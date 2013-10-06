#ifndef CUTESONG_H
#define CUTESONG_H

#include <QMainWindow>
#include <QObject>
#include <phonon>
#include <QList>
#include <QMap>
#include <QFileDialog>
#include <QDesktopServices>
#include <QListWidgetItem>

#include "classSQL.h"
#include "song.h"

typedef QMap<QListWidgetItem*, std::string> playlistMap;

namespace Ui {
class CuteSong;
}

class CuteSong : public QMainWindow
{
    Q_OBJECT
    
public:

    /**
     * @brief CuteSong
     *
     *
     *      Constructeur de la class CuteSong
     *
     *
     * @param parent
     */
    explicit CuteSong(QWidget *parent = 0);


    /**
     * @brief insertSongInDB
     *
     *
     *      Fonction permettant d'ajouter une chanson a la bdd a partir de la map contenant
     *      ses infos
     *
     *
     * @param dataSong : Une map ayant pour clef le nom du champs (artist, album etc..) et sa valeur
     *                  contenant les informations sur la chanson
     */
    void insertSongInDB (Song *song);


    /**
     * @brief makeBddView
     *
     *
     *      Fonction initialisant la QTableView pour qu'elle affiche les chansons
     *      de la bdd
     *
     *
     */
    void makeBddView ();


    /**
     * @brief ~CuteSong
     *
     *
     *      Destructeur de la classe CuteSong
     *
     *
     */
    ~CuteSong();


    /**
     * @brief makePlaylistView
     *
     *
     *      Fonction qui genere la vue des playlist a partir de la bdd
     *
     *
     *
     */
    void makePlaylistView ();

private:

    /**
     * @brief ui
     */
    Ui::CuteSong *ui;


    /**
     * @brief audioOutput
     */
    Phonon::AudioOutput *audioOutput;


    /**
     * @brief mediaObject
     */
    Phonon::MediaObject *mediaObject;


    /**
     * @brief metaInformationResolver
     */
    Phonon::MediaObject *metaInformationResolver;


    /**
     * @brief database
     *
     *      base de données du lecteur
     *
     *
     */
    Bdd database;


    Song *currentSong;


    /**
     * @brief currentPlaylistItems
     *
     *
     *      Map des musiques des la playlist en cours
     *      cle : Song correspondant
     *      valeur : QListWidgetItem correspondant dans la QListWidget playlist
     */
    playlistMap currentPlaylistItems;


private slots :
    /**
     * @brief playPause
     *
     *      Slot correspondant au bouton Play/Pause
     *      Change l'etat de la lecture de Pause a Play ou de Play a Pause
     *
     *
     */
    void playPause();


    /**
     * @brief addFile
     *
     *
     *      !!!   FONCTION TEMPORAIRE   !!!
     *
     *      Slot correspondant au bouton Add files du lecteur
     *      Ouvre un QFileDialog et creer la liste des musiques a lire.
     */
    void addFile();


    /**
     * @brief next
     *
     *
     *      Slot correspondant au bouton Next >>
     *      Permet de passer a la musique suivante dans la playlist
     *
     *
     */
    void next();


    /**
     * @brief previous
     *
     *
     *      Slot correspondant au bouton Previous <<
     *      Permet derevenir a la musique précédente dans la playlist
     *
     *
     */
    void previous();


    /**
     * @brief tickOfMediaObject
     *
     *
     *      Slot lié au signal 'tick' du mediaplayer
     *      Permet de calculer et d'afficher le temps de lecture
     *
     *
     */
    void tickOfMediaObject(qint64);


    /**
     * @brief on_addButton_clicked
     *
     *
     *      Slot correspondant au bouton Add Files de l'onglet Bibliotheque
     *      Ouvre un QFileDialog et ajoute les chansons selectionnées a la bdd
     *
     *
     */
    void on_addButton_clicked();


    /**
     * @brief on_rmButton_toggled
     *
     *
     *      Slot correspondant au bouton Remove selected file
     *      Supprime les chansons sélectionnées de la bdd
     *
     *
     */
    void on_rmButton_toggled ();


    /**
     * @brief updateDataSong
     *
     *
     *      Fonction permettant de mettre a jour les tags et de les afficher
     *
     *
     * @param song : string contenant le chemin de la chanson a traiter
     */
    void updateDataSong ();



    /**
     * @brief on_searchButton_toggled
     *
     *
     *      Slot associé au bouton de recherche
     *
     *      Fonction qui effectue la recherche avec les criteres demandes
     *      et met a jour l'affichage de la bibliotheque en conséquence.
     *
     *      Remise a zero avec recherche vide.
     */
    void on_searchButton_toggled();



    /**
     * @brief addToCurrentPlaylist
     *
     *
     *      Fonction permettant d'ajouter une chanson a la playlist courrante
     *
     *
     *
     * @param path : chaine de caracteres contenant le chemin vers la chanson a ajouter
     */
    void addToCurrentPlaylist (const char *path);


    /**
     * @brief on_rmFromPlaylist_clicked
     *
     *
     *      Slot associe au bouton de suppression de musique de la playlist courrante
     *
     *      Fonction qui retire l'element de la playlist et passe a l'élément suivant.
     *
     */
    void on_rmFromPlaylist_clicked();



    /**
     * @brief addDirToBdd
     *
     *
     *      Slot associé a au menu d'ajout de dossier a la bibliotheque.
     *
     *      Fonction d'ajout d'un dossier complet a la bibliotheque.
     *
     *
     */
    void addDirToBdd ();




    /**
     * @brief on_tablePlaylists_clicked
     *
     *
     *      Slot associé au clic sur une playlist
     *
     *      Fonction qui genere la vue du contenu de la playlist
     *
     *
     * @param index : QModelIndex contenant l'index selectionne
     */
    void on_tablePlaylists_clicked(const QModelIndex &index);



    /**
     * @brief on_tablePlaylistContent_doubleClicked
     *
     *
     *      Slot associé au double clic sur une element de la playlist.
     *
     *      Fonction qui lance la musique double cliquee
     *
     *
     * @param index : QModelIndex contenant l'index selectionne
     */
    void on_tablePlaylistContent_doubleClicked(const QModelIndex &index);


    /**
     * @brief makePlaylistContentView
     *
     *
     *      Fonction qui genere la vue associee a la playlist
     *      selectionnee
     *
     *
     * @param playlist : string contenant le nom de la playlist selectionnee
     */
    void makePlaylistContentView (std::string playlist);


    /**
     * @brief on_playlist_doubleClicked
     *
     *
     *      Slot asociee au bouton Play de l'onglet playlist
     *
     *      Fonction qui ajoute les elements de la playlist selectionnee
     *      a la list de lecture courante
     *
     *
     */
    void on_playPlaylistButton_toggled();


    /**
     * @brief on_rmPlaylistButton_toggled
     *
     *
     *      Slot associe au bouton "remove playlist" de l'onglet playlist
     *
     *      Fonction qui supprime une playlist de la base de donnee et re-genere la vue
     *
     *
     */
    void on_rmPlaylistButton_toggled(void);



    /**
     * @brief on_playFilesButton_toggled
     *
     *
     *      Slot associe au bouton "play files" de l'onglet bibiliotheque
     *
     *      Fonction qui ajoute les chansons selectionnees a la liste de
     *      lecture courrante
     *
     *
     */
    void on_playFilesButton_toggled(void);



    /**
     * @brief setCurrentSong
     *
     *
     *      Fonction qui definie la chanson passer en parametre comme
     *      la chanson courrante
     *
     *
     * @param path: string contenant le chemin de la chanson
     */
    void setCurrentSong(const char *path);

    void popPlaylistDialog (void);

    int generateRandomSkip();

    void songFinished ();

    void on_playlist_doubleClicked(const QModelIndex &index);

    void on_repeatChoice_currentIndexChanged(int index);

    void on_button_changeCover_clicked();

    void addDirToPlaylist (void);

    void muteManager (void);

    void stopStateManager (void);

    void volumeDown (void);

    void volumeUp (void);

    void on_renamePlaylistButton_clicked();

    void on_bddView_clicked(const QModelIndex &index);

    void on_moveDownButton_clicked();

    void on_moveUpButton_clicked();

protected slots:

    /**
     * @brief exportCurrentPlaylist
     *
     *
     *      Slot associe a la validation du nom d'enregistrement
     *      de la playlist
     *
     *      Fonction permettant de sauvegarder la playlist courrante
     *      avec le nom passe en parametre
     *
     *
     * @param name : QString contenant le nom de la playlist
     */
    void exportCurrentPlaylist (QString name);

    void exportPlaylistProcess (QString name);

    void deletePlaylist(QString name);

    void renamePlaylistProcess(std::string name);

    void allowPlayControlManager (bool wanted_state);

    void editCurrentSongTagProcess (std::string path, QString artist, QString album, QString title);

    void editCurrentSongTag();

    void PLSImport ();

    void PLSExport ();

    void importPlaylistPls(QList<QString> pls, QString name);

    void deletePlaylistImport (QList<QString> pls, QString name);

};


class ImageFile : public TagLib::File
{
public:
    ImageFile(const char *file) : TagLib::File(file){}

    TagLib::ByteVector data()
    {
        return readBlock(length());
    }


private:

    virtual TagLib::Tag *tag() const { return 0; }

    virtual TagLib::AudioProperties *audioProperties() const { return 0; }

    virtual bool save() { return false; }

};


#endif // CUTESONG_H
