/****************************************************************************
** Meta object code from reading C++ file 'qabstractstate.h'
**
** Created: Fri Aug 13 10:08:02 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qabstractstate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtAbstractState[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       1,   17, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      30,   16, 0x0009510b,

 // enums: name, flags, count, data
      16, 0x0,    3,   21,

 // enum data: key, value
      44, uint(QtAbstractState::GlobalRestorePolicy),
      64, uint(QtAbstractState::DoNotRestoreProperties),
      87, uint(QtAbstractState::RestoreProperties),

       0        // eod
};

static const char qt_meta_stringdata_QtAbstractState[] = {
    "QtAbstractState\0RestorePolicy\0"
    "restorePolicy\0GlobalRestorePolicy\0"
    "DoNotRestoreProperties\0RestoreProperties\0"
};

const QMetaObject QtAbstractState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtAbstractState,
      qt_meta_data_QtAbstractState, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtAbstractState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtAbstractState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtAbstractState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtAbstractState))
        return static_cast<void*>(const_cast< QtAbstractState*>(this));
    return QObject::qt_metacast(_clname);
}

int QtAbstractState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< RestorePolicy*>(_v) = restorePolicy(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setRestorePolicy(*reinterpret_cast< RestorePolicy*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
