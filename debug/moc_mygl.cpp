/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[17];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 8), // "SendMesh"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "Mesh&"
QT_MOC_LITERAL(4, 21, 5), // "oMesh"
QT_MOC_LITERAL(5, 27, 14), // "SendNextHEOfHE"
QT_MOC_LITERAL(6, 42, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 59, 2), // "he"
QT_MOC_LITERAL(8, 62, 13), // "SendSYMHEOfHE"
QT_MOC_LITERAL(9, 76, 12), // "SendFaceOfHE"
QT_MOC_LITERAL(10, 89, 1), // "f"
QT_MOC_LITERAL(11, 91, 14), // "SendVertexOfHE"
QT_MOC_LITERAL(12, 106, 1), // "v"
QT_MOC_LITERAL(13, 108, 14), // "SendHEOfVertex"
QT_MOC_LITERAL(14, 123, 12), // "SendHEOfFace"
QT_MOC_LITERAL(15, 136, 13), // "HighlightVert"
QT_MOC_LITERAL(16, 150, 13) // "HighlightFace"

    },
    "MyGL\0SendMesh\0\0Mesh&\0oMesh\0SendNextHEOfHE\0"
    "QListWidgetItem*\0he\0SendSYMHEOfHE\0"
    "SendFaceOfHE\0f\0SendVertexOfHE\0v\0"
    "SendHEOfVertex\0SendHEOfFace\0HighlightVert\0"
    "HighlightFace"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
       9,    1,   68,    2, 0x06 /* Public */,
      11,    1,   71,    2, 0x06 /* Public */,
      13,    1,   74,    2, 0x06 /* Public */,
      14,    1,   77,    2, 0x06 /* Public */,
      15,    1,   80,    2, 0x06 /* Public */,
      16,    1,   83,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,   10,
    QMetaType::Void, 0x80000000 | 6,   12,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,   12,
    QMetaType::Void, 0x80000000 | 6,   10,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendMesh((*reinterpret_cast< Mesh(*)>(_a[1]))); break;
        case 1: _t->SendNextHEOfHE((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->SendSYMHEOfHE((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->SendFaceOfHE((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->SendVertexOfHE((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->SendHEOfVertex((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->SendHEOfFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->HighlightVert((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->HighlightFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(Mesh & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendMesh)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendNextHEOfHE)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendSYMHEOfHE)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendFaceOfHE)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendVertexOfHE)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendHEOfVertex)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::SendHEOfFace)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::HighlightVert)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::HighlightFace)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &OpenGLContext::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata0))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return OpenGLContext::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OpenGLContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyGL::SendMesh(Mesh & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::SendNextHEOfHE(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::SendSYMHEOfHE(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::SendFaceOfHE(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGL::SendVertexOfHE(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGL::SendHEOfVertex(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGL::SendHEOfFace(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGL::HighlightVert(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGL::HighlightFace(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
