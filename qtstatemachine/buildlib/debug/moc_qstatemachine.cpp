/****************************************************************************
** Meta object code from reading C++ file 'qstatemachine.h'
**
** Created: Fri Aug 13 10:07:48 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qstatemachine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstatemachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtStateMachine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      26,   15,   15,   15, 0x05,
      36,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   15,   15,   15, 0x0a,
      55,   15,   15,   15, 0x0a,
      62,   15,   15,   15, 0x08,
      73,   15,   15,   15, 0x08,

 // properties: name, type, flags
      95,   86, 0x00095009,
     122,  105, 0x0009510b,
     135,  105, 0x0009510b,
     154,  146, 0x0a095001,

       0        // eod
};

static const char qt_meta_stringdata_QtStateMachine[] = {
    "QtStateMachine\0\0started()\0stopped()\0"
    "finished()\0start()\0stop()\0_q_start()\0"
    "_q_process()\0QtState*\0rootState\0"
    "QtAbstractState*\0initialState\0errorState\0"
    "QString\0errorString\0"
};

const QMetaObject QtStateMachine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtStateMachine,
      qt_meta_data_QtStateMachine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtStateMachine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtStateMachine))
        return static_cast<void*>(const_cast< QtStateMachine*>(this));
    return QObject::qt_metacast(_clname);
}

int QtStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: started(); break;
        case 1: stopped(); break;
        case 2: finished(); break;
        case 3: start(); break;
        case 4: stop(); break;
        case 5: d_func()->_q_start(); break;
        case 6: d_func()->_q_process(); break;
        default: ;
        }
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QtState**>(_v) = rootState(); break;
        case 1: *reinterpret_cast< QtAbstractState**>(_v) = initialState(); break;
        case 2: *reinterpret_cast< QtAbstractState**>(_v) = errorState(); break;
        case 3: *reinterpret_cast< QString*>(_v) = errorString(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setInitialState(*reinterpret_cast< QtAbstractState**>(_v)); break;
        case 2: setErrorState(*reinterpret_cast< QtAbstractState**>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtStateMachine::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QtStateMachine::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QtStateMachine::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
