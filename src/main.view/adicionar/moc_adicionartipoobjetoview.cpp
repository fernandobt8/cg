/****************************************************************************
** Meta object code from reading C++ file 'AdicionarTipoObjetoView.h'
**
** Created: Thu Mar 27 21:43:48 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AdicionarTipoObjetoView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdicionarTipoObjetoView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdicionarTipoObjetoView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   25,   24,   24, 0x0a,
      64,   24,   24,   24, 0x0a,
      86,   24,   24,   24, 0x0a,
     114,   24,   24,   24, 0x0a,
     145,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AdicionarTipoObjetoView[] = {
    "AdicionarTipoObjetoView\0\0index\0"
    "on_tabWindow_currentChanged(int)\0"
    "on_okButton_clicked()\0on_cancelarButton_clicked()\0"
    "on_removerCoordenada_clicked()\0"
    "on_adicionarCoordenada_clicked()\0"
};

void AdicionarTipoObjetoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdicionarTipoObjetoView *_t = static_cast<AdicionarTipoObjetoView *>(_o);
        switch (_id) {
        case 0: _t->on_tabWindow_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->on_cancelarButton_clicked(); break;
        case 3: _t->on_removerCoordenada_clicked(); break;
        case 4: _t->on_adicionarCoordenada_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdicionarTipoObjetoView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdicionarTipoObjetoView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdicionarTipoObjetoView,
      qt_meta_data_AdicionarTipoObjetoView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdicionarTipoObjetoView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdicionarTipoObjetoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdicionarTipoObjetoView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdicionarTipoObjetoView))
        return static_cast<void*>(const_cast< AdicionarTipoObjetoView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AdicionarTipoObjetoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
