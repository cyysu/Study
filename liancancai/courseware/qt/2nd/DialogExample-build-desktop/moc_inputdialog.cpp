/****************************************************************************
** Meta object code from reading C++ file 'inputdialog.h'
**
** Created: Fri Nov 25 17:26:10 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DialogExample/inputdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InputDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      30,   12,   12,   12, 0x0a,
      46,   12,   12,   12, 0x0a,
      62,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InputDialog[] = {
    "InputDialog\0\0changeNameSlot()\0"
    "changeSexSlot()\0changeAgeSlot()\0"
    "changeResultSlot()\0"
};

const QMetaObject InputDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InputDialog,
      qt_meta_data_InputDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InputDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InputDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InputDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InputDialog))
        return static_cast<void*>(const_cast< InputDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int InputDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeNameSlot(); break;
        case 1: changeSexSlot(); break;
        case 2: changeAgeSlot(); break;
        case 3: changeResultSlot(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
