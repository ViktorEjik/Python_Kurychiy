#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[25];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_main10_internal;
extern CPyModule *CPyModule_main10;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_abc;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_sys;
extern PyTypeObject *CPyType_Comparable;
extern PyObject *CPyDef_Comparable(void);
extern PyObject *CPyDef_Comparable_____lt__(PyObject *cpy_r_self, PyObject *cpy_r_other);
extern PyObject *CPyPy_Comparable_____lt__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_bubble(PyObject *cpy_r_sequence);
extern PyObject *CPyPy_bubble(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
