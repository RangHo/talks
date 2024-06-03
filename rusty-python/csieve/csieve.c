#include <Python.h>

#include <stdlib.h>
#include <math.h>

static PyObject *sieve(PyObject *self, PyObject *args)
{
    Py_ssize_t n;
    if (!PyArg_ParseTuple(args, "n", &n))
        goto error;

    int *sieve = (int *)malloc((n - 1) * sizeof(int));
    if (!sieve)
        goto error;
    for (Py_ssize_t i = 2; i <= n; i++)
        sieve[i - 2] = i;

    Py_ssize_t limit = (Py_ssize_t)sqrt((double)n);
    for (Py_ssize_t i = 2; i < limit; i++)
        if (sieve[i - 2] != 0)
            for (Py_ssize_t j = i * i; j <= n; j += i)
                sieve[j - 2] = 0;

    Py_ssize_t prime_num = 0;
    for (Py_ssize_t i = 0; i < n - 1; i++)
        if (sieve[i])
            prime_num++;

    PyObject *prime_list = PyList_New(prime_num);
    PyObject *buffer = NULL;
    for (Py_ssize_t i = 0, j = 0; i < n - 1; i++) {
        if (!sieve[i])
            continue;

        buffer = PyLong_FromLong(sieve[i]);
        if (!buffer) {
            Py_DECREF(prime_list);
            prime_list = NULL;
            goto error;
        } else {
            PyList_SetItem(prime_list, j++, buffer);
        }
    }

    free(sieve);
    return prime_list;

error:
    PyErr_Occurred();
    return NULL;
}

static PyMethodDef csieve_methods[] = {
    {"sieve", sieve, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef csieve_module = {
    PyModuleDef_HEAD_INIT,
    "csieve",
    NULL,
    -1,
    csieve_methods
};

PyMODINIT_FUNC PyInit_csieve(void)
{
    return PyModule_Create(&csieve_module);
}

