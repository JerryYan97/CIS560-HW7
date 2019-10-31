/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[519];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "slot_extrudeFace"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "i"
QT_MOC_LITERAL(4, 31, 24), // "slot_addMeshToListWidget"
QT_MOC_LITERAL(5, 56, 5), // "Mesh&"
QT_MOC_LITERAL(6, 62, 5), // "iMesh"
QT_MOC_LITERAL(7, 68, 25), // "slot_freeVerticesPinboxes"
QT_MOC_LITERAL(8, 94, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 111, 22), // "slot_freeFacesPinboxes"
QT_MOC_LITERAL(10, 134, 22), // "slot_slientAllPinboxes"
QT_MOC_LITERAL(11, 157, 25), // "slot_VertexPositionXValue"
QT_MOC_LITERAL(12, 183, 25), // "slot_VertexPositionYValue"
QT_MOC_LITERAL(13, 209, 25), // "slot_VertexPositionZValue"
QT_MOC_LITERAL(14, 235, 22), // "slot_FaceColorRedValue"
QT_MOC_LITERAL(15, 258, 24), // "slot_FaceColorGreenValue"
QT_MOC_LITERAL(16, 283, 23), // "slot_FaceColorBlueValue"
QT_MOC_LITERAL(17, 307, 20), // "slot_highlightVertex"
QT_MOC_LITERAL(18, 328, 18), // "slot_highlightFace"
QT_MOC_LITERAL(19, 347, 22), // "slot_highlightHalfEdge"
QT_MOC_LITERAL(20, 370, 18), // "slot_splitCubeEdge"
QT_MOC_LITERAL(21, 389, 24), // "slot_triangulateCubeFace"
QT_MOC_LITERAL(22, 414, 15), // "slot_smoothMesh"
QT_MOC_LITERAL(23, 430, 29), // "on_actionLoad_Scene_triggered"
QT_MOC_LITERAL(24, 460, 34), // "on_actionCamera_Controls_trig..."
QT_MOC_LITERAL(25, 495, 23) // "on_actionQuit_triggered"

    },
    "MainWindow\0slot_extrudeFace\0\0i\0"
    "slot_addMeshToListWidget\0Mesh&\0iMesh\0"
    "slot_freeVerticesPinboxes\0QListWidgetItem*\0"
    "slot_freeFacesPinboxes\0slot_slientAllPinboxes\0"
    "slot_VertexPositionXValue\0"
    "slot_VertexPositionYValue\0"
    "slot_VertexPositionZValue\0"
    "slot_FaceColorRedValue\0slot_FaceColorGreenValue\0"
    "slot_FaceColorBlueValue\0slot_highlightVertex\0"
    "slot_highlightFace\0slot_highlightHalfEdge\0"
    "slot_splitCubeEdge\0slot_triangulateCubeFace\0"
    "slot_smoothMesh\0on_actionLoad_Scene_triggered\0"
    "on_actionCamera_Controls_triggered\0"
    "on_actionQuit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x0a /* Public */,
       4,    1,  117,    2, 0x0a /* Public */,
       7,    1,  120,    2, 0x0a /* Public */,
       9,    1,  123,    2, 0x0a /* Public */,
      10,    1,  126,    2, 0x0a /* Public */,
      11,    1,  129,    2, 0x0a /* Public */,
      12,    1,  132,    2, 0x0a /* Public */,
      13,    1,  135,    2, 0x0a /* Public */,
      14,    1,  138,    2, 0x0a /* Public */,
      15,    1,  141,    2, 0x0a /* Public */,
      16,    1,  144,    2, 0x0a /* Public */,
      17,    1,  147,    2, 0x0a /* Public */,
      18,    1,  150,    2, 0x0a /* Public */,
      19,    1,  153,    2, 0x0a /* Public */,
      20,    1,  156,    2, 0x0a /* Public */,
      21,    1,  159,    2, 0x0a /* Public */,
      22,    1,  162,    2, 0x0a /* Public */,
      23,    1,  165,    2, 0x0a /* Public */,
      24,    0,  168,    2, 0x0a /* Public */,
      25,    0,  169,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_extrudeFace((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slot_addMeshToListWidget((*reinterpret_cast< Mesh(*)>(_a[1]))); break;
        case 2: _t->slot_freeVerticesPinboxes((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slot_freeFacesPinboxes((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->slot_slientAllPinboxes((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->slot_VertexPositionXValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slot_VertexPositionYValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->slot_VertexPositionZValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->slot_FaceColorRedValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->slot_FaceColorGreenValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->slot_FaceColorBlueValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->slot_highlightVertex((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->slot_highlightFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: _t->slot_highlightHalfEdge((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->slot_splitCubeEdge((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->slot_triangulateCubeFace((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->slot_smoothMesh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_actionLoad_Scene_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_actionCamera_Controls_triggered(); break;
        case 19: _t->on_actionQuit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
