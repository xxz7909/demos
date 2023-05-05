/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tcp_server_2/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tcpserver_t {
    QByteArrayData data[21];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tcpserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tcpserver_t qt_meta_stringdata_Tcpserver = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Tcpserver"
QT_MOC_LITERAL(1, 10, 16), // "slotUpdateServer"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "msgType"
QT_MOC_LITERAL(4, 36, 20), // "on_btnListen_clicked"
QT_MOC_LITERAL(5, 57, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(6, 76, 22), // "on_btnClearMsg_clicked"
QT_MOC_LITERAL(7, 99, 22), // "on_btnSendFile_clicked"
QT_MOC_LITERAL(8, 122, 24), // "on_btnSelectFile_clicked"
QT_MOC_LITERAL(9, 147, 8), // "showinfo"
QT_MOC_LITERAL(10, 156, 5), // "index"
QT_MOC_LITERAL(11, 162, 7), // "addlist"
QT_MOC_LITERAL(12, 170, 2), // "ip"
QT_MOC_LITERAL(13, 173, 4), // "port"
QT_MOC_LITERAL(14, 178, 10), // "removelist"
QT_MOC_LITERAL(15, 189, 10), // "sortHeader"
QT_MOC_LITERAL(16, 200, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(17, 226, 15), // "soltupdateshell"
QT_MOC_LITERAL(18, 242, 3), // "str"
QT_MOC_LITERAL(19, 246, 31), // "on_pushButton_getscreen_clicked"
QT_MOC_LITERAL(20, 278, 16) // "soltupdatescreen"

    },
    "Tcpserver\0slotUpdateServer\0\0msgType\0"
    "on_btnListen_clicked\0on_btnSend_clicked\0"
    "on_btnClearMsg_clicked\0on_btnSendFile_clicked\0"
    "on_btnSelectFile_clicked\0showinfo\0"
    "index\0addlist\0ip\0port\0removelist\0"
    "sortHeader\0on_lineEdit_returnPressed\0"
    "soltupdateshell\0str\0on_pushButton_getscreen_clicked\0"
    "soltupdatescreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcpserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x09 /* Protected */,
       4,    0,   89,    2, 0x08 /* Private */,
       5,    0,   90,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    1,   94,    2, 0x08 /* Private */,
      11,    2,   97,    2, 0x08 /* Private */,
      14,    2,  102,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    1,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   12,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void Tcpserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tcpserver *_t = static_cast<Tcpserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotUpdateServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_btnListen_clicked(); break;
        case 2: _t->on_btnSend_clicked(); break;
        case 3: _t->on_btnClearMsg_clicked(); break;
        case 4: _t->on_btnSendFile_clicked(); break;
        case 5: _t->on_btnSelectFile_clicked(); break;
        case 6: _t->showinfo((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->addlist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 8: _t->removelist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 9: _t->sortHeader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_returnPressed(); break;
        case 11: _t->soltupdateshell((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_getscreen_clicked(); break;
        case 13: _t->soltupdatescreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Tcpserver::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tcpserver.data,
      qt_meta_data_Tcpserver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tcpserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcpserver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tcpserver.stringdata0))
        return static_cast<void*>(const_cast< Tcpserver*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tcpserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
