/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canvas_t {
    const uint offsetsAndSize[32];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Canvas_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 6), // "Canvas"
QT_MOC_LITERAL(7, 11), // "zoomRequest"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 1), // "i"
QT_MOC_LITERAL(22, 13), // "scrollRequest"
QT_MOC_LITERAL(36, 1), // "j"
QT_MOC_LITERAL(38, 8), // "newShape"
QT_MOC_LITERAL(47, 16), // "selectionChanged"
QT_MOC_LITERAL(64, 10), // "shapeMoved"
QT_MOC_LITERAL(75, 14), // "drawingPolygon"
QT_MOC_LITERAL(90, 9), // "hideRRect"
QT_MOC_LITERAL(100, 9), // "hideNRect"
QT_MOC_LITERAL(110, 6), // "status"
QT_MOC_LITERAL(117, 3), // "str"
QT_MOC_LITERAL(121, 10), // "cancelDraw"
QT_MOC_LITERAL(132, 10) // "toggleEdit"

    },
    "Canvas\0zoomRequest\0\0i\0scrollRequest\0"
    "j\0newShape\0selectionChanged\0shapeMoved\0"
    "drawingPolygon\0hideRRect\0hideNRect\0"
    "status\0str\0cancelDraw\0toggleEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    2,   83,    2, 0x06,    3 /* Public */,
       6,    1,   88,    2, 0x06,    6 /* Public */,
       7,    1,   91,    2, 0x06,    8 /* Public */,
       8,    0,   94,    2, 0x06,   10 /* Public */,
       9,    1,   95,    2, 0x06,   11 /* Public */,
      10,    1,   98,    2, 0x06,   13 /* Public */,
      11,    1,  101,    2, 0x06,   15 /* Public */,
      12,    1,  104,    2, 0x06,   17 /* Public */,
      14,    0,  107,    2, 0x06,   19 /* Public */,
      15,    1,  108,    2, 0x06,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canvas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->zoomRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->scrollRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->newShape((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->selectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->shapeMoved(); break;
        case 5: _t->drawingPolygon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->hideRRect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->hideNRect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->cancelDraw(); break;
        case 10: _t->toggleEdit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Canvas::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::zoomRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::scrollRequest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::newShape)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::selectionChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::shapeMoved)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::drawingPolygon)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::hideRRect)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::hideNRect)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::status)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Canvas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::cancelDraw)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Canvas::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::toggleEdit)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject Canvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Canvas.offsetsAndSize,
    qt_meta_data_Canvas,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Canvas_t
, QtPrivate::TypeAndForceComplete<Canvas, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>



>,
    nullptr
} };


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Canvas::zoomRequest(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Canvas::scrollRequest(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Canvas::newShape(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Canvas::selectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Canvas::shapeMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Canvas::drawingPolygon(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Canvas::hideRRect(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Canvas::hideNRect(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Canvas::status(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Canvas::cancelDraw()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Canvas::toggleEdit(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
