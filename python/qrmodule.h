/**
 * QR Code generator module for Python
 *
 * Copyright (c) 2007-2013 Ryusuke SEKIYAMA. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * @package     pyqr
 * @author      Ryusuke SEKIYAMA <rsky0711@gmail.com>
 * @copyright   2007-2013 Ryusuke SEKIYAMA
 * @license     http://www.opensource.org/licenses/mit-license.php  MIT License
 */

#ifndef __QRMODULE_H__
#define __QRMODULE_H__

#include <Python.h>
#include "qr.h"

typedef struct _QRCodeObject QRCodeObject;

/* {{{ qr module method prototypes */

static PyObject *
qr_qrcode(PyObject *self, PyObject *args, PyObject *kwds);

static PyObject *
qr_mimetype(PyObject *self, PyObject *args);

static PyObject *
qr_extension(PyObject *self, PyObject *args);

/* }}} */
/* {{{ qr.QRCode type function prototypes */

static int
QRCode_init(QRCodeObject *self, PyObject *args, PyObject *kwds);

static void
QRCode_dealloc(QRCodeObject *self);

/* }}} */
/* {{{ qr.QRCode class method prototypes */

static PyObject *
QRCode_add_data(QRCodeObject *self, PyObject *args, PyObject *kwds);

static PyObject *
QRCode_read_data(QRCodeObject *self, PyObject *args, PyObject *kwds);

static QRCodeObject *
QRCode_copy(QRCodeObject *self, PyObject *unused);

static PyObject *
QRCode_finalize(QRCodeObject *self, PyObject *unused);

static PyObject *
QRCode_is_finalized(QRCodeObject *self, PyObject *unused);

static PyObject *
QRCode_has_data(QRCodeObject *self, PyObject *unused);

static PyObject *
QRCode_get_symbol(QRCodeObject *self, PyObject *args, PyObject *kwds);

static PyObject *
QRCode_output_symbol(QRCodeObject *self, PyObject *args, PyObject *kwds);

static PyObject *
QRCode_get_info(QRCodeObject *self, PyObject *unused);

/* }}} */
/* {{{ internal function prototypes */

static PyObject *
PyQR_Process(const qr_byte_t *data, int data_len,
             int version, int mode, int eclevel, int masktype,
             int format, int magnify, int separator);

static PyObject *
PyQR_ProcessMulti(const qr_byte_t *data, int data_len,
                  int version, int mode, int eclevel, int masktype, int maxnum,
                  int format, int magnify, int separator, int order);

static QRCode *
PyQR_Create(const qr_byte_t *data, int data_len,
            int version, int mode, int eclevel, int masktype);

static QRStructured *
PyQR_CreateMulti(const qr_byte_t *data, int data_len,
                 int version, int mode, int eclevel, int masktype, int maxnum);

static qr_byte_t *
PyQR_GetSymbol(QRCode *qr,
               int format, int separator, int magnify, int *symbol_size);

static qr_byte_t *
PyQR_GetSymbols(QRStructured * st,
                int format, int separator, int magnify,
                int order, int *symbol_size);

static void
PyQR_SetError(int errcode, const char *errmsg);

static PyTypeObject *
PyQR_TypeObject(void);

static const char *
PyQR_ActiveFuncName(void);

/* }}} */
/* {{{ compatibility macros and inline functions */

#ifndef Py_TYPE
#define Py_TYPE(ob) (((PyObject*)(ob))->ob_type)
#endif

#if PY_MAJOR_VERSION < 3
#define PyLong_FromLong PyInt_FromLong
#endif

/* }}} */

#endif /* __QRMODULE_H__ */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: nil;
 * End:
 * vim600: et sw=4 ts=4 fdm=marker
 * vim<600: et sw=4 ts=4
 */
