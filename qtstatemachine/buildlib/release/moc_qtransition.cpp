/****************************************************************************
** Meta object code from reading C++ file 'qtransition.h'
**
** Created: Fri Aug 13 10:08:32 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qtransition.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtransition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtTransition[] = {

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

static const char qt_meta_stringdata_QtTransition[] = {
    "QtTransition\0"
};

const QMetaObject QtTransition::staticMetaObject = {
    { &QtAbstractTransition::staticMetaObject, qt_meta_stringdata_QtTransition,
      qt_meta_data_QtTransition, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtTransition::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtTransition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtTransition::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtTransition))
        return static_cast<void*>(const_cast< QtTransition*>(this));
    return QtAbstractTransition::qt_metacast(_clname);
}

int QtTransition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAbstractTransition::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
