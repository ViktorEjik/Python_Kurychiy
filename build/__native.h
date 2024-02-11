#ifndef MYPYC_NATIVE_H
#define MYPYC_NATIVE_H
#include <Python.h>
#include <CPy.h>
typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} main10___ComparableObject;

#endif
