#ifndef ANY_H
#define ANY_H

#include <stdlib.h>

typedef struct any any;

enum _any_type {
    TYPE_CHAR,
    TYPE_UCHAR,
    TYPE_INT,
    TYPE_UINT,
    TYPE_SHORT,
    TYPE_USHORT,
    TYPE_LONG,
    TYPE_ULONG,
    TYPE_LLONG,
    TYPE_ULLONG,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_LDOUBLE,
    TYPE_POINTER
};

struct any {
    enum _any_type type;
    union {
        char _char;
        unsigned char _uchar;
        int _int;
        unsigned int _uint;
        short _short;
        unsigned short _ushort;
        long _long;
        unsigned long _ulong;
        long long _llong;
        unsigned long long _ullong;
        float _float;
        double _double;
        long double _ldouble;
        void * _pointer;
    } data;
};

static inline char any_get_char(const any * _any) {
    return _any->data._char;
}

static inline unsigned char any_get_uchar(const any * _any) {
    return _any->data._uchar;
}

static inline int any_get_int(const any * _any) {
    return _any->data._int;
}

static inline unsigned int any_get_uint(const any * _any) {
    return _any->data._uint;
}

static inline short any_get_short(const any * _any) {
    return _any->data._short;
}

static inline unsigned short any_get_ushort(const any * _any) {
    return _any->data._ushort;
}

static inline long any_get_long(const any * _any) {
    return _any->data._long;
}

static inline unsigned long any_get_ulong(const any * _any) {
    return _any->data._ulong;
}

static inline long long any_get_llong(const any * _any) {
    return _any->data._llong;
}

static inline unsigned long long any_get_ullong(const any * _any) {
    return _any->data._ullong;
}

static inline float any_get_float(const any * _any) {
    return _any->data._float;
}

static inline double any_get_double(const any * _any) {
    return _any->data._double;
}

static inline long double any_get_ldouble(const any * _any) {
    return _any->data._ldouble;
}

static inline void * any_get_pointer(const any * _any) {
    return _any->data._pointer;
}

/*
#define any_get(A) (A->type == TYPE_CHAR ? A->data._char : \
(A->type == TYPE_UCHAR ? A->data._uchar : \
(A->type == TYPE_INT ? A->data._int : \
(A->type == TYPE_UINT ? A->data._uint : \
(A->type == TYPE_LONG ? A->data._long : \
(A->type == TYPE_ULONG ? A->data._ulong : \
(A->type == TYPE_LLONG ? A->data._llong : \
(A->type == TYPE_ULLONG ? A->data._ullong : \
(A->type == TYPE_FLOAT ? A->data._float : \
(A->type == TYPE_DOUBLE ? A->data._double : \
(A->type == TYPE_LDOUBLE ? A->data._ldouble : \
A->data._pointer)))))))))))
*/

static inline void any_set_char(any * _any, char _char) {
    _any->type = TYPE_CHAR;
    _any->data._char = _char;
}

static inline void any_set_uchar(any * _any, unsigned char _uchar) {
    _any->type = TYPE_UCHAR;
    _any->data._uchar = _uchar;
}

static inline void any_set_int(any * _any, int _int) {
    _any->type = TYPE_INT;
    _any->data._int = _int;
}

static inline void any_set_uint(any * _any, unsigned int _uint) {
    _any->type = TYPE_UINT;
    _any->data._uint = _uint;
}

static inline void any_set_short(any * _any, short _short) {
    _any->type = TYPE_SHORT;
    _any->data._uint = _short;
}

static inline void any_set_ushort(any * _any, unsigned short _ushort) {
    _any->type = TYPE_USHORT;
    _any->data._uint = _ushort;
}

static inline void any_set_long(any * _any, long _long) {
    _any->type = TYPE_LONG;
    _any->data._long = _long;
}

static inline void any_set_ulong(any * _any, unsigned long _ulong) {
    _any->type = TYPE_ULONG;
    _any->data._ulong = _ulong;
}

static inline void any_set_llong(any * _any, long long _llong) {
    _any->type = TYPE_LLONG;
    _any->data._llong = _llong;
}

static inline void any_set_ullong(any * _any, unsigned long long _ullong) {
    _any->type = TYPE_ULLONG;
    _any->data._ullong = _ullong;
}
/*
inline void any_set_int8(any * _any, int8_t _int8) {
    _any->data._int8 = _int8;
}

inline void any_set_uint8(any * _any, uint8_t _uint8) {
    _any->data._uint8 = _uint8;
}

inline void any_set_int16(any * _any, int16_t _int16) {
    _any->data._int16 = _int16;
}

inline void any_set_uint16(any * _any, uint16_t _uint16) {
    _any->data._uint16 = _uint16;
}

inline void any_set_int32(any * _any, int32_t _int32) {
    _any->data._int32 = _int32;
}

inline void any_set_uint32(any * _any, uint32_t _uint32) {
    _any->data._uint32 = _uint32;
}

inline void any_set_int64(any * _any, int64_t _int64) {
    _any->data._int64 = _int64;
}

inline void any_set_uint64(any * _any, uint64_t _uint64) {
    _any->data._uint64 = _uint64;
}
*/
static inline void any_set_float(any * _any, float _float) {
    _any->type = TYPE_FLOAT;
    _any->data._float = _float;
}

static inline void any_set_double(any * _any, double _double) {
    _any->type = TYPE_DOUBLE;
    _any->data._double = _double;
}

static inline void any_set_ldouble(any * _any, long double _ldouble) {
    _any->type = TYPE_LDOUBLE;
    _any->data._ldouble = _ldouble;
}

static inline void any_set_pointer(any * _any, void * _pointer) {
    _any->type = TYPE_POINTER;
    _any->data._pointer = _pointer;
}

static inline void any_get(const any * _any, void * val) {
    switch (_any->type) {
        case TYPE_CHAR:    *(char*)val = _any->data._char; break;
        case TYPE_UCHAR:   *(unsigned char*)val = _any->data._uchar; break;
        case TYPE_INT:     *(int*)val = _any->data._int; break;
        case TYPE_UINT:    *(unsigned int*)val = _any->data._uint; break;
        case TYPE_SHORT:   *(short*)val = _any->data._short; break;
        case TYPE_USHORT:  *(unsigned short*)val = _any->data._ushort; break;
        case TYPE_LONG:    *(long*)val = _any->data._long; break;
        case TYPE_ULONG:   *(unsigned long*)val = _any->data._ulong; break;
        case TYPE_LLONG:   *(long long*)val = _any->data._llong; break;
        case TYPE_ULLONG:  *(unsigned long long*)val = _any->data._ullong; break;
        case TYPE_FLOAT:   *(float*)val = _any->data._float; break;
        case TYPE_DOUBLE:  *(double*) val = _any->data._double; break;
        case TYPE_LDOUBLE: *(long double*)val = _any->data._ldouble; break;
        default:           *(void**)val = _any->data._pointer;
    }
}

static inline void * any_get_ref(const any * _any) {
    switch (_any->type) {
        case TYPE_CHAR:    return (void*)&_any->data._char;
        case TYPE_UCHAR:   return (void*)&_any->data._uchar;
        case TYPE_INT:     return (void*)&_any->data._int;
        case TYPE_UINT:    return (void*)&_any->data._uint;
        case TYPE_SHORT:   return (void*)&_any->data._short;
        case TYPE_USHORT:  return (void*)&_any->data._ushort;
        case TYPE_LONG:    return (void*)&_any->data._long;
        case TYPE_ULONG:   return (void*)&_any->data._ulong;
        case TYPE_LLONG:   return (void*)&_any->data._llong;
        case TYPE_ULLONG:  return (void*)&_any->data._ullong;
        case TYPE_FLOAT:   return (void*)&_any->data._float;
        case TYPE_DOUBLE:  return (void*)&_any->data._double;
        case TYPE_LDOUBLE: return (void*)&_any->data._ldouble;
        default:           return (void*)&_any->data._pointer;
    }
}

static inline size_t any_size(const any * _any) {
    switch (_any->type) {
        case TYPE_CHAR:    return sizeof(char);
        case TYPE_UCHAR:   return sizeof(unsigned char);
        case TYPE_INT:     return sizeof(int);
        case TYPE_UINT:    return sizeof(unsigned int);
        case TYPE_SHORT:   return sizeof(short);
        case TYPE_USHORT:  return sizeof(unsigned short);
        case TYPE_LONG:    return sizeof(long);
        case TYPE_ULONG:   return sizeof(unsigned long);
        case TYPE_LLONG:   return sizeof(long long);
        case TYPE_ULLONG:  return sizeof(unsigned long long);
        case TYPE_FLOAT:   return sizeof(float);
        case TYPE_DOUBLE:  return sizeof(double);
        case TYPE_LDOUBLE: return sizeof(long double);
        default:           return sizeof(void*);
    }
}

#define any_set(A, X) _Generic((X), \
    char:               any_set_char, \
    unsigned char:      any_set_uchar, \
    int:                any_set_int, \
    unsigned int:       any_set_uint, \
    short:              any_set_short, \
    unsigned short:     any_set_ushort, \
    long:               any_set_long, \
    unsigned long:      any_set_ulong, \
    long long:          any_set_llong, \
    unsigned long long: any_set_ullong, \
    float:              any_set_float, \
    double:             any_set_double, \
    long double:        any_set_ldouble, \
    default:            any_set_pointer)(A, X)

/*
#define ANY(X) _Generic((X), \
    char:               ((any){.type=TYPE_CHAR,.data._char=X}), \
    unsigned char:      ((any){.type=TYPE_UCHAR,.data._uchar=X}), \
    int:                ((any){.type=TYPE_INT,.data._int=X}), \
    unsigned int:       ((any){.type=TYPE_UINT,.data._uint=X}), \
    short:              ((any){.type=TYPE_SHORT,.data._short=X}), \
    unsigned short:     ((any){.type=TYPE_USHORT,.data._ushort=X}), \
    long:               ((any){.type=TYPE_LONG,.data._long=X}), \
    unsigned long:      ((any){.type=TYPE_ULONG,.data._ulong=X}), \
    long long:          ((any){.type=TYPE_LLONG,.data._llong=X}), \
    unsigned long long: ((any){.type=TYPE_ULLONG,.data._ullong=X}), \
    float:              ((any){.type=TYPE_FLOAT,.data._float=X}), \
    double:             ((any){.type=TYPE_DOUBLE,.data._double=X}), \
    long double:        ((any){.type=TYPE_LDOUBLE,.data._ldouble=X}), \
    default:            ((any){.type=TYPE_POINTER,.data._pointer=X}))
*/

#define ANY_CHAR(X)    (any){.type = TYPE_CHAR, .data._char = X}
#define ANY_UCHAR(X)   (any){.type = TYPE_UCHAR, .data._uchar = X}
#define ANY_INT(X)     (any){.type = TYPE_INT, .data._int = X}
#define ANY_UINT(X)    (any){.type = TYPE_UINT, .data._uint = X}
#define ANY_SHORT(X)   (any){.type = TYPE_INT, .data._short = X}
#define ANY_USHORT(X)  (any){.type = TYPE_USHORT, .data._ushort = X}
#define ANY_LONG(X)    (any){.type = TYPE_LONG, .data._long = X}
#define ANY_ULONG(X)   (any){.type = TYPE_ULONG, .data._ulong = X}
#define ANY_LLONG(X)   (any){.type = TYPE_LLONG, .data._llong = X}
#define ANY_ULLONG(X)  (any){.type = TYPE_ULLONG, .data._ullong = X}
#define ANY_FLOAT(X)   (any){.type = TYPE_FLOAT, .data._float = X}
#define ANY_DOUBLE(X)  (any){.type = TYPE_DOUBLE, .data._double = X}
#define ANY_LDOUBLE(X) (any){.type = TYPE_LDOUBLE, .data._ldouble = X}
#define ANY_POINTER(X) (any){.type = TYPE_POINTER, .data._pointer = X}

#endif /* end of include guard: ANY_H */
