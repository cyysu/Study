/****************************************************************************
** Meta object code from reading C++ file 'addressbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addressbook/addressbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addressBook_t {
    QByteArrayData data[12];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addressBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addressBook_t qt_meta_stringdata_addressBook = {
    {
QT_MOC_LITERAL(0, 0, 11), // "addressBook"
QT_MOC_LITERAL(1, 12, 7), // "addProc"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "editProc"
QT_MOC_LITERAL(4, 30, 10), // "removeProc"
QT_MOC_LITERAL(5, 41, 8), // "findProc"
QT_MOC_LITERAL(6, 50, 10), // "submitProc"
QT_MOC_LITERAL(7, 61, 10), // "cancelProc"
QT_MOC_LITERAL(8, 72, 8), // "loadProc"
QT_MOC_LITERAL(9, 81, 8), // "saveProc"
QT_MOC_LITERAL(10, 90, 13), // "previousrProc"
QT_MOC_LITERAL(11, 104, 8) // "nextProc"

    },
    "addressBook\0addProc\0\0editProc\0removeProc\0"
    "findProc\0submitProc\0cancelProc\0loadProc\0"
    "saveProc\0previousrProc\0nextProc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addressBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addressBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addressBook *_t = static_cast<addressBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addProc(); break;
        case 1: _t->editProc(); break;
        case 2: _t->removeProc(); break;
        case 3: _t->findProc(); break;
        case 4: _t->submitProc(); break;
        case 5: _t->cancelProc(); break;
        case 6: _t->loadProc(); break;
        case 7: _t->saveProc(); break;
        case 8: _t->previousrProc(); break;
        case 9: _t->nextProc(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject addressBook::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addressBook.data,
      qt_meta_data_addressBook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *addressBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addressBook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_addressBook.stringdata0))
        return static_cast<void*>(const_cast< addressBook*>(this));
    return QDialog::qt_metacast(_clname);
}

int addressBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
