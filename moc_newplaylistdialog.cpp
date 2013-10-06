/****************************************************************************
** Meta object code from reading C++ file 'newplaylistdialog.h'
**
** Created: Sat Jan 12 20:26:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newplaylistdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newplaylistdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_newPlaylistDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_newPlaylistDialog[] = {
    "newPlaylistDialog\0\0name\0name(QString)\0"
    "ok()\0"
};

void newPlaylistDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        newPlaylistDialog *_t = static_cast<newPlaylistDialog *>(_o);
        switch (_id) {
        case 0: _t->name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ok(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData newPlaylistDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject newPlaylistDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_newPlaylistDialog,
      qt_meta_data_newPlaylistDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &newPlaylistDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *newPlaylistDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *newPlaylistDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_newPlaylistDialog))
        return static_cast<void*>(const_cast< newPlaylistDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int newPlaylistDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void newPlaylistDialog::name(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
