#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"

static PyObject *CPyDunder__RichCompare_Comparable(PyObject *obj_lhs, PyObject *obj_rhs, int op) {
    switch (op) {
        case Py_LT: {
            PyObject *arg_lhs;
            if (likely(PyObject_TypeCheck(obj_lhs, CPyType_Comparable)))
                arg_lhs = obj_lhs;
            else {
                CPy_TypeError("main10.Comparable", obj_lhs); 
                return NULL;
            }
            PyObject *arg_rhs = obj_rhs;
            return CPyDef_Comparable_____lt__(arg_lhs, arg_rhs);
        }
    }
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static PyObject *Comparable_setup(PyTypeObject *type);
PyObject *CPyDef_Comparable(void);

static PyObject *
Comparable_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Comparable) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return Comparable_setup(type);
}

static int
Comparable_traverse(main10___ComparableObject *self, visitproc visit, void *arg)
{
    return 0;
}

static int
Comparable_clear(main10___ComparableObject *self)
{
    return 0;
}

static void
Comparable_dealloc(main10___ComparableObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Comparable_dealloc)
    Comparable_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem Comparable_vtable[1];
static bool
CPyDef_Comparable_trait_vtable_setup(void)
{
    CPyVTableItem Comparable_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Comparable_____lt__,
    };
    memcpy(Comparable_vtable, Comparable_vtable_scratch, sizeof(Comparable_vtable));
    return 1;
}


static PyGetSetDef Comparable_getseters[] = {
    {NULL}  /* Sentinel */
};

static PyMethodDef Comparable_methods[] = {
    {"__lt__",
     (PyCFunction)CPyPy_Comparable_____lt__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Comparable_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Comparable",
    .tp_new = Comparable_new,
    .tp_dealloc = (destructor)Comparable_dealloc,
    .tp_traverse = (traverseproc)Comparable_traverse,
    .tp_clear = (inquiry)Comparable_clear,
    .tp_getset = Comparable_getseters,
    .tp_methods = Comparable_methods,
    .tp_richcompare = CPyDunder__RichCompare_Comparable,
    .tp_basicsize = sizeof(main10___ComparableObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_Comparable_template = &CPyType_Comparable_template_;

static PyObject *
Comparable_setup(PyTypeObject *type)
{
    main10___ComparableObject *self;
    self = (main10___ComparableObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Comparable_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_Comparable(void)
{
    PyObject *self = Comparable_setup(CPyType_Comparable);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {"bubble", (PyCFunction)CPyPy_bubble, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "main10",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_main10(void)
{
    PyObject* modname = NULL;
    if (CPyModule_main10_internal) {
        Py_INCREF(CPyModule_main10_internal);
        return CPyModule_main10_internal;
    }
    CPyModule_main10_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_main10_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_main10_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_main10_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_main10_internal;
    fail:
    Py_CLEAR(CPyModule_main10_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_Comparable);
    return NULL;
}

PyObject *CPyDef_Comparable_____lt__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    cpy_r_r0 = (PyObject *)&_Py_EllipsisObject;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    return cpy_r_r1;
}

PyObject *CPyPy_Comparable_____lt__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__lt__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyObject_TypeCheck(obj_self, CPyType_Comparable)))
        arg_self = obj_self;
    else {
        CPy_TypeError("main10.Comparable", obj_self); 
        goto fail;
    }
    PyObject *arg_other = obj_other;
    PyObject *retval = CPyDef_Comparable_____lt__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("main10.py", "__lt__", 6, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_bubble(PyObject *cpy_r_sequence) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_N;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r3;
    char cpy_r_r4;
    int64_t cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    CPyTagged cpy_r_r11;
    CPyTagged cpy_r_r12;
    CPyTagged cpy_r_r13;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r14;
    char cpy_r_r15;
    int64_t cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    CPyTagged cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    CPyTagged cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
    CPyTagged cpy_r_r43;
    PyObject *cpy_r_r44;
    int32_t cpy_r_r45;
    char cpy_r_r46;
    CPyTagged cpy_r_r47;
    CPyTagged cpy_r_r48;
    PyObject *cpy_r_r49;
    cpy_r_r0 = CPyObject_Size(cpy_r_sequence);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("main10.py", "bubble", 11, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_N = cpy_r_r0;
    cpy_r_r1 = CPyTagged_Subtract(cpy_r_N, 2);
    cpy_r_r2 = 0;
    CPyTagged_INCREF(cpy_r_r2);
    cpy_r_i = cpy_r_r2;
CPyL2: ;
    cpy_r_r3 = cpy_r_r2 & 1;
    cpy_r_r4 = cpy_r_r3 == 0;
    cpy_r_r5 = cpy_r_r1 & 1;
    cpy_r_r6 = cpy_r_r5 == 0;
    cpy_r_r7 = cpy_r_r4 & cpy_r_r6;
    if (!cpy_r_r7) goto CPyL4;
    cpy_r_r8 = (Py_ssize_t)cpy_r_r2 < (Py_ssize_t)cpy_r_r1;
    cpy_r_r9 = cpy_r_r8;
    goto CPyL5;
CPyL4: ;
    cpy_r_r10 = CPyTagged_IsLt_(cpy_r_r2, cpy_r_r1);
    cpy_r_r9 = cpy_r_r10;
CPyL5: ;
    if (!cpy_r_r9) goto CPyL28;
    cpy_r_r11 = CPyTagged_Subtract(cpy_r_N, cpy_r_i);
    CPyTagged_DECREF(cpy_r_i);
    cpy_r_r12 = CPyTagged_Subtract(cpy_r_r11, 2);
    CPyTagged_DECREF(cpy_r_r11);
    cpy_r_r13 = 0;
    CPyTagged_INCREF(cpy_r_r13);
    cpy_r_j = cpy_r_r13;
CPyL7: ;
    cpy_r_r14 = cpy_r_r13 & 1;
    cpy_r_r15 = cpy_r_r14 == 0;
    cpy_r_r16 = cpy_r_r12 & 1;
    cpy_r_r17 = cpy_r_r16 == 0;
    cpy_r_r18 = cpy_r_r15 & cpy_r_r17;
    if (!cpy_r_r18) goto CPyL9;
    cpy_r_r19 = (Py_ssize_t)cpy_r_r13 < (Py_ssize_t)cpy_r_r12;
    cpy_r_r20 = cpy_r_r19;
    goto CPyL10;
CPyL9: ;
    cpy_r_r21 = CPyTagged_IsLt_(cpy_r_r13, cpy_r_r12);
    cpy_r_r20 = cpy_r_r21;
CPyL10: ;
    if (!cpy_r_r20) goto CPyL29;
    CPyTagged_INCREF(cpy_r_j);
    cpy_r_r22 = CPyTagged_StealAsObject(cpy_r_j);
    cpy_r_r23 = PyObject_GetItem(cpy_r_sequence, cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("main10.py", "bubble", 14, CPyStatic_globals);
        goto CPyL30;
    }
    if (likely(PyObject_TypeCheck(cpy_r_r23, CPyType_Comparable)))
        cpy_r_r24 = cpy_r_r23;
    else {
        CPy_TypeErrorTraceback("main10.py", "bubble", 14, CPyStatic_globals, "main10.Comparable", cpy_r_r23);
        goto CPyL30;
    }
    cpy_r_r25 = CPyTagged_Add(cpy_r_j, 2);
    cpy_r_r26 = CPyTagged_StealAsObject(cpy_r_r25);
    cpy_r_r27 = PyObject_GetItem(cpy_r_sequence, cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("main10.py", "bubble", 14, CPyStatic_globals);
        goto CPyL31;
    }
    if (likely(PyObject_TypeCheck(cpy_r_r27, CPyType_Comparable)))
        cpy_r_r28 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("main10.py", "bubble", 14, CPyStatic_globals, "main10.Comparable", cpy_r_r27);
        goto CPyL31;
    }
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r24, cpy_r_r28, 4);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("main10.py", "bubble", 14, CPyStatic_globals);
        goto CPyL30;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("main10.py", "bubble", 14, CPyStatic_globals);
        goto CPyL30;
    }
    if (!cpy_r_r30) goto CPyL32;
    cpy_r_r31 = CPyTagged_Add(cpy_r_j, 2);
    cpy_r_r32 = CPyTagged_StealAsObject(cpy_r_r31);
    cpy_r_r33 = PyObject_GetItem(cpy_r_sequence, cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("main10.py", "bubble", 15, CPyStatic_globals);
        goto CPyL30;
    }
    if (likely(PyObject_TypeCheck(cpy_r_r33, CPyType_Comparable)))
        cpy_r_r34 = cpy_r_r33;
    else {
        CPy_TypeErrorTraceback("main10.py", "bubble", 15, CPyStatic_globals, "main10.Comparable", cpy_r_r33);
        goto CPyL30;
    }
    cpy_r_r35 = cpy_r_r34;
    CPyTagged_INCREF(cpy_r_j);
    cpy_r_r36 = CPyTagged_StealAsObject(cpy_r_j);
    cpy_r_r37 = PyObject_GetItem(cpy_r_sequence, cpy_r_r36);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("main10.py", "bubble", 15, CPyStatic_globals);
        goto CPyL33;
    }
    if (likely(PyObject_TypeCheck(cpy_r_r37, CPyType_Comparable)))
        cpy_r_r38 = cpy_r_r37;
    else {
        CPy_TypeErrorTraceback("main10.py", "bubble", 15, CPyStatic_globals, "main10.Comparable", cpy_r_r37);
        goto CPyL33;
    }
    cpy_r_r39 = cpy_r_r38;
    CPyTagged_INCREF(cpy_r_j);
    cpy_r_r40 = CPyTagged_StealAsObject(cpy_r_j);
    cpy_r_r41 = PyObject_SetItem(cpy_r_sequence, cpy_r_r40, cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r35);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("main10.py", "bubble", 15, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r43 = CPyTagged_Add(cpy_r_j, 2);
    CPyTagged_DECREF(cpy_r_j);
    cpy_r_r44 = CPyTagged_StealAsObject(cpy_r_r43);
    cpy_r_r45 = PyObject_SetItem(cpy_r_sequence, cpy_r_r44, cpy_r_r39);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r46 = cpy_r_r45 >= 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("main10.py", "bubble", 15, CPyStatic_globals);
        goto CPyL35;
    }
CPyL24: ;
    cpy_r_r47 = CPyTagged_Add(cpy_r_r13, 2);
    CPyTagged_DECREF(cpy_r_r13);
    CPyTagged_INCREF(cpy_r_r47);
    cpy_r_r13 = cpy_r_r47;
    cpy_r_j = cpy_r_r47;
    goto CPyL7;
CPyL25: ;
    cpy_r_r48 = CPyTagged_Add(cpy_r_r2, 2);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_INCREF(cpy_r_r48);
    cpy_r_r2 = cpy_r_r48;
    cpy_r_i = cpy_r_r48;
    goto CPyL2;
CPyL26: ;
    CPy_INCREF(cpy_r_sequence);
    return cpy_r_sequence;
CPyL27: ;
    cpy_r_r49 = NULL;
    return cpy_r_r49;
CPyL28: ;
    CPyTagged_DECREF(cpy_r_N);
    CPyTagged_DECREF(cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL26;
CPyL29: ;
    CPyTagged_DECREF(cpy_r_r12);
    CPyTagged_DECREF(cpy_r_r13);
    CPyTagged_DECREF(cpy_r_j);
    goto CPyL25;
CPyL30: ;
    CPyTagged_DecRef(cpy_r_N);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL27;
CPyL31: ;
    CPyTagged_DecRef(cpy_r_N);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r24);
    goto CPyL27;
CPyL32: ;
    CPyTagged_DECREF(cpy_r_j);
    goto CPyL24;
CPyL33: ;
    CPyTagged_DecRef(cpy_r_N);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r35);
    goto CPyL27;
CPyL34: ;
    CPyTagged_DecRef(cpy_r_N);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r39);
    goto CPyL27;
CPyL35: ;
    CPyTagged_DecRef(cpy_r_N);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    goto CPyL27;
}

PyObject *CPyPy_bubble(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"sequence", 0};
    static CPyArg_Parser parser = {"O:bubble", kwlist, 0};
    PyObject *obj_sequence;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_sequence)) {
        return NULL;
    }
    PyObject *arg_sequence = obj_sequence;
    PyObject *retval = CPyDef_bubble(arg_sequence);
    return retval;
fail: ;
    CPy_AddTraceback("main10.py", "bubble", 10, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    int32_t cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    int32_t cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    PyObject **cpy_r_r35;
    void *cpy_r_r37;
    void *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    char cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject **cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject **cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", -1, CPyStatic_globals);
        goto CPyL20;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[21]; /* ('ABCMeta', 'abstractmethod') */
    cpy_r_r6 = CPyStatics[6]; /* 'abc' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 1, CPyStatic_globals);
        goto CPyL20;
    }
    CPyModule_abc = cpy_r_r8;
    CPy_INCREF(CPyModule_abc);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[22]; /* ('Any', 'TypeVar', 'MutableSequence') */
    cpy_r_r10 = CPyStatics[10]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 2, CPyStatic_globals);
        goto CPyL20;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = NULL;
    cpy_r_r14 = CPyStatics[11]; /* 'main10' */
    cpy_r_r15 = (PyObject *)CPyType_Comparable_template;
    cpy_r_r16 = CPyType_FromTemplate(cpy_r_r15, cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 4, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r17 = CPyDef_Comparable_trait_vtable_setup();
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AddTraceback("main10.py", "<module>", -1, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r18 = CPyStatics[12]; /* '__mypyc_attrs__' */
    cpy_r_r19 = PyTuple_Pack(0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 4, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r20 = PyObject_SetAttr(cpy_r_r16, cpy_r_r18, cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r21 = cpy_r_r20 >= 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("main10.py", "<module>", 4, CPyStatic_globals);
        goto CPyL21;
    }
    CPyType_Comparable = (PyTypeObject *)cpy_r_r16;
    CPy_INCREF(CPyType_Comparable);
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyStatics[13]; /* 'Comparable' */
    cpy_r_r24 = CPyDict_SetItem(cpy_r_r22, cpy_r_r23, cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r25 = cpy_r_r24 >= 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("main10.py", "<module>", 4, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyStatics[9]; /* 'MutableSequence' */
    cpy_r_r28 = CPyDict_GetItem(cpy_r_r26, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 8, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r29 = (PyObject *)CPyType_Comparable;
    cpy_r_r30 = PyObject_GetItem(cpy_r_r28, cpy_r_r29);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 8, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyStatics[14]; /* 'Sortable' */
    cpy_r_r33 = CPyDict_SetItem(cpy_r_r31, cpy_r_r32, cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("main10.py", "<module>", 8, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r35 = (PyObject **)&CPyModule_sys;
    PyObject **cpy_r_r36[1] = {cpy_r_r35};
    cpy_r_r37 = (void *)&cpy_r_r36;
    int64_t cpy_r_r38[1] = {18};
    cpy_r_r39 = (void *)&cpy_r_r38;
    cpy_r_r40 = CPyStatics[24]; /* (('sys', 'sys', 'sys'),) */
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyStatics[16]; /* 'main10.py' */
    cpy_r_r43 = CPyStatics[17]; /* '<module>' */
    cpy_r_r44 = CPyImport_ImportMany(cpy_r_r40, cpy_r_r37, cpy_r_r41, cpy_r_r42, cpy_r_r43, cpy_r_r39);
    if (!cpy_r_r44) goto CPyL20;
    cpy_r_r45 = CPyModule_sys;
    cpy_r_r46 = CPyStatics[18]; /* 'stdin' */
    cpy_r_r47 = CPyObject_GetAttr(cpy_r_r45, cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 19, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r48 = CPyStatics[19]; /* 'read' */
    PyObject *cpy_r_r49[1] = {cpy_r_r47};
    cpy_r_r50 = (PyObject **)&cpy_r_r49;
    cpy_r_r51 = PyObject_VectorcallMethod(cpy_r_r48, cpy_r_r50, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 19, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r47);
    if (likely(PyUnicode_Check(cpy_r_r51)))
        cpy_r_r52 = cpy_r_r51;
    else {
        CPy_TypeErrorTraceback("main10.py", "<module>", 19, CPyStatic_globals, "str", cpy_r_r51);
        goto CPyL20;
    }
    cpy_r_r53 = CPyModule_builtins;
    cpy_r_r54 = CPyStatics[20]; /* 'exec' */
    cpy_r_r55 = CPyObject_GetAttr(cpy_r_r53, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 19, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r56[1] = {cpy_r_r52};
    cpy_r_r57 = (PyObject **)&cpy_r_r56;
    cpy_r_r58 = _PyObject_Vectorcall(cpy_r_r55, cpy_r_r57, 1, 0);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("main10.py", "<module>", 19, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL24;
CPyL19: ;
    CPy_DECREF(cpy_r_r52);
    return 1;
CPyL20: ;
    cpy_r_r59 = 2;
    return cpy_r_r59;
CPyL21: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL20;
CPyL22: ;
    CPy_DecRef(cpy_r_r47);
    goto CPyL20;
CPyL23: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL20;
CPyL24: ;
    CPy_DECREF(cpy_r_r58);
    goto CPyL19;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_main10 = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_abc = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_sys = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[25];
const char * const CPyLit_Str[] = {
    "\a\bbuiltins\aABCMeta\016abstractmethod\003abc\003Any\aTypeVar\017MutableSequence",
    "\a\006typing\006main10\017__mypyc_attrs__\nComparable\bSortable\003sys\tmain10.py",
    "\004\b<module>\005stdin\004read\004exec",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {4, 2, 4, 5, 3, 7, 8, 9, 3, 15, 15, 15, 1, 23};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_main10_internal = NULL;
CPyModule *CPyModule_main10;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_abc;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_sys;
PyTypeObject *CPyType_Comparable;
PyObject *CPyDef_Comparable(void);
PyObject *CPyDef_Comparable_____lt__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_Comparable_____lt__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_bubble(PyObject *cpy_r_sequence);
PyObject *CPyPy_bubble(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
