/****************************************************************************
** Meta object code from reading C++ file 'tcpclientsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tcp_server_2/tcpclientsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclientsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClientSocket_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClientSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClientSocket_t qt_meta_stringdata_TcpClientSocket = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpClientSocket"
QT_MOC_LITERAL(1, 16, 12), // "updateServer"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "msgType"
QT_MOC_LITERAL(4, 38, 18), // "clientDisconnected"
QT_MOC_LITERAL(5, 57, 11), // "updateshell"
QT_MOC_LITERAL(6, 69, 11), // "updatescree"
QT_MOC_LITERAL(7, 81, 11), // "receiveData"
QT_MOC_LITERAL(8, 93, 22) // "slotClientDisconnected"

    },
    "TcpClientSocket\0updateServer\0\0msgType\0"
    "clientDisconnected\0updateshell\0"
    "updatescree\0receiveData\0slotClientDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClientSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       4,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x09 /* Protected */,
       8,    0,   59,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpClientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpClientSocket *_t = static_cast<TcpClientSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateshell((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updatescree((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->receiveData(); break;
        case 5: _t->slotClientDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpClientSocket::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClientSocket::updateServer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpClientSocket::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClientSocket::clientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpClientSocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClientSocket::updateshell)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpClientSocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpClientSocket::updatescree)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject TcpClientSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpClientSocket.data,
      qt_meta_data_TcpClientSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpClientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClientSocket.stringdata0))
        return static_cast<void*>(const_cast< TcpClientSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpClientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TcpClientSocket::updateServer(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpClientSocket::clientDisconnected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpClientSocket::updateshell(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpClientSocket::updatescree(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
