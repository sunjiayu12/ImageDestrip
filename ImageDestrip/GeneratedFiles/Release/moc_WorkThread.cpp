/****************************************************************************
** Meta object code from reading C++ file 'WorkThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorkThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkThread_t {
    QByteArrayData data[11];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkThread_t qt_meta_stringdata_WorkThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WorkThread"
QT_MOC_LITERAL(1, 11, 13), // "sendImageSize"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "sendImagePatches"
QT_MOC_LITERAL(4, 43, 17), // "sendDestripSignal"
QT_MOC_LITERAL(5, 61, 17), // "sendDestripDetail"
QT_MOC_LITERAL(6, 79, 17), // "sendWritingSignal"
QT_MOC_LITERAL(7, 97, 16), // "sendFinishSignal"
QT_MOC_LITERAL(8, 114, 15), // "sendMulSplitMsg"
QT_MOC_LITERAL(9, 130, 14), // "sendMulBandMsg"
QT_MOC_LITERAL(10, 145, 10) // "sendFFTMsg"

    },
    "WorkThread\0sendImageSize\0\0sendImagePatches\0"
    "sendDestripSignal\0sendDestripDetail\0"
    "sendWritingSignal\0sendFinishSignal\0"
    "sendMulSplitMsg\0sendMulBandMsg\0"
    "sendFFTMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkThread[] = {

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
       1,    2,   59,    2, 0x06 /* Public */,
       3,    2,   64,    2, 0x06 /* Public */,
       4,    0,   69,    2, 0x06 /* Public */,
       5,    2,   70,    2, 0x06 /* Public */,
       6,    0,   75,    2, 0x06 /* Public */,
       7,    0,   76,    2, 0x06 /* Public */,
       8,    0,   77,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void WorkThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkThread *_t = static_cast<WorkThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImageSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendImagePatches((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendDestripSignal(); break;
        case 3: _t->sendDestripDetail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->sendWritingSignal(); break;
        case 5: _t->sendFinishSignal(); break;
        case 6: _t->sendMulSplitMsg(); break;
        case 7: _t->sendMulBandMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sendFFTMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WorkThread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendImageSize)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendImagePatches)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendDestripSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendDestripDetail)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendWritingSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendFinishSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendMulSplitMsg)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendMulBandMsg)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::sendFFTMsg)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject WorkThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WorkThread.data,
      qt_meta_data_WorkThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WorkThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WorkThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void WorkThread::sendImageSize(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkThread::sendImagePatches(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorkThread::sendDestripSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WorkThread::sendDestripDetail(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WorkThread::sendWritingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WorkThread::sendFinishSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WorkThread::sendMulSplitMsg()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void WorkThread::sendMulBandMsg(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void WorkThread::sendFFTMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
