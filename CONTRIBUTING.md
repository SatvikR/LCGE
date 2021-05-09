# How to Contribute to LCGE

You can contribute to this project in two ways:

- Create an issue
- Contributing Code

## Creating an Issue

If you are creating an issue make sure to:

- Keep suggestions realistic
- Be specific

## Contributing Code

The first thing you will want to do is fork this repository and clone your fork to your local machine.
Make sure you use the `--recursive` when cloning so you clone the submodules as well.

Then, you will need to build the project:

1. Create build files

```sh
# Use cmake to create build files
cmake -B ./build .
```

2. Build

```sh
# From the root of the repo
cmake --build ./build
```

These two steps will build glad, GLFW, and LCGE as static libraries, and build the examples as executables.
The output files will be in different places inside `./build` depending on your build system.

Now that you've built LCGE, you can start writing code.

### Style:

Follow these simple guidelines for code style/formatting.

Every file must begin with this comment with a license notice

> Before commiting, run this command `find src/ include/ tests/ -iname *.h -o -iname *.c | xargs clang-format -i`

```c
/*
    LCGE - A Lightweight C Game Engine
    Copyright (C) 2021  YOUR NAME

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA

    YOUR NAME <YOUR EMAIL>
*/
```

> If you are editing a file that already has a copyright notice, add your name to the copyright notice on a new line, and add your name and email at the end on a new line.

Formatting:

- **Use 4 spaces rather than tabs**
- Use 80 as your column limit/ruler
- For naming in code:

```c
int my_var;

typedef struct LCGE_struct_name
{
} LCGE_struct_name;

void lcge_function();

#define LCGE_CONSTANT 1
```

- For naming files, no capital letters, no spaces or underscores (ex. `window.h` or `core.c`)

Style:

- All functions that users may access must be declared like this in `include/LCGE/lcge.h`

```c
/* Description */
extern void lcge_function_name();
```

- Functions are implemented in `src`
- Declare structs opaquely like this (in `include/LCGE/lcge.h`)

```c
typedef struct LCGE_name LCGE_name;
```

- Then define them in a header in `src`

```c

#include <LCGE/lcge.h>

typedef struct LCGE_name
{
  int thing;
  char *name;
} LCGE_name;
```

- Use these header guards

```c
#ifndef _FILE_H
#define _FILE_H

#ifdef __cplusplus
extern "C"
{
#endif

/* code */

#ifdef __cplusplus
}
#endif

#endif
```
