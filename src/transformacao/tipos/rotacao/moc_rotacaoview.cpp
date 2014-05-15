/****************************************************************************
** Meta object code from reading C++ file 'RotacaoView.h'
**
** Created: Thu May 15 19:43:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RotacaoView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RotacaoView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RotacaoView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x0a,
      50,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RotacaoView[] = {
    "RotacaoView\0\0checked\0on_pontoButton_toggled(bool)\0"
    "on_adicionarButton_clicked()\0"
};

void RotacaoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RotacaoView *_t = static_cast<RotacaoView *>(_o);
        switch (_id) {
        case 0: _t->on_pontoButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_adicionarButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RotacaoView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RotacaoView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RotacaoView,
      qt_meta_data_RotacaoView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RotacaoView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RotacaoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RotacaoView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RotacaoView))
        return static_cast<void*>(const_cast< RotacaoView*>(this));
    return QWidget::qt_metacast(_clname);
}

int RotacaoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
