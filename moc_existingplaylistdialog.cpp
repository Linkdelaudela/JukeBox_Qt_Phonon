/****************************************************************************
** Meta object code from reading C++ file 'existingplaylistdialog.h'
**
** Created: Sat Jan 12 20:26:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "existingplaylistdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'existingplaylistdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ExistingPlaylistDialog[] = {

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
      38,   24,   23,   23, 0x05,
      51,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   23,   23,   23, 0x08,
      91,   23,   23,   23, 0x08,
     113,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ExistingPlaylistDialog[] = {
    "ExistingPlaylistDialog\0\0playlist_name\0"
    "yes(QString)\0replace(QString)\0"
    "on_yesButton_clicked()\0on_noButton_clicked()\0"
    "on_replaceButton_clicked()\0"
};

void ExistingPlaylistDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ExistingPlaylistDialog *_t = static_cast<ExistingPlaylistDialog *>(_o);
        switch (_id) {
        case 0: _t->yes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->replace((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_yesButton_clicked(); break;
        case 3: _t->on_noButton_clicked(); break;
        case 4: _t->on_replaceButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ExistingPlaylistDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ExistingPlaylistDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ExistingPlaylistDialog,
      qt_meta_data_ExistingPlaylistDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ExistingPlaylistDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ExistingPlaylistDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ExistingPlaylistDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExistingPlaylistDialog))
        return static_cast<void*>(const_cast< ExistingPlaylistDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ExistingPlaylistDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ExistingPlaylistDialog::yes(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExistingPlaylistDialog::replace(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
