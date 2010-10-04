/****************************************************************************
** Meta object code from reading C++ file 'qscriptedstatemachine.h'
**
** Created: Fri Aug 13 10:08:34 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qscriptedstatemachine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qscriptedstatemachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtScriptedTransition[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      29,   21, 0x0a095103,
      49,   21, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_QtScriptedTransition[] = {
    "QtScriptedTransition\0QString\0"
    "conditionExpression\0eventPrefix\0"
};

const QMetaObject QtScriptedTransition::staticMetaObject = {
    { &QtTransition::staticMetaObject, qt_meta_stringdata_QtScriptedTransition,
      qt_meta_data_QtScriptedTransition, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtScriptedTransition::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtScriptedTransition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtScriptedTransition::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtScriptedTransition))
        return static_cast<void*>(const_cast< QtScriptedTransition*>(this));
    return QtTransition::qt_metacast(_clname);
}

int QtScriptedTransition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtTransition::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = conditionExpression(); break;
        case 1: *reinterpret_cast< QString*>(_v) = eventPrefix(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setConditionExpression(*reinterpret_cast< QString*>(_v)); break;
        case 1: setEventPrefix(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
static const uint qt_meta_data_QtSsmInvoker[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      25,   13,   13,   13, 0x0a,
      40,   34,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QtSsmInvoker[] = {
    "QtSsmInvoker\0\0activate()\0cancel()\0"
    "event\0postParentEvent(QString)\0"
};

const QMetaObject QtSsmInvoker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtSsmInvoker,
      qt_meta_data_QtSsmInvoker, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtSsmInvoker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtSsmInvoker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtSsmInvoker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtSsmInvoker))
        return static_cast<void*>(const_cast< QtSsmInvoker*>(this));
    return QObject::qt_metacast(_clname);
}

int QtSsmInvoker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activate(); break;
        case 1: cancel(); break;
        case 2: postParentEvent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_QtScriptedStateMachine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   23,   23,   23, 0x0a,
      72,   23,   23,   23, 0x0a,
      95,   23,   23,   23, 0x08,
     113,   23,   23,   23, 0x08,

 // properties: name, type, flags
     138,  133, 0x11095103,

       0        // eod
};

static const char qt_meta_stringdata_QtScriptedStateMachine[] = {
    "QtScriptedStateMachine\0\0eventTriggered(QString)\0"
    "postNamedEvent(QString)\0executeScript(QString)\0"
    "registerSession()\0unregisterSession()\0"
    "QUrl\0baseUrl\0"
};

const QMetaObject QtScriptedStateMachine::staticMetaObject = {
    { &QtStateMachine::staticMetaObject, qt_meta_stringdata_QtScriptedStateMachine,
      qt_meta_data_QtScriptedStateMachine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtScriptedStateMachine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtScriptedStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtScriptedStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtScriptedStateMachine))
        return static_cast<void*>(const_cast< QtScriptedStateMachine*>(this));
    return QtStateMachine::qt_metacast(_clname);
}

int QtScriptedStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: eventTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: postNamedEvent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: executeScript((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: registerSession(); break;
        case 4: unregisterSession(); break;
        default: ;
        }
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QUrl*>(_v) = baseUrl(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setBaseUrl(*reinterpret_cast< QUrl*>(_v)); break;
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

// SIGNAL 0
void QtScriptedStateMachine::eventTriggered(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
