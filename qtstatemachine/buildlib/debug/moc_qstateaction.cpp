/****************************************************************************
** Meta object code from reading C++ file 'qstateaction.h'
**
** Created: Fri Aug 13 10:08:01 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qstateaction.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstateaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtStateAction[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QtStateAction[] = {
    "QtStateAction\0"
};

const QMetaObject QtStateAction::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtStateAction,
      qt_meta_data_QtStateAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtStateAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtStateAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtStateAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtStateAction))
        return static_cast<void*>(const_cast< QtStateAction*>(this));
    return QObject::qt_metacast(_clname);
}

int QtStateAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QtStateInvokeMethodAction[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      35,   26, 0x88095003,
      53,   42, 0x0c095103,
      77,   64, 0x09095103,

       0        // eod
};

static const char qt_meta_stringdata_QtStateInvokeMethodAction[] = {
    "QtStateInvokeMethodAction\0QObject*\0"
    "target\0QByteArray\0methodName\0QVariantList\0"
    "arguments\0"
};

const QMetaObject QtStateInvokeMethodAction::staticMetaObject = {
    { &QtStateAction::staticMetaObject, qt_meta_stringdata_QtStateInvokeMethodAction,
      qt_meta_data_QtStateInvokeMethodAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtStateInvokeMethodAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtStateInvokeMethodAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtStateInvokeMethodAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtStateInvokeMethodAction))
        return static_cast<void*>(const_cast< QtStateInvokeMethodAction*>(this));
    return QtStateAction::qt_metacast(_clname);
}

int QtStateInvokeMethodAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtStateAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = targetObject(); break;
        case 1: *reinterpret_cast< QByteArray*>(_v) = methodName(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = arguments(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTargetObject(*reinterpret_cast< QObject**>(_v)); break;
        case 1: setMethodName(*reinterpret_cast< QByteArray*>(_v)); break;
        case 2: setArguments(*reinterpret_cast< QVariantList*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
