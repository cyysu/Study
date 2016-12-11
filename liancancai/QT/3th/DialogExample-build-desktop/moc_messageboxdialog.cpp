/****************************************************************************
** Meta object code from reading C++ file 'messageboxdialog.h'
**
** Created: Mon Nov 28 12:02:46 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DialogExample/messageboxdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messageboxdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessageBoxDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      40,   17,   17,   17, 0x0a,
      65,   17,   17,   17, 0x0a,
      86,   17,   17,   17, 0x0a,
     108,   17,   17,   17, 0x0a,
     127,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MessageBoxDialog[] = {
    "MessageBoxDialog\0\0showQuestionMsgSlot()\0"
    "showInformationMsgSlot()\0showWarningMsgSlot()\0"
    "showCriticalMsgSlot()\0showAboutMsgSlot()\0"
    "showAboutQtMsgSlot()\0"
};

const QMetaObject MessageBoxDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MessageBoxDialog,
      qt_meta_data_MessageBoxDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessageBoxDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessageBoxDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessageBoxDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageBoxDialog))
        return static_cast<void*>(const_cast< MessageBoxDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MessageBoxDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showQuestionMsgSlot(); break;
        case 1: showInformationMsgSlot(); break;
        case 2: showWarningMsgSlot(); break;
        case 3: showCriticalMsgSlot(); break;
        case 4: showAboutMsgSlot(); break;
        case 5: showAboutQtMsgSlot(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
