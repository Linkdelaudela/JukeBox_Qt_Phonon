/****************************************************************************
** Meta object code from reading C++ file 'cutesong.h'
**
** Created: Sat Jan 12 20:26:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cutesong.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cutesong.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CuteSong[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      22,    9,    9,    9, 0x08,
      32,    9,    9,    9, 0x08,
      39,    9,    9,    9, 0x08,
      50,    9,    9,    9, 0x08,
      76,    9,    9,    9, 0x08,
      99,    9,    9,    9, 0x08,
     121,    9,    9,    9, 0x08,
     138,    9,    9,    9, 0x08,
     169,  164,    9,    9, 0x08,
     203,    9,    9,    9, 0x08,
     231,    9,    9,    9, 0x08,
     251,  245,    9,    9, 0x08,
     290,  245,    9,    9, 0x08,
     350,  341,    9,    9, 0x08,
     387,    9,    9,    9, 0x08,
     419,    9,    9,    9, 0x08,
     449,    9,    9,    9, 0x08,
     478,  164,    9,    9, 0x08,
     506,    9,    9,    9, 0x08,
     530,    9,  526,    9, 0x08,
     551,    9,    9,    9, 0x08,
     566,  245,    9,    9, 0x08,
     605,  245,    9,    9, 0x08,
     646,    9,    9,    9, 0x08,
     678,    9,    9,    9, 0x08,
     697,    9,    9,    9, 0x08,
     711,    9,    9,    9, 0x08,
     730,    9,    9,    9, 0x08,
     743,    9,    9,    9, 0x08,
     754,    9,    9,    9, 0x08,
     788,  245,    9,    9, 0x08,
     820,    9,    9,    9, 0x08,
     848,    9,    9,    9, 0x08,
     879,  874,    9,    9, 0x09,
     910,  874,    9,    9, 0x09,
     941,  874,    9,    9, 0x09,
     965,  874,    9,    9, 0x09,
    1013, 1000,    9,    9, 0x09,
    1067, 1043,    9,    9, 0x09,
    1130,    9,    9,    9, 0x09,
    1151,    9,    9,    9, 0x09,
    1163,    9,    9,    9, 0x09,
    1184, 1175,    9,    9, 0x09,
    1226, 1175,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CuteSong[] = {
    "CuteSong\0\0playPause()\0addFile()\0next()\0"
    "previous()\0tickOfMediaObject(qint64)\0"
    "on_addButton_clicked()\0on_rmButton_toggled()\0"
    "updateDataSong()\0on_searchButton_toggled()\0"
    "path\0addToCurrentPlaylist(const char*)\0"
    "on_rmFromPlaylist_clicked()\0addDirToBdd()\0"
    "index\0on_tablePlaylists_clicked(QModelIndex)\0"
    "on_tablePlaylistContent_doubleClicked(QModelIndex)\0"
    "playlist\0makePlaylistContentView(std::string)\0"
    "on_playPlaylistButton_toggled()\0"
    "on_rmPlaylistButton_toggled()\0"
    "on_playFilesButton_toggled()\0"
    "setCurrentSong(const char*)\0"
    "popPlaylistDialog()\0int\0generateRandomSkip()\0"
    "songFinished()\0on_playlist_doubleClicked(QModelIndex)\0"
    "on_repeatChoice_currentIndexChanged(int)\0"
    "on_button_changeCover_clicked()\0"
    "addDirToPlaylist()\0muteManager()\0"
    "stopStateManager()\0volumeDown()\0"
    "volumeUp()\0on_renamePlaylistButton_clicked()\0"
    "on_bddView_clicked(QModelIndex)\0"
    "on_moveDownButton_clicked()\0"
    "on_moveUpButton_clicked()\0name\0"
    "exportCurrentPlaylist(QString)\0"
    "exportPlaylistProcess(QString)\0"
    "deletePlaylist(QString)\0"
    "renamePlaylistProcess(std::string)\0"
    "wanted_state\0allowPlayControlManager(bool)\0"
    "path,artist,album,title\0"
    "editCurrentSongTagProcess(std::string,QString,QString,QString)\0"
    "editCurrentSongTag()\0PLSImport()\0"
    "PLSExport()\0pls,name\0"
    "importPlaylistPls(QList<QString>,QString)\0"
    "deletePlaylistImport(QList<QString>,QString)\0"
};

void CuteSong::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CuteSong *_t = static_cast<CuteSong *>(_o);
        switch (_id) {
        case 0: _t->playPause(); break;
        case 1: _t->addFile(); break;
        case 2: _t->next(); break;
        case 3: _t->previous(); break;
        case 4: _t->tickOfMediaObject((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->on_addButton_clicked(); break;
        case 6: _t->on_rmButton_toggled(); break;
        case 7: _t->updateDataSong(); break;
        case 8: _t->on_searchButton_toggled(); break;
        case 9: _t->addToCurrentPlaylist((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 10: _t->on_rmFromPlaylist_clicked(); break;
        case 11: _t->addDirToBdd(); break;
        case 12: _t->on_tablePlaylists_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_tablePlaylistContent_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->makePlaylistContentView((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 15: _t->on_playPlaylistButton_toggled(); break;
        case 16: _t->on_rmPlaylistButton_toggled(); break;
        case 17: _t->on_playFilesButton_toggled(); break;
        case 18: _t->setCurrentSong((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 19: _t->popPlaylistDialog(); break;
        case 20: { int _r = _t->generateRandomSkip();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 21: _t->songFinished(); break;
        case 22: _t->on_playlist_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 23: _t->on_repeatChoice_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_button_changeCover_clicked(); break;
        case 25: _t->addDirToPlaylist(); break;
        case 26: _t->muteManager(); break;
        case 27: _t->stopStateManager(); break;
        case 28: _t->volumeDown(); break;
        case 29: _t->volumeUp(); break;
        case 30: _t->on_renamePlaylistButton_clicked(); break;
        case 31: _t->on_bddView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 32: _t->on_moveDownButton_clicked(); break;
        case 33: _t->on_moveUpButton_clicked(); break;
        case 34: _t->exportCurrentPlaylist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->exportPlaylistProcess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->deletePlaylist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->renamePlaylistProcess((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 38: _t->allowPlayControlManager((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->editCurrentSongTagProcess((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 40: _t->editCurrentSongTag(); break;
        case 41: _t->PLSImport(); break;
        case 42: _t->PLSExport(); break;
        case 43: _t->importPlaylistPls((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 44: _t->deletePlaylistImport((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CuteSong::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CuteSong::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CuteSong,
      qt_meta_data_CuteSong, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CuteSong::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CuteSong::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CuteSong::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CuteSong))
        return static_cast<void*>(const_cast< CuteSong*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CuteSong::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
