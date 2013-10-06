#include "cutesong.h"
#include "ui_cutesong.h"
#include "song.h"
#include "playlist.h"
#include "newplaylistdialog.h"
#include "existingplaylistdialog.h"
#include "existingplaylistimportdialog.h"
#include "renameplaylistdialog.h"
#include "tageditiondialog.h"
#include "importexport.h"

#include <stdlib.h>
#include <time.h>
#include <phonon>
#include <QTime>
#include <QFileSystemModel>
#include <QDirModel>
#include <taglib/fileref.h>
#include <sstream>
#include <QMessageBox>



typedef QMap<QListWidgetItem*, std::string> playlistMap;

static const std::string Wiki("http://fr.wikipedia.org/wiki/");
static const std::string DefaultCover ("./Data/DefaultCover.jpg");
static const std::string StartupLogo ("./Data/qtLogo.jpg");
static const std::string REPEAT_Normal_Logo("./Data/repeatNormal.png");
static const std::string REPEAT_One_Logo("./Data/repeatOne.png");
static const std::string REPEAT_All_Logo("./Data/repeatAll.png");

static int to_skip = 1;




CuteSong::CuteSong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CuteSong)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);

    database.getDatabaseFromFile("QSQLITE","CuteSong.sqlite");

    // initialisation du 'lecteur media'
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);
    mediaObject->setTickInterval(1000);
    connect(mediaObject,SIGNAL(tick(qint64)),this,SLOT(tickOfMediaObject(qint64)));
    Phonon::createPath(mediaObject, audioOutput);

    // intialisation de l'afficheur LCD de progression du temps de la musique
    QTime displayTime(0,0);
    ui->lcdProgress->display(displayTime.toString("mm:ss"));

    // affichage du message de binvenue dans la statusBar (en bas)
    statusBar()->showMessage("Welcome to CuteSong !");

    // initialisation du volume
    ui->volumeSlider->setAudioOutput(audioOutput);
    ui->volumeSlider->setMuteVisible(true);
    audioOutput->setVolume(0);

    // genere la vue
    makeBddView();
    makePlaylistView();
    allowPlayControlManager(false);
    ui->coverLabel->setScaledContents(true);
    ui->playFilesButton->setEnabled(false);
    ui->rmButton->setEnabled(false);
    ui->actionExport_to_PLS->setEnabled(false);

    currentSong = new Song();


    // faire tous les connect
    connect (mediaObject,SIGNAL(finished()),this,SLOT(songFinished()));
    connect (ui->actionOuvrir_fichier,SIGNAL(triggered()),this,SLOT(addFile()));
    connect (ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));
    connect (ui->actionAjouter_dossier,SIGNAL(triggered()),this,SLOT(addDirToBdd()));
    connect (ui->actionAjouter_fichiers,SIGNAL(triggered()),this,SLOT(on_addButton_clicked()));
    connect (ui->actionSauver_playlist_courante,SIGNAL(triggered()),this,SLOT(popPlaylistDialog()));
    connect (ui->actionOpen_Directory,SIGNAL(triggered()),this,SLOT(addDirToPlaylist()));
    connect (ui->actionChange_cover,SIGNAL(triggered()),this,SLOT(on_button_changeCover_clicked()));
    connect (ui->actionMute,SIGNAL(triggered()),this,SLOT(muteManager()));
    connect (ui->actionNext,SIGNAL(triggered()),this,SLOT(next()));
    connect (ui->actionPause,SIGNAL(triggered()),this->mediaObject,SLOT(pause()));
    connect (ui->actionPlay,SIGNAL(triggered()),this->mediaObject,SLOT(play()));
    connect (ui->actionPrevious,SIGNAL(triggered()),this,SLOT(previous()));
    connect (ui->actionStop,SIGNAL(triggered()),this,SLOT(stopStateManager()));
    connect (ui->actionVolume_Down,SIGNAL(triggered()),this,SLOT(volumeDown()));
    connect (ui->actionVolume_up,SIGNAL(triggered()),this,SLOT(volumeUp()));
    connect (ui->actionEdit_song_s_tag,SIGNAL(triggered()),this,SLOT(editCurrentSongTag()));
    connect (ui->actionExport_to_PLS,SIGNAL(triggered()),this,SLOT(PLSExport()));
    connect (ui->actionImport_from_PLS,SIGNAL(triggered()),this,SLOT(PLSImport()));

}

/// @brief destructeur de la classe CuteSong
CuteSong::~CuteSong()
{    
    for (playlistMap::Iterator it = currentPlaylistItems.begin(); it != currentPlaylistItems.end(); ++it)
    {
        delete it.key();
    }

    database.closeBdd();
    delete ui;
}






/// @brief slot du bouton play/pause
void CuteSong::playPause()
{
    // récupération de l'etat actuel de lecture
    int etat = mediaObject->state();


    switch (etat)
    {
        case 0: //Phonon::LoadingState
            ui->playButton->setChecked(false);
            break;

        case 1: //Phonon::StoppedState
            mediaObject->play();
            ui->playButton->setIcon(QIcon("./Data/Pause.png"));
            ui->trackSlider->setMediaObject(mediaObject);
            break;

        case 2: //Phonon::PlayingState
            mediaObject->pause();
            ui->playButton->setIcon(QIcon("./Data/Play.png"));
            ui->playButton->setChecked(false);
            break;

        case 4: //Phonon::PausedState
            mediaObject->play();
            ui->playButton->setIcon(QIcon("./Data/Pause.png"));
            ui->trackSlider->setMediaObject(mediaObject);
            break;
    }
}





/// @brief permet l'ajout de fichier pour creer une playlist courante
void CuteSong::addFile()
{
    // ouverture d'une fenetre de selection
    QStringList files = QFileDialog::getOpenFileNames(this, "Select Music Files",
                    QDesktopServices::storageLocation(QDesktopServices::MusicLocation),"*.mp3 *.m4a *.wma *.flac");

    if (files.isEmpty())
        return;

    // ajout de chaque fichier a la suite de la liste de lecture
    ui->statusBar->showMessage("Processing ...");
   foreach (QString string, files)
           addToCurrentPlaylist(string.toStdString().c_str());

   ui->statusBar->showMessage("Files added to current playlist");
   mediaObject->stop();
   setCurrentSong(files.first().toStdString().c_str());

   ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
   ui->playlist->setCurrentRow(ui->playlist->row(currentPlaylistItems.key(files.first().toStdString())), QItemSelectionModel::Select);
   if (TagLib::MPEG::File(currentSong->getPath().c_str()).isValid())
       ui->actionEdit_song_s_tag->setEnabled(true);
   mediaObject->play();
}






/// @brief ajoute le chansons passee en parmaetre a la playlist courante
void CuteSong::addToCurrentPlaylist (const char *path)
{
    if (!ui->playButton->isEnabled())
    {
        allowPlayControlManager(true);
    }
    QListWidgetItem *item = new QListWidgetItem(QString(Song::getFilenameFromPath(path).c_str()));
    currentPlaylistItems.insert(item,path);
    ui->playlist->addItem(item);
    std::cout << "new Song added to current playlist" << std::endl;
}






/// @brief slot du bouton suivant
void CuteSong::next()
{
    //if (mediaObject->state()!=Phonon::StoppedState)
    //{
        // gestion de l'aleatoire
        if (ui->randomCheckBox->isChecked())
            to_skip = generateRandomSkip();
        else
            to_skip = 1;

        mediaObject->stop();

        playlistMap::Iterator it;

         if (ui->playlist->currentRow()+1 != ui->playlist->count() || ui->randomCheckBox->isChecked())
         {
            it = currentPlaylistItems.find(ui->playlist->item(ui->playlist->currentRow()+to_skip));
            // Deplace l'indicateur de selection sur la chanson suivante
            ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
            ui->playlist->setCurrentRow(ui->playlist->currentRow()+to_skip, QItemSelectionModel::Select);

            setCurrentSong(it.value().c_str());

            mediaObject->play();
         }
         else
             if (ui->repeatChoice->currentText() == "Repeat All")
             {
                 it = currentPlaylistItems.find(ui->playlist->item(0));
                 // Deplace l'indicateur de selection sur la chanson suivante
                 ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
                 ui->playlist->setCurrentRow(0, QItemSelectionModel::Select);

                 setCurrentSong(it.value().c_str());

                 mediaObject->play();
             }
             else
             {
                 delete currentSong;
                 currentSong = new Song();

                 mediaObject->clear();
                 ui->coverLabel->clear();
                 ui->labelAlbum->clear();
                 ui->labelArtist->clear();
                 ui->labelTitle->clear();
                 ui->statusBar->clearMessage();
             }
   // }
}





/// @brief slot du bouton précédent
void CuteSong::previous()
{
    //if (mediaObject->state()!=Phonon::StoppedState)
    //{
        if (ui->randomCheckBox->isChecked())
            to_skip = generateRandomSkip();
        else
            to_skip = -1;

        playlistMap::Iterator it;

        mediaObject->stop();
        if (ui->playlist->currentRow() == 0 && !ui->randomCheckBox->isChecked())
            it = currentPlaylistItems.find(ui->playlist->currentItem());
            //it = currentPlaylistItems.find(ui->playlist->item(ui->playlist->currentRow()));
        else
        {
            it = currentPlaylistItems.find(ui->playlist->item(ui->playlist->currentRow()-(-to_skip)));
            // Deplace l'indicateur de selection sur la chanson precedente
            ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
            ui->playlist->setCurrentRow(ui->playlist->currentRow()-(-to_skip), QItemSelectionModel::Select);
        }

        setCurrentSong(it.value().c_str());

        mediaObject->play();
    //}
}






/// @brief MAJ du temps de la musique fait a chque signal 'tick'
void CuteSong :: tickOfMediaObject(qint64 time)
{
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdProgress->display(displayTime.toString("mm:ss"));
}






/// @brief Fonction mettant a jour l'affichage des tags récupérer via TagLib
void CuteSong :: updateDataSong ()
{
    std::cout << "Updating data..." << std::endl;
    ui->labelAlbum->setText(currentSong->getAlbum().c_str());
    ui->labelArtist->setText(currentSong->getArtist().c_str());
    ui->labelTitle->setText(currentSong->getTitle().c_str());
    statusBar()->showMessage(currentSong->getFilename().c_str());
    std::string url = Wiki+currentSong->getArtist();
    ui->wikiView->load(QUrl(QString(url.c_str())));

    // recuperation par ImageForFile et affichage
    QImage *cover=currentSong->imageForFile(currentSong->getPath().c_str());

    // si aucune cover ==> cover par default
    if (cover == NULL) cover = new QImage(DefaultCover.c_str());

    // remise a l'echelle de l'image
    ui->coverLabel->setPixmap(QPixmap::fromImage(*cover));

    std::cout << "data updated" << std::endl;
}






/// @brief slot du bouton Add files de l'onglet bibliotheque
void CuteSong::on_addButton_clicked()
{
    Song *song;

    // Ouvre une fenetre de selection de fichier
    QStringList files = QFileDialog::getOpenFileNames(this, "Select Music Files",
                QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    if (files.isEmpty())
        return;
    ui->statusBar->showMessage("Processing ...");
    // traitement de chaques fichiers selectionnés
    foreach (QString path, files) {
        song = new Song(path.toStdString().c_str());
        insertSongInDB(song);
        delete(song);
    }

    statusBar()->showMessage("Songs added to your music");
}



void CuteSong::on_button_changeCover_clicked()
{
    if (ui->playlist->count() != 0)
    {
        QString file = QFileDialog::getOpenFileName(this, "Select Image File",
                    QDesktopServices::storageLocation(QDesktopServices::PicturesLocation));

        if (file.isEmpty())
            return;

        ImageFile imageFile(file.toStdString().c_str());

        TagLib::ByteVector imageData = imageFile.data();

        currentSong->changeCover(currentSong->getPath().c_str(),imageData);
        updateDataSong();


        statusBar()->showMessage("Cover succesfuly changed");
    }
}



/// @brief Ajouter une chansons a la bdd
void CuteSong :: insertSongInDB (Song *song)
{
    std::ostringstream oss;

    oss << "\"" << song->getPath() << "\",";
    oss << "\"" << song->getFilename() << "\",";
    oss << "\"" << song->getArtist() << "\",";
    oss << "\"" << song->getAlbum() << "\",";
    oss << "\"" << song->getTitle() << "\"";

    database.insertBdd("tmusic",oss.str());
    makeBddView();
}








/// @brief Remplir bddView avec la base de données des musiques.
void CuteSong::makeBddView()
{
    QSqlTableModel *model = new QSqlTableModel(0,database.getBdd());
    model->setTable("tmusic");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->bddView->setModel(model);

    ui->bddView->setColumnHidden(0,true);
    ui->bddView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->bddView->verticalHeader()->hide();
    ui->bddView->setSelectionBehavior(QAbstractItemView::SelectRows);
}





/// @brief Remplir playlistView avec la liste des playlists
void CuteSong :: makePlaylistView ()
{
    QSqlTableModel *model = new QSqlTableModel(0,database.getBdd());
    model->setTable("tplaylist");
    model->select();


    ui->playlist->setMovement(QListView::Static);
    ui->playlist->setViewMode(QListView::ListMode);

    ui->tablePlaylists->setModel(model);
    ui->tablePlaylists->setColumnHidden(1,true);
    ui->tablePlaylists->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablePlaylists->verticalHeader()->hide();
    ui->tablePlaylists->horizontalHeader()->hide();
    ui->tablePlaylists->setEditTriggers(QAbstractItemView::NoEditTriggers);
}





/// @brief genere la vu du contenu de la playlist selectionnee
void CuteSong :: makePlaylistContentView (std::string playlist)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    std::ostringstream oss;

    oss << "playlist_name=\"" << playlist << "\"";
    model->setQuery(database.selectQuery("path","tplaylist_music",oss.str()));

    ui->tablePlaylistContent->setModel(model);
    ui->tablePlaylistContent->show();
    ui->tablePlaylistContent->resizeRowsToContents();
    //ui->tablePlaylistContent->resizeColumnsToContents();
}




void CuteSong::on_playPlaylistButton_toggled()
{
    QAbstractItemModel *model = ui->tablePlaylistContent->model();
    int nbRow = model->rowCount(), count;

    for (count = 0; count != nbRow; count++)
    {
        QModelIndex index = model->index(count,0);
        std::cout << "Path to add : " <<index.data().toString().toStdString() << std::endl;
        addToCurrentPlaylist(index.data().toString().toStdString().c_str());
    }
}





/// @brief Retirer de la Bdd les entrées selectionnées dans bddView
void CuteSong :: on_rmButton_toggled ()
{
    ui->statusBar->showMessage("Processing ...");
    int i=1;
    QAbstractItemModel * model = ui->bddView->model();
    QItemSelectionModel * selection = ui->bddView->selectionModel();
    QModelIndexList indexes = selection->selectedIndexes();

    ui->actionExport_to_PLS->setEnabled(false);

    foreach (QModelIndex index, indexes)
    {
        if (i == 1)
        {
            std::string where ("path=\"");
            QString text = model->data(index).toString();
            std::cout << text.toStdString() << std::endl;
            where += text.toStdString();
            where += "\"";
            database.deleteQuery("tmusic",where);
        }

        if (i== 5) i=0;
        i++;
    }

    makeBddView();
    ui->playFilesButton->setEnabled(false);
    ui->rmButton->setEnabled(false);
    ui->statusBar->showMessage("Songs removed");
}






/// @brief Afficher le resultat de la recherche
void CuteSong :: on_searchButton_toggled()
{
    QString searchBy = ui->searchBy->currentText();
    std::string searched = ui->searched->text().toStdString();
    std::ostringstream oss;

    // si aucune valeur de recherche alors faire un SELECT *
    if (searched.empty())
        searched = "*";

    else
        oss << "lower(" << searchBy.toStdString() << ")" << " LIKE lower(\"%" << searched <<"%\")";


    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(database.selectQuery("*","tmusic",oss.str()));

    ui->bddView->setModel(model);
    ui->bddView->show();
}





/// @brief retirer de la playlis courrante la chansons selectionnée
void CuteSong :: on_rmFromPlaylist_clicked()
{

    mediaObject->stop();

    QListWidgetItem* currentItem = ui->playlist->takeItem(ui->playlist->currentRow());
    currentPlaylistItems.erase(currentPlaylistItems.find(currentItem));

    playlistMap::Iterator it;

    if (ui->playlist->count() != 0)
    {
        it = currentPlaylistItems.find(ui->playlist->item(ui->playlist->currentRow()));
        ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Select);

        setCurrentSong(it.value().c_str());

        mediaObject->play();
    }

    else
     {
        ui->labelAlbum->clear();
        ui->labelArtist->clear();
        ui->labelTitle->clear();
        ui->coverLabel->setPixmap(QPixmap());
        statusBar()->showMessage("No song to play");
        std::string url = " ";
        ui->wikiView->load(QUrl(QString(url.c_str())));
        allowPlayControlManager(false);
     }

}



/// @brief ajouter un dossier complet a la base de donnee
void CuteSong::addDirToBdd()
{
    Song *song;

    // Ouvre une fenetre de selection de fichier
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                  "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);


    ui->statusBar->showMessage("Processing ...");
    QDir directory(dir);

    QStringList filters;
    filters << "*.mp3" << "*.wma" << "*.m4a" << "*.flac";

    QStringList files =directory.entryList(filters,QDir::Files);


    // traitement de chaques fichiers selectionnés
    foreach (QString path, files) {
        path = directory.absoluteFilePath(path);
        std::cout << "path:" << path.toStdString() << std::endl;
        song = new Song(path.toStdString().c_str());
        insertSongInDB(song);
        delete(song);

    }
    statusBar()->showMessage("Songs added to your music");
}





/// @brief afficher le contenu de la playlist selectionne
/// @bug le scrollbarne marche pas
void CuteSong::on_tablePlaylists_clicked(const QModelIndex &index)
{
    delete ui->tablePlaylistContent->model();
    std::string name_playlist = index.data().toString().toStdString();
    makePlaylistContentView(name_playlist);
    ui->actionExport_to_PLS->setEnabled(true);

}






/// @brief ajouter a la playlist courante la chanson double cliquée dans la playlist
void CuteSong::on_tablePlaylistContent_doubleClicked(const QModelIndex &index)
{
    std::cout << "double click in playlist content" << std::endl;
    std::string data = index.data().toString().toStdString();
    addToCurrentPlaylist(data.c_str());
    setCurrentSong(data.c_str());
    ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
    ui->playlist->setCurrentRow(ui->playlist->row(currentPlaylistItems.key(data)), QItemSelectionModel::Select);
    ui->playButton->setIcon(QIcon("./Data/Pause.png"));
    mediaObject->play();
}







/// @brief exporter la playlist courante dans la bdd
void CuteSong::exportCurrentPlaylist(QString name)
{
    std::cout << "Enregistrement playlist" << std::endl;
    std::string where ("name=\"");
    where += name.toStdString();
    where += "\"";

    QSqlQuery result = database.selectQuery("*","tplaylist",where);
    result.first();
    if (result.isValid())
    {
        std::cout << "valid : let's pop it" << std::endl;
        ExistingPlaylistDialog *dialog = new ExistingPlaylistDialog(name.toStdString(),this);
        dialog->show();
    }
    else
    {
        std::cout << "invalid choose name" << std::endl;
        exportPlaylistProcess(name);
    }

}

void CuteSong::exportPlaylistProcess(QString name)
{
    Playlist to_export(currentPlaylistItems,name.toStdString());
    to_export.addToDb(database);
    makePlaylistView();
    statusBar()->showMessage("Playlist sauvegardée dans la base de donnée !");
}


void CuteSong::deletePlaylist(QString name)
{
    std::cout << "delete playlist" << std::endl;
    Playlist::deleteFromDb(database,name.toStdString(),"tplaylist","tplaylist_music");
    exportPlaylistProcess(name);
}



void CuteSong::deletePlaylistImport(QList<QString> pls, QString name)
{
    std::cout << "delete playlist" << std::endl;
    Playlist::deleteFromDb(database,name.toStdString(),"tplaylist","tplaylist_music");
    importPlaylistPls(pls,name);
}





/// @brief lire les musique selectionnees dans la bibliotheque
void CuteSong::on_playFilesButton_toggled()
{
    int i=0;
    QAbstractItemModel * model = ui->bddView->model();
    QItemSelectionModel * selection = ui->bddView->selectionModel();
    QModelIndexList indexes = selection->selectedIndexes();

    if (indexes.count() > 5 )
    {
        foreach (QModelIndex index, indexes)
        {
            if (i < indexes.count()/5)
            {
                QString text = model->data(index).toString();

                std::cout << "DEBUG :: play files button :" << text.toStdString() << std::endl;
                addToCurrentPlaylist(text.toStdString().c_str());
            }
            i++;
        }
    }

    else
    {
        std::cout << "only one song to add" << std::endl;
        std::string text(indexes.first().data(0).toString().toStdString());
        addToCurrentPlaylist(text.c_str());
        std::cout << "DEBUG :: play files button :" << text.c_str()<< std::endl;

    }

    ui->statusBar->showMessage("Files added to current playlist");

    mediaObject->stop();

    setCurrentSong(indexes.first().data(0).toString().toStdString().c_str());

    ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
    ui->playlist->setCurrentRow(ui->playlist->row(currentPlaylistItems.key(indexes.first().data(0).toString().toStdString())), QItemSelectionModel::Select);
    ui->playButton->setIcon(QIcon("./Data/Pause.png"));
    ui->playFilesButton->setEnabled(false);
    ui->rmButton->setEnabled(false);
    mediaObject->play();
    ui->bddView->clearSelection();
    if (TagLib::MPEG::File(currentSong->getPath().c_str()).isValid())
        ui->actionEdit_song_s_tag->setEnabled(true);
}





/// @brief definir la chanson passer en parametre comme chanson actuelle.
void CuteSong::setCurrentSong(const char *path)
{
    Song *song = new Song(path);
    delete currentSong;
    currentSong = song;

    // Prepare la lecture du nouveau fichier
    mediaObject->setCurrentSource(Phonon::MediaSource(path));
    updateDataSong();

    // Relance la lecture
    ui->trackSlider->setMediaObject(mediaObject);
}





void CuteSong ::popPlaylistDialog (void)
{
    newPlaylistDialog *playlistDialog = new newPlaylistDialog(this);

    playlistDialog->show();
}




int CuteSong::generateRandomSkip()
{
    int row;
    do
    {
        srand(time(NULL));
        row=(rand()%ui->playlist->count())-ui->playlist->currentRow();
    }while (row == ui->playlist->currentRow());
    return row;
}




void CuteSong::songFinished()
{
    if (ui->repeatChoice->currentText() == "Repeat One")
    {
        mediaObject->stop();

        playlistMap::Iterator it;

        it = currentPlaylistItems.find(ui->playlist->currentItem());
        setCurrentSong(it.value().c_str());

        mediaObject->play();
    }
    else
        next();
}







/// @brief supprimer une playlist et son contenu
void CuteSong::on_rmPlaylistButton_toggled()
{
    std::cout << "DELETE PLAYLIST" << std::endl;
    ui->statusBar->showMessage("Processing ...");

    QString playlist_name = ui->tablePlaylists->currentIndex().data().toString();
    /*QList <std::string> path_list;

    std::string where ("playlist_name =\"");
    where += playlist_name;
    where += "\"";

    QSqlQuery query = database.selectQuery("path","tplaylist_music",where);

    while (query.next())
        path_list.append(query.value(0).toString().toStdString());

    foreach (std::string path, path_list)
    {
        where = "path=\"";
        where += path;
        where += "\"";

        database.deleteQuery("tplaylist_music",where);
    }

    where = "name=\"";
    where += playlist_name;
    where += "\"";
    database.deleteQuery("tplaylist",where);
    */
    deletePlaylist(playlist_name);

    makePlaylistView();

    ui->statusBar->showMessage("Playlist deleted");
    makePlaylistContentView(" ");
}





void CuteSong::on_playlist_doubleClicked(const QModelIndex &index)
{
    mediaObject->stop();

    playlistMap::Iterator it;

    it = currentPlaylistItems.find(ui->playlist->currentItem());

    setCurrentSong(it.value().c_str());
    if (TagLib::MPEG::File(currentSong->getPath().c_str()).isValid())
        ui->actionEdit_song_s_tag->setEnabled(true);
    mediaObject->play();
}




/// @brief slot qui permet de modifier le logo associé
void CuteSong::on_repeatChoice_currentIndexChanged(int index)
{
    std::cout << "CHANGED " << index << std::endl;

    switch (index)
    {
        case 0:
        {
           QImage logo = QImage(REPEAT_Normal_Logo.c_str());
           ui->repeatLabel->setPixmap(QPixmap::fromImage(logo));
           break;
        }
        case 1:
         {
           QImage logo = QImage(REPEAT_One_Logo.c_str());
           ui->repeatLabel->setPixmap(QPixmap::fromImage(logo));
           break;
         }
        case 2:
        {
           QImage logo = QImage(REPEAT_All_Logo.c_str());
           ui->repeatLabel->setPixmap(QPixmap::fromImage(logo));
           break;
        }
    }
}



/*
 *  else
    {
        QMessageBox msgBox;
        std::string msg("Incorrect path... Check the file existance !\nPath : ");
        msg +="\"";
        msg += path;
        msg += "\"\n";
        msgBox.setText(msg.c_str());
        msgBox.exec();
        return NULL;
    }
    */



void CuteSong::addDirToPlaylist()
{
    // Ouvre une fenetre de selection de fichier
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                  "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);


    ui->statusBar->showMessage("Processing ...");
    QDir directory(dir);

    QStringList filters;
    filters << "*.mp3" << "*.wma" << "*.m4a" << "*.flac";

    QStringList files =directory.entryList(filters,QDir::Files);


    // traitement de chaques fichiers selectionnés
    foreach (QString path, files) {
        path = directory.absoluteFilePath(path);
        std::cout << "path:" << path.toStdString() << std::endl;
        addToCurrentPlaylist(path.toStdString().c_str());
    }
    statusBar()->showMessage("Songs added to current playlist");
}





void CuteSong::muteManager()
{
    if (audioOutput->isMuted())
        audioOutput->setMuted(false);
    else
        audioOutput->setMuted(true);
}






void CuteSong::stopStateManager()
{
    this->mediaObject->stop();
    ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
    delete currentSong;
    currentSong = new Song();
    allowPlayControlManager(false);
    mediaObject->clear();
    ui->coverLabel->clear();
    ui->labelAlbum->clear();
    ui->labelArtist->clear();
    ui->labelTitle->clear();
    ui->statusBar->showMessage("Stopped !");
}





void CuteSong::volumeDown()
{
    audioOutput->setVolumeDecibel(audioOutput->volumeDecibel()-2);
}





void CuteSong::volumeUp()
{
    audioOutput->setVolumeDecibel(audioOutput->volumeDecibel()+2);
}





void CuteSong::on_renamePlaylistButton_clicked()
{
    QDialog *pop_up = new RenamePlaylistDialog(this);

    pop_up->show();
}




void CuteSong::renamePlaylistProcess(std::string name)
{
    Playlist::renameInDb(database,ui->tablePlaylists->currentIndex().data().toString().toStdString(),name,"tplaylist","tplaylist_music");
    makePlaylistContentView(name);
    makePlaylistView();
}




void CuteSong::on_bddView_clicked(const QModelIndex &index)
{
    ui->playFilesButton->setEnabled(true);
    ui->rmButton->setEnabled(true);
}



void CuteSong::allowPlayControlManager (bool wanted_state)
{
    ui->playButton->setEnabled(wanted_state);
    ui->nextButton->setEnabled(wanted_state);
    ui->previousButton->setEnabled(wanted_state);
    ui->actionChange_cover->setEnabled(wanted_state);
    ui->actionNext->setEnabled(wanted_state);
    ui->actionPause->setEnabled(wanted_state);
    ui->actionPlay->setEnabled(wanted_state);
    ui->actionPrevious->setEnabled(wanted_state);
    ui->actionStop->setEnabled(wanted_state);
    if (wanted_state == false)
        ui->actionEdit_song_s_tag->setEnabled(wanted_state);
}


void CuteSong::editCurrentSongTagProcess (std::string path, QString artist, QString album, QString title)
{
    TagLib::MPEG::File ref(path.c_str());
    if (ref.isValid())
    {
        ref.tag()->setAlbum(album.toStdString());
        ref.tag()->setArtist(artist.toStdString());
        ref.tag()->setTitle(title.toStdString());
        ref.save();
        currentSong->updateTag();
        updateDataSong();
    }

    std::string where("path=\"");
    where += currentSong->getPath();
    where += "\"";
    database.updateBdd("tmusic","album",currentSong->getAlbum(),where);
    database.updateBdd("tmusic","artist",currentSong->getArtist(),where);
    database.updateBdd("tmusic","title",currentSong->getTitle(),where);
    makeBddView();
}




void CuteSong::editCurrentSongTag()
{
    TagEditionDialog *dialog = new TagEditionDialog(currentSong->getPath(), this);
    dialog->show();
}





void CuteSong::PLSImport ()
{
    QString file = QFileDialog::getOpenFileName(this, "Select .pls file",
            QDesktopServices::storageLocation(QDesktopServices::MusicLocation),"*.pls");

    if (file.isEmpty())
            return;

    std::string pls=file.toStdString().c_str();

    ImportExport fromPls;
    QList<QString> playlist=fromPls.importerPLS(pls);
    std::string name=fromPls.getNameFromPath(pls.c_str());
    //importPlaylistPls(playlist,name);
    ExistingPlaylistImportDialog *dialog = new ExistingPlaylistImportDialog(playlist,name,this);
    dialog->show();
}



void CuteSong::PLSExport ()
{
   ImportExport pls;
   QList<QString> itemDataList;
   std::string playlist_name = ui->tablePlaylists->currentIndex().data().toString().toStdString();

   std::string where("playlist_name=\"");
   where += playlist_name;
   where += "\"";

   QSqlQuery result = database.selectQuery("path","tplaylist_music",where);

   while (result.next())
       itemDataList.append(result.value(0).toString());


   Playlist to_export(itemDataList,playlist_name);
   pls.exporterPLS(&to_export, playlist_name);
   ui->actionExport_to_PLS->setEnabled(false);

   statusBar()->showMessage("Playlist succesfuly exported");
}





void CuteSong::importPlaylistPls(QList<QString> pls, QString name)
{
    std::cout << "importProcess " << pls.length() << std::endl;
    Playlist to_export(pls,name.toStdString());
    to_export.addToDb(database);
    makePlaylistView();
    ui->actionExport_to_PLS->setEnabled(false);
    statusBar()->showMessage("Playlist succesfuly imported");
}





void CuteSong::on_moveDownButton_clicked()
{
    ui->playlist->insertItem(ui->playlist->currentRow()+1,ui->playlist->takeItem(ui->playlist->currentRow()));

    ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
    ui->playlist->setCurrentRow(ui->playlist->currentRow()+1, QItemSelectionModel::Select);

}




void CuteSong::on_moveUpButton_clicked()
{
    ui->playlist->insertItem(ui->playlist->currentRow()-1,ui->playlist->takeItem(ui->playlist->currentRow()));

    ui->playlist->setCurrentRow(ui->playlist->currentRow(), QItemSelectionModel::Clear);
    ui->playlist->setCurrentRow(ui->playlist->currentRow()-1, QItemSelectionModel::Select);
}
