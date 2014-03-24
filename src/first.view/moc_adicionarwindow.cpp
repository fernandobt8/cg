/****************************************************************************
** Meta object code from reading C++ file 'adicionarwindow.h'
**
** Created: Sun Mar 23 20:49:34 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AdicionarWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adicionarwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdicionarWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,
      56,   16,   16,   16, 0x08,
      78,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdicionarWindow[] = {
    "AdicionarWindow\0\0index\0"
    "on_tabWindow_currentChanged(int)\0"
    "on_okButton_clicked()\0on_cancelarButton_clicked()\0"
};

void AdicionarWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdicionarWindow *_t = static_cast<AdicionarWindow *>(_o);
        switch (_id) {
        case 0: _t->on_tabWindow_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->on_cancelarButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdicionarWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdicionarWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdicionarWindow,
      qt_meta_data_AdicionarWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdicionarWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdicionarWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdicionarWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdicionarWindow))
        return static_cast<void*>(const_cast< AdicionarWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AdicionarWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
