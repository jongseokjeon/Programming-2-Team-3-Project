/****************************************************************************
** Meta object code from reading C++ file 'playwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/playwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayWindow_t {
    const uint offsetsAndSize[16];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PlayWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PlayWindow_t qt_meta_stringdata_PlayWindow = {
    {
QT_MOC_LITERAL(0, 10), // "PlayWindow"
QT_MOC_LITERAL(11, 8), // "loadList"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 12), // "computerTurn"
QT_MOC_LITERAL(34, 22), // "on_twistButton_clicked"
QT_MOC_LITERAL(57, 22), // "on_stickButton_clicked"
QT_MOC_LITERAL(80, 26), // "on_playagainButton_clicked"
QT_MOC_LITERAL(107, 23) // "on_actionQuit_triggered"

    },
    "PlayWindow\0loadList\0\0computerTurn\0"
    "on_twistButton_clicked\0on_stickButton_clicked\0"
    "on_playagainButton_clicked\0"
    "on_actionQuit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadList(); break;
        case 1: _t->computerTurn(); break;
        case 2: _t->on_twistButton_clicked(); break;
        case 3: _t->on_stickButton_clicked(); break;
        case 4: _t->on_playagainButton_clicked(); break;
        case 5: _t->on_actionQuit_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject PlayWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_PlayWindow.offsetsAndSize,
    qt_meta_data_PlayWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PlayWindow_t
, QtPrivate::TypeAndForceComplete<PlayWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PlayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PlayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
