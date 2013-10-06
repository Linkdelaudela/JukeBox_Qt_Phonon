/********************************************************************************
** Form generated from reading UI file 'cutesong.ui'
**
** Created: Sat Jan 12 20:25:45 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTESONG_H
#define UI_CUTESONG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_CuteSong
{
public:
    QAction *actionQuitter;
    QAction *actionOuvrir_fichier;
    QAction *actionQuit;
    QAction *actionAjouter_dossier;
    QAction *actionAjouter_fichiers;
    QAction *actionAjouter_dossier_2;
    QAction *actionAjouter_Fichier;
    QAction *actionSauver_playlist_courante;
    QAction *actionOpen_Directory;
    QAction *actionChange_cover;
    QAction *actionSelect_a_playlist;
    QAction *actionSelect_a_song;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionNext;
    QAction *actionPrevious;
    QAction *actionMute;
    QAction *actionVolume_up;
    QAction *actionVolume_Down;
    QAction *actionEdit_song_s_tag;
    QAction *actionExport_to_PLS;
    QAction *actionImport_from_PLS;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    Phonon::SeekSlider *trackSlider;
    QLCDNumber *lcdProgress;
    QHBoxLayout *horizontalLayout;
    QPushButton *addFileButton;
    QPushButton *previousButton;
    QPushButton *playButton;
    QPushButton *nextButton;
    QCheckBox *randomCheckBox;
    QComboBox *repeatChoice;
    QLabel *repeatLabel;
    QSpacerItem *horizontalSpacer;
    Phonon::VolumeSlider *volumeSlider;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *homeTab;
    QGridLayout *gridLayout_3;
    QLabel *labelAlbum;
    QLabel *coverLabel;
    QLabel *labelTitle;
    QLabel *label;
    QListWidget *playlist;
    QLabel *label_2;
    QLabel *labelArtist;
    QLabel *label_3;
    QPushButton *rmPlaylistButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *moveUpButton;
    QPushButton *moveDownButton;
    QWidget *bibliothequeTab;
    QGridLayout *gridLayout_4;
    QTableView *bddView;
    QPushButton *addButton;
    QPushButton *rmButton;
    QPushButton *searchButton;
    QLabel *label_4;
    QComboBox *searchBy;
    QPushButton *playFilesButton;
    QLineEdit *searched;
    QWidget *tabPlaylist;
    QGridLayout *gridLayout_2;
    QPushButton *playPlaylistButton;
    QTableView *tablePlaylistContent;
    QPushButton *rmPlaylistButton_2;
    QTableView *tablePlaylists;
    QPushButton *renamePlaylistButton;
    QWidget *wikiTab;
    QGridLayout *gridLayout_7;
    QWebView *wikiView;
    QMenuBar *menuBar;
    QMenu *menuPlaylist;
    QMenu *menuBibliotheque;
    QMenu *menuFichier;
    QMenu *menuLecture;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CuteSong)
    {
        if (CuteSong->objectName().isEmpty())
            CuteSong->setObjectName(QString::fromUtf8("CuteSong"));
        CuteSong->resize(801, 615);
        CuteSong->setStyleSheet(QString::fromUtf8(""));
        actionQuitter = new QAction(CuteSong);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionOuvrir_fichier = new QAction(CuteSong);
        actionOuvrir_fichier->setObjectName(QString::fromUtf8("actionOuvrir_fichier"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Data/File.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrir_fichier->setIcon(icon);
        actionOuvrir_fichier->setIconVisibleInMenu(true);
        actionQuit = new QAction(CuteSong);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Data/Blocked.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionQuit->setIconVisibleInMenu(true);
        actionAjouter_dossier = new QAction(CuteSong);
        actionAjouter_dossier->setObjectName(QString::fromUtf8("actionAjouter_dossier"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Data/Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAjouter_dossier->setIcon(icon2);
        actionAjouter_dossier->setIconVisibleInMenu(true);
        actionAjouter_fichiers = new QAction(CuteSong);
        actionAjouter_fichiers->setObjectName(QString::fromUtf8("actionAjouter_fichiers"));
        actionAjouter_fichiers->setIcon(icon);
        actionAjouter_fichiers->setIconVisibleInMenu(true);
        actionAjouter_dossier_2 = new QAction(CuteSong);
        actionAjouter_dossier_2->setObjectName(QString::fromUtf8("actionAjouter_dossier_2"));
        actionAjouter_Fichier = new QAction(CuteSong);
        actionAjouter_Fichier->setObjectName(QString::fromUtf8("actionAjouter_Fichier"));
        actionSauver_playlist_courante = new QAction(CuteSong);
        actionSauver_playlist_courante->setObjectName(QString::fromUtf8("actionSauver_playlist_courante"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Data/Floppy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSauver_playlist_courante->setIcon(icon3);
        actionSauver_playlist_courante->setIconVisibleInMenu(true);
        actionOpen_Directory = new QAction(CuteSong);
        actionOpen_Directory->setObjectName(QString::fromUtf8("actionOpen_Directory"));
        actionOpen_Directory->setIcon(icon2);
        actionOpen_Directory->setIconVisibleInMenu(true);
        actionChange_cover = new QAction(CuteSong);
        actionChange_cover->setObjectName(QString::fromUtf8("actionChange_cover"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Data/glyphicons_151_new_window.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChange_cover->setIcon(icon4);
        actionChange_cover->setIconVisibleInMenu(true);
        actionSelect_a_playlist = new QAction(CuteSong);
        actionSelect_a_playlist->setObjectName(QString::fromUtf8("actionSelect_a_playlist"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("Data/glyphicons_114_list.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_a_playlist->setIcon(icon5);
        actionSelect_a_playlist->setIconVisibleInMenu(true);
        actionSelect_a_song = new QAction(CuteSong);
        actionSelect_a_song->setObjectName(QString::fromUtf8("actionSelect_a_song"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Data/glyphicons_018_note.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_a_song->setIcon(icon6);
        actionSelect_a_song->setIconVisibleInMenu(true);
        actionPlay = new QAction(CuteSong);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("Data/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon7);
        actionPlay->setIconVisibleInMenu(true);
        actionPause = new QAction(CuteSong);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("Data/Pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon8);
        actionPause->setIconVisibleInMenu(true);
        actionStop = new QAction(CuteSong);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("Data/Stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon9);
        actionStop->setIconVisibleInMenu(true);
        actionNext = new QAction(CuteSong);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("Data/Track[Forward].png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon10);
        actionNext->setIconVisibleInMenu(true);
        actionPrevious = new QAction(CuteSong);
        actionPrevious->setObjectName(QString::fromUtf8("actionPrevious"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("Data/Track[Back].png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevious->setIcon(icon11);
        actionPrevious->setIconVisibleInMenu(true);
        actionMute = new QAction(CuteSong);
        actionMute->setObjectName(QString::fromUtf8("actionMute"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("Data/glyphicons_182_mute.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMute->setIcon(icon12);
        actionMute->setIconVisibleInMenu(true);
        actionVolume_up = new QAction(CuteSong);
        actionVolume_up->setObjectName(QString::fromUtf8("actionVolume_up"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("Data/glyphicons_184_volume_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVolume_up->setIcon(icon13);
        actionVolume_up->setIconVisibleInMenu(true);
        actionVolume_Down = new QAction(CuteSong);
        actionVolume_Down->setObjectName(QString::fromUtf8("actionVolume_Down"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("Data/glyphicons_183_volume_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVolume_Down->setIcon(icon14);
        actionVolume_Down->setIconVisibleInMenu(true);
        actionEdit_song_s_tag = new QAction(CuteSong);
        actionEdit_song_s_tag->setObjectName(QString::fromUtf8("actionEdit_song_s_tag"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("Data/List.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_song_s_tag->setIcon(icon15);
        actionEdit_song_s_tag->setIconVisibleInMenu(true);
        actionExport_to_PLS = new QAction(CuteSong);
        actionExport_to_PLS->setObjectName(QString::fromUtf8("actionExport_to_PLS"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("Data/Sign-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_to_PLS->setIcon(icon16);
        actionExport_to_PLS->setIconVisibleInMenu(true);
        actionImport_from_PLS = new QAction(CuteSong);
        actionImport_from_PLS->setObjectName(QString::fromUtf8("actionImport_from_PLS"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8("Data/Sign-Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_from_PLS->setIcon(icon17);
        actionImport_from_PLS->setIconVisibleInMenu(true);
        centralWidget = new QWidget(CuteSong);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        centralWidget->setFont(font);
        centralWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        trackSlider = new Phonon::SeekSlider(centralWidget);
        trackSlider->setObjectName(QString::fromUtf8("trackSlider"));

        horizontalLayout_2->addWidget(trackSlider);

        lcdProgress = new QLCDNumber(centralWidget);
        lcdProgress->setObjectName(QString::fromUtf8("lcdProgress"));
        lcdProgress->setFrameShape(QFrame::NoFrame);
        lcdProgress->setFrameShadow(QFrame::Plain);
        lcdProgress->setNumDigits(4);
        lcdProgress->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(lcdProgress);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        addFileButton = new QPushButton(centralWidget);
        addFileButton->setObjectName(QString::fromUtf8("addFileButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addFileButton->sizePolicy().hasHeightForWidth());
        addFileButton->setSizePolicy(sizePolicy);
        addFileButton->setIcon(icon);

        horizontalLayout->addWidget(addFileButton);

        previousButton = new QPushButton(centralWidget);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setMaximumSize(QSize(40, 16777215));
        previousButton->setIcon(icon11);

        horizontalLayout->addWidget(previousButton);

        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setMaximumSize(QSize(40, 16777215));
        playButton->setIcon(icon7);

        horizontalLayout->addWidget(playButton);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setMaximumSize(QSize(40, 500));
        nextButton->setIcon(icon10);
        nextButton->setAutoDefault(false);
        nextButton->setDefault(false);
        nextButton->setFlat(false);

        horizontalLayout->addWidget(nextButton);

        randomCheckBox = new QCheckBox(centralWidget);
        randomCheckBox->setObjectName(QString::fromUtf8("randomCheckBox"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8("Data/glyphicons_083_random.png"), QSize(), QIcon::Normal, QIcon::Off);
        randomCheckBox->setIcon(icon18);

        horizontalLayout->addWidget(randomCheckBox);

        repeatChoice = new QComboBox(centralWidget);
        repeatChoice->setObjectName(QString::fromUtf8("repeatChoice"));

        horizontalLayout->addWidget(repeatChoice);

        repeatLabel = new QLabel(centralWidget);
        repeatLabel->setObjectName(QString::fromUtf8("repeatLabel"));
        repeatLabel->setMaximumSize(QSize(20, 20));
        repeatLabel->setPixmap(QPixmap(QString::fromUtf8("Data/repeatNormal.png")));
        repeatLabel->setScaledContents(true);

        horizontalLayout->addWidget(repeatLabel);

        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        volumeSlider = new Phonon::VolumeSlider(centralWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy1);
        volumeSlider->setMinimumSize(QSize(150, 15));
        volumeSlider->setMaximumSize(QSize(0, 0));
        volumeSlider->setAutoFillBackground(false);

        horizontalLayout->addWidget(volumeSlider);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabShape(QTabWidget::Rounded);
        homeTab = new QWidget();
        homeTab->setObjectName(QString::fromUtf8("homeTab"));
        gridLayout_3 = new QGridLayout(homeTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelAlbum = new QLabel(homeTab);
        labelAlbum->setObjectName(QString::fromUtf8("labelAlbum"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(7);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelAlbum->sizePolicy().hasHeightForWidth());
        labelAlbum->setSizePolicy(sizePolicy2);
        labelAlbum->setMinimumSize(QSize(230, 0));

        gridLayout_3->addWidget(labelAlbum, 7, 1, 1, 1);

        coverLabel = new QLabel(homeTab);
        coverLabel->setObjectName(QString::fromUtf8("coverLabel"));
        coverLabel->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(coverLabel->sizePolicy().hasHeightForWidth());
        coverLabel->setSizePolicy(sizePolicy3);
        coverLabel->setMinimumSize(QSize(280, 280));
        coverLabel->setFrameShape(QFrame::StyledPanel);
        coverLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(coverLabel, 0, 0, 1, 2);

        labelTitle = new QLabel(homeTab);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(7);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy4);
        labelTitle->setMinimumSize(QSize(230, 20));

        gridLayout_3->addWidget(labelTitle, 5, 1, 1, 1);

        label = new QLabel(homeTab);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(4);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label, 7, 0, 1, 1);

        playlist = new QListWidget(homeTab);
        playlist->setObjectName(QString::fromUtf8("playlist"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(15);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(playlist->sizePolicy().hasHeightForWidth());
        playlist->setSizePolicy(sizePolicy6);

        gridLayout_3->addWidget(playlist, 0, 3, 6, 1);

        label_2 = new QLabel(homeTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(4);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy7);

        gridLayout_3->addWidget(label_2, 6, 0, 1, 1);

        labelArtist = new QLabel(homeTab);
        labelArtist->setObjectName(QString::fromUtf8("labelArtist"));
        sizePolicy4.setHeightForWidth(labelArtist->sizePolicy().hasHeightForWidth());
        labelArtist->setSizePolicy(sizePolicy4);
        labelArtist->setMinimumSize(QSize(230, 0));

        gridLayout_3->addWidget(labelArtist, 6, 1, 1, 1);

        label_3 = new QLabel(homeTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_3, 5, 0, 1, 1);

        rmPlaylistButton = new QPushButton(homeTab);
        rmPlaylistButton->setObjectName(QString::fromUtf8("rmPlaylistButton"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(rmPlaylistButton->sizePolicy().hasHeightForWidth());
        rmPlaylistButton->setSizePolicy(sizePolicy8);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8("Data/glyphicons_197_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        rmPlaylistButton->setIcon(icon19);

        gridLayout_3->addWidget(rmPlaylistButton, 7, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        moveUpButton = new QPushButton(homeTab);
        moveUpButton->setObjectName(QString::fromUtf8("moveUpButton"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8("Data/glyphicons_213_up_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveUpButton->setIcon(icon20);

        horizontalLayout_3->addWidget(moveUpButton);

        moveDownButton = new QPushButton(homeTab);
        moveDownButton->setObjectName(QString::fromUtf8("moveDownButton"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8("Data/glyphicons_212_down_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveDownButton->setIcon(icon21);

        horizontalLayout_3->addWidget(moveDownButton);


        gridLayout_3->addLayout(horizontalLayout_3, 6, 3, 1, 1);

        tabWidget->addTab(homeTab, icon6, QString());
        bibliothequeTab = new QWidget();
        bibliothequeTab->setObjectName(QString::fromUtf8("bibliothequeTab"));
        gridLayout_4 = new QGridLayout(bibliothequeTab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        bddView = new QTableView(bibliothequeTab);
        bddView->setObjectName(QString::fromUtf8("bddView"));
        bddView->setShowGrid(false);
        bddView->setSortingEnabled(true);
        bddView->horizontalHeader()->setStretchLastSection(true);
        bddView->verticalHeader()->setCascadingSectionResizes(true);

        gridLayout_4->addWidget(bddView, 3, 0, 1, 6);

        addButton = new QPushButton(bibliothequeTab);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        sizePolicy3.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy3);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8("Data/glyphicons_190_circle_plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon22);

        gridLayout_4->addWidget(addButton, 2, 0, 1, 1);

        rmButton = new QPushButton(bibliothequeTab);
        rmButton->setObjectName(QString::fromUtf8("rmButton"));
        sizePolicy3.setHeightForWidth(rmButton->sizePolicy().hasHeightForWidth());
        rmButton->setSizePolicy(sizePolicy3);
        rmButton->setIcon(icon19);

        gridLayout_4->addWidget(rmButton, 0, 0, 2, 1);

        searchButton = new QPushButton(bibliothequeTab);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        sizePolicy3.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy3);
        QIcon icon23;
        icon23.addFile(QString::fromUtf8("Data/Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon23);

        gridLayout_4->addWidget(searchButton, 1, 5, 2, 1);

        label_4 = new QLabel(bibliothequeTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy9);

        gridLayout_4->addWidget(label_4, 1, 2, 2, 1);

        searchBy = new QComboBox(bibliothequeTab);
        searchBy->setObjectName(QString::fromUtf8("searchBy"));
        sizePolicy3.setHeightForWidth(searchBy->sizePolicy().hasHeightForWidth());
        searchBy->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(searchBy, 1, 3, 2, 1);

        playFilesButton = new QPushButton(bibliothequeTab);
        playFilesButton->setObjectName(QString::fromUtf8("playFilesButton"));
        sizePolicy9.setHeightForWidth(playFilesButton->sizePolicy().hasHeightForWidth());
        playFilesButton->setSizePolicy(sizePolicy9);
        playFilesButton->setIcon(icon7);

        gridLayout_4->addWidget(playFilesButton, 0, 1, 3, 1);

        searched = new QLineEdit(bibliothequeTab);
        searched->setObjectName(QString::fromUtf8("searched"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(searched->sizePolicy().hasHeightForWidth());
        searched->setSizePolicy(sizePolicy10);

        gridLayout_4->addWidget(searched, 1, 4, 2, 1);

        QIcon icon24;
        icon24.addFile(QString::fromUtf8("Data/iTunes.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(bibliothequeTab, icon24, QString());
        tabPlaylist = new QWidget();
        tabPlaylist->setObjectName(QString::fromUtf8("tabPlaylist"));
        gridLayout_2 = new QGridLayout(tabPlaylist);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        playPlaylistButton = new QPushButton(tabPlaylist);
        playPlaylistButton->setObjectName(QString::fromUtf8("playPlaylistButton"));
        sizePolicy10.setHeightForWidth(playPlaylistButton->sizePolicy().hasHeightForWidth());
        playPlaylistButton->setSizePolicy(sizePolicy10);
        playPlaylistButton->setIcon(icon7);

        gridLayout_2->addWidget(playPlaylistButton, 0, 0, 1, 1);

        tablePlaylistContent = new QTableView(tabPlaylist);
        tablePlaylistContent->setObjectName(QString::fromUtf8("tablePlaylistContent"));
        tablePlaylistContent->setSortingEnabled(false);
        tablePlaylistContent->horizontalHeader()->setDefaultSectionSize(100);
        tablePlaylistContent->horizontalHeader()->setStretchLastSection(true);
        tablePlaylistContent->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(tablePlaylistContent, 0, 1, 4, 1);

        rmPlaylistButton_2 = new QPushButton(tabPlaylist);
        rmPlaylistButton_2->setObjectName(QString::fromUtf8("rmPlaylistButton_2"));
        sizePolicy10.setHeightForWidth(rmPlaylistButton_2->sizePolicy().hasHeightForWidth());
        rmPlaylistButton_2->setSizePolicy(sizePolicy10);
        rmPlaylistButton_2->setIcon(icon19);

        gridLayout_2->addWidget(rmPlaylistButton_2, 1, 0, 1, 1);

        tablePlaylists = new QTableView(tabPlaylist);
        tablePlaylists->setObjectName(QString::fromUtf8("tablePlaylists"));
        QSizePolicy sizePolicy11(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(tablePlaylists->sizePolicy().hasHeightForWidth());
        tablePlaylists->setSizePolicy(sizePolicy11);
        tablePlaylists->horizontalHeader()->setStretchLastSection(true);
        tablePlaylists->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(tablePlaylists, 3, 0, 1, 1);

        renamePlaylistButton = new QPushButton(tabPlaylist);
        renamePlaylistButton->setObjectName(QString::fromUtf8("renamePlaylistButton"));
        renamePlaylistButton->setIcon(icon5);

        gridLayout_2->addWidget(renamePlaylistButton, 2, 0, 1, 1);

        tabWidget->addTab(tabPlaylist, icon5, QString());
        wikiTab = new QWidget();
        wikiTab->setObjectName(QString::fromUtf8("wikiTab"));
        gridLayout_7 = new QGridLayout(wikiTab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        wikiView = new QWebView(wikiTab);
        wikiView->setObjectName(QString::fromUtf8("wikiView"));
        wikiView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_7->addWidget(wikiView, 0, 0, 1, 1);

        QIcon icon25;
        icon25.addFile(QString::fromUtf8("Data/Globe.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(wikiTab, icon25, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        CuteSong->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CuteSong);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 801, 29));
        menuPlaylist = new QMenu(menuBar);
        menuPlaylist->setObjectName(QString::fromUtf8("menuPlaylist"));
        menuBibliotheque = new QMenu(menuBar);
        menuBibliotheque->setObjectName(QString::fromUtf8("menuBibliotheque"));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuLecture = new QMenu(menuBar);
        menuLecture->setObjectName(QString::fromUtf8("menuLecture"));
        CuteSong->setMenuBar(menuBar);
        statusBar = new QStatusBar(CuteSong);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CuteSong->setStatusBar(statusBar);
        QWidget::setTabOrder(addFileButton, previousButton);
        QWidget::setTabOrder(previousButton, playButton);
        QWidget::setTabOrder(playButton, nextButton);
        QWidget::setTabOrder(nextButton, randomCheckBox);
        QWidget::setTabOrder(randomCheckBox, repeatChoice);
        QWidget::setTabOrder(repeatChoice, tabWidget);
        QWidget::setTabOrder(tabWidget, playlist);
        QWidget::setTabOrder(playlist, rmPlaylistButton);
        QWidget::setTabOrder(rmPlaylistButton, addButton);
        QWidget::setTabOrder(addButton, rmButton);
        QWidget::setTabOrder(rmButton, searchBy);
        QWidget::setTabOrder(searchBy, searched);
        QWidget::setTabOrder(searched, searchButton);
        QWidget::setTabOrder(searchButton, bddView);
        QWidget::setTabOrder(bddView, playFilesButton);
        QWidget::setTabOrder(playFilesButton, rmPlaylistButton_2);
        QWidget::setTabOrder(rmPlaylistButton_2, tablePlaylistContent);
        QWidget::setTabOrder(tablePlaylistContent, tablePlaylists);
        QWidget::setTabOrder(tablePlaylists, playPlaylistButton);
        QWidget::setTabOrder(playPlaylistButton, wikiView);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuLecture->menuAction());
        menuBar->addAction(menuBibliotheque->menuAction());
        menuBar->addAction(menuPlaylist->menuAction());
        menuPlaylist->addAction(actionSauver_playlist_courante);
        menuPlaylist->addAction(actionExport_to_PLS);
        menuPlaylist->addAction(actionImport_from_PLS);
        menuBibliotheque->addAction(actionAjouter_dossier);
        menuBibliotheque->addAction(actionAjouter_fichiers);
        menuFichier->addAction(actionOuvrir_fichier);
        menuFichier->addSeparator();
        menuFichier->addAction(actionOpen_Directory);
        menuFichier->addAction(actionChange_cover);
        menuFichier->addAction(actionEdit_song_s_tag);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuit);
        menuLecture->addAction(actionPlay);
        menuLecture->addAction(actionPause);
        menuLecture->addAction(actionStop);
        menuLecture->addSeparator();
        menuLecture->addAction(actionPrevious);
        menuLecture->addAction(actionNext);
        menuLecture->addSeparator();
        menuLecture->addAction(actionMute);
        menuLecture->addAction(actionVolume_Down);
        menuLecture->addAction(actionVolume_up);

        retranslateUi(CuteSong);
        QObject::connect(playButton, SIGNAL(clicked()), CuteSong, SLOT(playPause()));
        QObject::connect(addFileButton, SIGNAL(clicked()), CuteSong, SLOT(addFile()));
        QObject::connect(nextButton, SIGNAL(clicked()), CuteSong, SLOT(next()));
        QObject::connect(previousButton, SIGNAL(clicked()), CuteSong, SLOT(previous()));
        QObject::connect(addButton, SIGNAL(toggled(bool)), CuteSong, SLOT(on_addButton_clicked()));
        QObject::connect(searchButton, SIGNAL(clicked()), CuteSong, SLOT(on_searchButton_toggled()));
        QObject::connect(rmPlaylistButton, SIGNAL(clicked()), CuteSong, SLOT(on_rmFromPlaylist_clicked()));
        QObject::connect(rmButton, SIGNAL(clicked()), CuteSong, SLOT(on_rmButton_toggled()));
        QObject::connect(rmPlaylistButton_2, SIGNAL(toggled(bool)), CuteSong, SLOT(on_rmPlaylistButton_toggled()));
        QObject::connect(playFilesButton, SIGNAL(clicked()), CuteSong, SLOT(on_playFilesButton_toggled()));
        QObject::connect(playPlaylistButton, SIGNAL(clicked()), CuteSong, SLOT(on_playPlaylistButton_toggled()));
        QObject::connect(rmPlaylistButton_2, SIGNAL(clicked()), CuteSong, SLOT(on_rmPlaylistButton_toggled()));
        QObject::connect(searched, SIGNAL(textChanged(QString)), searchButton, SLOT(click()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CuteSong);
    } // setupUi

    void retranslateUi(QMainWindow *CuteSong)
    {
        CuteSong->setWindowTitle(QApplication::translate("CuteSong", "CuteSong", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("CuteSong", "Quitter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("CuteSong", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOuvrir_fichier->setText(QApplication::translate("CuteSong", "Open file", 0, QApplication::UnicodeUTF8));
        actionOuvrir_fichier->setShortcut(QApplication::translate("CuteSong", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("CuteSong", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("CuteSong", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAjouter_dossier->setText(QApplication::translate("CuteSong", "Add Directory", 0, QApplication::UnicodeUTF8));
        actionAjouter_fichiers->setText(QApplication::translate("CuteSong", "Add Files", 0, QApplication::UnicodeUTF8));
        actionAjouter_dossier_2->setText(QApplication::translate("CuteSong", "Ajouter dossier", 0, QApplication::UnicodeUTF8));
        actionAjouter_Fichier->setText(QApplication::translate("CuteSong", "Ajouter Fichier", 0, QApplication::UnicodeUTF8));
        actionSauver_playlist_courante->setText(QApplication::translate("CuteSong", "Save current playlist", 0, QApplication::UnicodeUTF8));
        actionSauver_playlist_courante->setShortcut(QApplication::translate("CuteSong", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionOpen_Directory->setText(QApplication::translate("CuteSong", "Open Directory", 0, QApplication::UnicodeUTF8));
        actionOpen_Directory->setShortcut(QApplication::translate("CuteSong", "Ctrl+Shift+O", 0, QApplication::UnicodeUTF8));
        actionChange_cover->setText(QApplication::translate("CuteSong", "Change song's cover", 0, QApplication::UnicodeUTF8));
        actionChange_cover->setShortcut(QApplication::translate("CuteSong", "Ctrl+Shift+E", 0, QApplication::UnicodeUTF8));
        actionSelect_a_playlist->setText(QApplication::translate("CuteSong", "Select playlist", 0, QApplication::UnicodeUTF8));
        actionSelect_a_playlist->setShortcut(QApplication::translate("CuteSong", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionSelect_a_song->setText(QApplication::translate("CuteSong", "Select songs", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("CuteSong", "Play", 0, QApplication::UnicodeUTF8));
        actionPlay->setShortcut(QApplication::translate("CuteSong", "Ctrl+F1", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("CuteSong", "Pause", 0, QApplication::UnicodeUTF8));
        actionPause->setShortcut(QApplication::translate("CuteSong", "Ctrl+F2", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("CuteSong", "Stop", 0, QApplication::UnicodeUTF8));
        actionStop->setShortcut(QApplication::translate("CuteSong", "Ctrl+F3", 0, QApplication::UnicodeUTF8));
        actionNext->setText(QApplication::translate("CuteSong", "Next", 0, QApplication::UnicodeUTF8));
        actionNext->setShortcut(QApplication::translate("CuteSong", "Ctrl+F5", 0, QApplication::UnicodeUTF8));
        actionPrevious->setText(QApplication::translate("CuteSong", "Previous", 0, QApplication::UnicodeUTF8));
        actionPrevious->setShortcut(QApplication::translate("CuteSong", "Ctrl+F4", 0, QApplication::UnicodeUTF8));
        actionMute->setText(QApplication::translate("CuteSong", "Mute", 0, QApplication::UnicodeUTF8));
        actionMute->setShortcut(QApplication::translate("CuteSong", "Ctrl+F10", 0, QApplication::UnicodeUTF8));
        actionVolume_up->setText(QApplication::translate("CuteSong", "Volume up", 0, QApplication::UnicodeUTF8));
        actionVolume_up->setShortcut(QApplication::translate("CuteSong", "Ctrl+F12", 0, QApplication::UnicodeUTF8));
        actionVolume_Down->setText(QApplication::translate("CuteSong", "Volume Down", 0, QApplication::UnicodeUTF8));
        actionVolume_Down->setShortcut(QApplication::translate("CuteSong", "Ctrl+F11", 0, QApplication::UnicodeUTF8));
        actionEdit_song_s_tag->setText(QApplication::translate("CuteSong", "Edit song's tag", 0, QApplication::UnicodeUTF8));
        actionExport_to_PLS->setText(QApplication::translate("CuteSong", "Export to PLS", 0, QApplication::UnicodeUTF8));
        actionImport_from_PLS->setText(QApplication::translate("CuteSong", "Import from PLS", 0, QApplication::UnicodeUTF8));
        addFileButton->setText(QApplication::translate("CuteSong", "Open Files", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QString());
        playButton->setText(QString());
        nextButton->setText(QString());
        randomCheckBox->setText(QString());
        repeatChoice->clear();
        repeatChoice->insertItems(0, QStringList()
         << QApplication::translate("CuteSong", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CuteSong", "Repeat One", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CuteSong", "Repeat All", 0, QApplication::UnicodeUTF8)
        );
        repeatLabel->setText(QString());
        labelAlbum->setText(QString());
        coverLabel->setText(QString());
        labelTitle->setText(QString());
        label->setText(QApplication::translate("CuteSong", "Album :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CuteSong", "Artist :", 0, QApplication::UnicodeUTF8));
        labelArtist->setText(QString());
        label_3->setText(QApplication::translate("CuteSong", "Title :", 0, QApplication::UnicodeUTF8));
        rmPlaylistButton->setText(QApplication::translate("CuteSong", "Remove", 0, QApplication::UnicodeUTF8));
        moveUpButton->setText(QApplication::translate("CuteSong", "Move up", 0, QApplication::UnicodeUTF8));
        moveDownButton->setText(QApplication::translate("CuteSong", "Move down", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(homeTab), QApplication::translate("CuteSong", "Play", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("CuteSong", "Add Files     ", 0, QApplication::UnicodeUTF8));
        rmButton->setText(QApplication::translate("CuteSong", "Remove File", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QString());
        label_4->setText(QApplication::translate("CuteSong", "Search by :", 0, QApplication::UnicodeUTF8));
        searchBy->clear();
        searchBy->insertItems(0, QStringList()
         << QApplication::translate("CuteSong", "artist", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CuteSong", "album", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CuteSong", "title", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CuteSong", "filename", 0, QApplication::UnicodeUTF8)
        );
        playFilesButton->setText(QApplication::translate("CuteSong", "Play Files", 0, QApplication::UnicodeUTF8));
        searched->setText(QString());
        searched->setPlaceholderText(QApplication::translate("CuteSong", "Search", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(bibliothequeTab), QApplication::translate("CuteSong", "My Music", 0, QApplication::UnicodeUTF8));
        playPlaylistButton->setText(QApplication::translate("CuteSong", "Play Playlist", 0, QApplication::UnicodeUTF8));
        rmPlaylistButton_2->setText(QApplication::translate("CuteSong", "Delete Playlist", 0, QApplication::UnicodeUTF8));
        renamePlaylistButton->setText(QApplication::translate("CuteSong", "Rename Playlist", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPlaylist), QApplication::translate("CuteSong", "Playlist", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(wikiTab), QApplication::translate("CuteSong", "Wiki", 0, QApplication::UnicodeUTF8));
        menuPlaylist->setTitle(QApplication::translate("CuteSong", "Playlist", 0, QApplication::UnicodeUTF8));
        menuBibliotheque->setTitle(QApplication::translate("CuteSong", "My Music", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("CuteSong", "Files", 0, QApplication::UnicodeUTF8));
        menuLecture->setTitle(QApplication::translate("CuteSong", "Play", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CuteSong: public Ui_CuteSong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTESONG_H
