// The MIT License (MIT)

// Copyright (c) 2021 Satvik Reddy

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.


#ifndef _GLERROR_H
#define _GLERROR_H

#ifdef __cplusplus
extern "C"
{
#endif


#include <stdbool.h>
#include <stdio.h>
#include "debug.h"

#ifndef NDEBUG
#ifdef _MSC_VER
#define ASSERT(x) \
    if (!(x)) \
        __debugbreak();
#else
#include <signal.h>
#define ASSERT(x) \
    if (!(x)) \
        raise(SIGTRAP);
#endif
#define GLCALL(x) \
    GL_clear_error(); \
    x; \
    ASSERT(GL_log_call(__FILE__, __LINE__))
#else
#define ASSERT(x) \
    x;
#define GLCALL(x) \
    x;
#endif


void GL_clear_error();

bool GL_log_call(const char *file, int line);

#ifdef __cplusplus
}
#endif
#endif