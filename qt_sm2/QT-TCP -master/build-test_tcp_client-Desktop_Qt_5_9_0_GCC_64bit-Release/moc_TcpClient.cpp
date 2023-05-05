/****************************************************************************
** Meta object code from reading C++ file 'TcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test_tcp_client/TcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClient_t {
    QByteArrayData data[16];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpClient"
QT_MOC_LITERAL(1, 10, 9), // "newClient"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "updataProgress"
QT_MOC_LITERAL(4, 36, 13), // "newClientInfo"
QT_MOC_LITERAL(5, 50, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(6, 72, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(7, 91, 16), // "socket_Read_Data"
QT_MOC_LITERAL(8, 108, 19), // "socket_Disconnected"
QT_MOC_LITERAL(9, 128, 24), // "on_btnSelectFile_clicked"
QT_MOC_LITERAL(10, 153, 22), // "on_btnSendFile_clicked"
QT_MOC_LITERAL(11, 176, 11), // "sendallinfo"
QT_MOC_LITERAL(12, 188, 26), // "readBashStandardOutputInfo"
QT_MOC_LITERAL(13, 215, 25), // "readBashStandardErrorInfo"
QT_MOC_LITERAL(14, 241, 10), // "sendscreen"
QT_MOC_LITERAL(15, 252, 5) // "check"

    },
    "TcpClient\0newClient\0\0updataProgress\0"
    "newClientInfo\0on_btnConnect_clicked\0"
    "on_btnSend_clicked\0socket_Read_Data\0"
    "socket_Disconnected\0on_btnSelectFile_clicked\0"
    "on_btnSendFile_clicked\0sendallinfo\0"
    "readBashStandardOutputInfo\0"
    "readBashStandardErrorInfo\0sendscreen\0"
    "check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    3,   85,    2, 0x06 /* Public */,
       4,    3,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   99,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpClient *_t = static_cast<TcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newClient(); break;
        case 1: _t->updataProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->newClientInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->on_btnConnect_clicked(); break;
        case 4: _t->on_btnSend_clicked(); break;
        case 5: _t->socket_Read_Data(); break;
        case 6: _t->socket_Disconnected(); break;
        case 7: _t->on_btnSelectFile_clicked(); break;
        case 8: _t->on_btnSendFile_clicked(); break;
        case 9: _t->sendallinfo(); break;
        case 10: _t->readBashStandardOutputInfo(); break;
        case 11: _t->readBashStandardErrorInfo(); break;
        case 12: _t->sendscreen(); break;
        case 13: _t->check(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClient::newClient)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpClient::*_t)(qint64 , qint64 , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClient::updataProgress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpClient::*_t)(QString , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClient::newClientInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TcpClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TcpClient.data,
      qt_meta_data_TcpClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(const_cast< TcpClient*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TcpClient::newClient()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpClient::updataProgress(qint64 _t1, qint64 _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpClient::newClientInfo(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
