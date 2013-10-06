/****************************************************************************
** Meta object code from reading C++ file 'tageditiondialog.h'
**
** Created: Sat Jan 12 20:26:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tageditiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tageditiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TagEditionDialog[] = {

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
      42,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      90,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TagEditionDialog[] = {
    "TagEditionDialog\0\0path,artist,album,title\0"
    "tagChanged(std::string,QString,QString,QString)\0"
    "on_saveButton_clicked()\0"
};

void TagEditionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TagEditionDialog *_t = static_cast<TagEditionDialog *>(_o);
        switch (_id) {
        case 0: _t->tagChanged((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->on_saveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TagEditionDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TagEditionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TagEditionDialog,
      qt_meta_data_TagEditionDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TagEditionDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TagEditionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TagEditionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TagEditionDialog))
        return static_cast<void*>(const_cast< TagEditionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TagEditionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TagEditionDialog::tagChanged(std::string _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
