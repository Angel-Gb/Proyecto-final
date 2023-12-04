/****************************************************************************
** Meta object code from reading C++ file 'personajes.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Proyecto_final/personajes.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personajes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPersonajesENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPersonajesENDCLASS = QtMocHelpers::stringData(
    "Personajes",
    "personajeEliminado",
    "",
    "Personajes*",
    "personaje",
    "Actualizacion",
    "salto",
    "verificarColisionConProyectil"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPersonajesENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[10];
    char stringdata5[14];
    char stringdata6[6];
    char stringdata7[30];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPersonajesENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPersonajesENDCLASS_t qt_meta_stringdata_CLASSPersonajesENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Personajes"
        QT_MOC_LITERAL(11, 18),  // "personajeEliminado"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 11),  // "Personajes*"
        QT_MOC_LITERAL(43, 9),  // "personaje"
        QT_MOC_LITERAL(53, 13),  // "Actualizacion"
        QT_MOC_LITERAL(67, 5),  // "salto"
        QT_MOC_LITERAL(73, 29)   // "verificarColisionConProyectil"
    },
    "Personajes",
    "personajeEliminado",
    "",
    "Personajes*",
    "personaje",
    "Actualizacion",
    "salto",
    "verificarColisionConProyectil"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPersonajesENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   41,    2, 0x0a,    3 /* Public */,
       6,    0,   42,    2, 0x0a,    4 /* Public */,
       7,    0,   43,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Personajes::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPersonajesENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPersonajesENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPersonajesENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Personajes, std::true_type>,
        // method 'personajeEliminado'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Personajes *, std::false_type>,
        // method 'Actualizacion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'salto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verificarColisionConProyectil'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Personajes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Personajes *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->personajeEliminado((*reinterpret_cast< std::add_pointer_t<Personajes*>>(_a[1]))); break;
        case 1: _t->Actualizacion(); break;
        case 2: _t->salto(); break;
        case 3: _t->verificarColisionConProyectil(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Personajes* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Personajes::*)(Personajes * );
            if (_t _q_method = &Personajes::personajeEliminado; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Personajes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Personajes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPersonajesENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Personajes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Personajes::personajeEliminado(Personajes * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
