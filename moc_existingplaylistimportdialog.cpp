/****************************************************************************
** Meta object code from reading C++ file 'existingplaylistimportdialog.h'
**
** Created: Sat Jan 12 20:26:12 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "existingplaylistimportdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'existingplaylistimportdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ExistingPlaylistImportDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      49,   30,   29,   29, 0x05,
      77,   30,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,   29,   29,   29, 0x08,
     132,   29,   29,   29, 0x08,
     154,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ExistingPlaylistImportDialog[] = {
    "ExistingPlaylistImportDialog\0\0"
    "list,playlist_name\0yes(QList<QString>,QString)\0"
    "replace(QList<QString>,QString)\0"
    "on_yesButton_clicked()\0on_noButton_clicked()\0"
    "on_replaceButton_clicked()\0"
};

void ExistingPlaylistImportDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ExistingPlaylistImportDialog *_t = static_cast<ExistingPlaylistImportDialog *>(_o);
        switch (_id) {
        case 0: _t->yes((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->replace((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_yesButton_clicked(); break;
        case 3: _t->on_noButton_clicked(); break;
        case 4: _t->on_replaceButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ExistingPlaylistImportDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ExistingPlaylistImportDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ExistingPlaylistImportDialog,
      qt_meta_data_ExistingPlaylistImportDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ExistingPlaylistImportDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ExistingPlaylistImportDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ExistingPlaylistImportDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExistingPlaylistImportDialog))
        return static_cast<void*>(const_cast< ExistingPlaylistImportDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ExistingPlaylistImportDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ExistingPlaylistImportDialog::yes(QList<QString> _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExistingPlaylistImportDialog::replace(QList<QString> _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
