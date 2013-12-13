/****************************************************************************
** Meta object code from reading C++ file 'wmansied.h'
**
** Created: Wed Apr 18 20:07:33 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wmansied.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wmansied.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WMAnsiEd[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,
      36,    9,    9,    9, 0x09,
      62,    9,    9,    9, 0x09,
      90,    9,    9,    9, 0x09,
     105,    9,    9,    9, 0x09,
     121,    9,    9,    9, 0x09,
     136,    9,    9,    9, 0x09,
     152,    9,    9,    9, 0x09,
     163,    9,    9,    9, 0x09,
     178,    9,    9,    9, 0x09,
     190,    9,    9,    9, 0x09,
     202,    9,    9,    9, 0x09,
     218,    9,    9,    9, 0x09,
     233,    9,    9,    9, 0x09,
     246,    9,    9,    9, 0x09,
     261,    9,    9,    9, 0x09,
     275,    9,    9,    9, 0x09,
     289,    9,    9,    9, 0x09,
     300,    9,    9,    9, 0x09,
     311,    9,    9,    9, 0x09,
     321,    9,    9,    9, 0x09,
     332,    9,    9,    9, 0x09,
     345,    9,    9,    9, 0x09,
     359,    9,    9,    9, 0x09,
     374,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_WMAnsiEd[] = {
    "WMAnsiEd\0\0slotComboBGActivated(int)\0"
    "slotComboFGActivated(int)\0"
    "slotComboCHARActivated(int)\0slotSaveAnsi()\0"
    "slotSaveAscii()\0slotLoadAnsi()\0"
    "slotLoadAscii()\0slotQuit()\0slotWidth(int)\0"
    "slotClear()\0slotAbout()\0slotMoveRight()\0"
    "slotMoveLeft()\0slotMoveUp()\0slotMoveDown()\0"
    "slotHCenter()\0slotVCenter()\0slotPlot()\0"
    "slotLine()\0slotBox()\0slotFBox()\0"
    "slotCircle()\0slotFCircle()\0slotScribble()\0"
    "slotDScribble()\0"
};

void WMAnsiEd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WMAnsiEd *_t = static_cast<WMAnsiEd *>(_o);
        switch (_id) {
        case 0: _t->slotComboBGActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotComboFGActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotComboCHARActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotSaveAnsi(); break;
        case 4: _t->slotSaveAscii(); break;
        case 5: _t->slotLoadAnsi(); break;
        case 6: _t->slotLoadAscii(); break;
        case 7: _t->slotQuit(); break;
        case 8: _t->slotWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotClear(); break;
        case 10: _t->slotAbout(); break;
        case 11: _t->slotMoveRight(); break;
        case 12: _t->slotMoveLeft(); break;
        case 13: _t->slotMoveUp(); break;
        case 14: _t->slotMoveDown(); break;
        case 15: _t->slotHCenter(); break;
        case 16: _t->slotVCenter(); break;
        case 17: _t->slotPlot(); break;
        case 18: _t->slotLine(); break;
        case 19: _t->slotBox(); break;
        case 20: _t->slotFBox(); break;
        case 21: _t->slotCircle(); break;
        case 22: _t->slotFCircle(); break;
        case 23: _t->slotScribble(); break;
        case 24: _t->slotDScribble(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WMAnsiEd::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WMAnsiEd::staticMetaObject = {
    { &Q3MainWindow::staticMetaObject, qt_meta_stringdata_WMAnsiEd,
      qt_meta_data_WMAnsiEd, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WMAnsiEd::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WMAnsiEd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WMAnsiEd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WMAnsiEd))
        return static_cast<void*>(const_cast< WMAnsiEd*>(this));
    return Q3MainWindow::qt_metacast(_clname);
}

int WMAnsiEd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
