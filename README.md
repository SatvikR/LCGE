# LCGE

```
     ___       ________  ________  _______
    |\  \     |\   ____\|\   ____\|\  ___ \
    \ \  \    \ \  \___|\ \  \___|\ \   __/|
     \ \  \    \ \  \    \ \  \  __\ \  \_|/__
      \ \  \____\ \  \____\ \  \|\  \ \  \_|\ \
       \ \_______\ \_______\ \_______\ \_______\
        \|_______|\|_______|\|_______|\|_______| v1.1.0
```

A Lightweight C game engine built with OpenGL.

[Docs](https://satvikr.github.io/LCGE/)

## TOC

- [Capabilities](https://github.com/SatvikR/LCGE#capabilities)
- [Build from source](https://github.com/SatvikR/LCGE#build-from-source)
- [Basic Usage](https://github.com/SatvikR/LCGE#basic-usage)
- [License](https://github.com/SatvikR/LCGE#licenses)
- [Dependencies](https://github.com/SatvikR/LCGE#dependencies)

## Capabilities

- Create a window
- Maintain an FPS
- Render 2D rectangles
- Render 2D images
- Render 2D lines
- Rotate 2D rectangles and images
- Get keyboard input
- Get mouse input
- Load truetype fonts
- Render text
- More coming soon!

## Build From Source

1. Clone

```sh
git clone --recursive https://github.com/SatvikR/LCGE.git
```

2. Build using [CMake](https://cmake.org/)

```
cmake -B ./build .
cmake --build ./build
```

> Make sure you link with LCGE (shared), glad, and glfw

## Basic usage

Look [here](https://github.com/SatvikR/LCGE/tree/main/tests) for specific exaxmples

```c
#include <LCGE/lcge.h>

int main(int argc, char const *argv[])
{
    // Initialize LCGE with the path to the res directory of LCGE (specific to you)
    if (lcge_init("vendor/LCGE/res") == LCGE_INIT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create a window
    int success = lcge_create_context(500, 500, "LCGE Example",
                                      LCGE_NON_RESIZEABLE);

    // Create clock with a max fps
    LCGE_clock *clock = lcge_clock_create(60);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    while (lcge_window_is_open())
    {
        // Do any udpating here

        // Do any drawing here
        lcge_window_clear();

        // Get ready for next iteration
        lcge_clock_tick(clock);
        lcge_window_update();
    }

    // Clean up
    lcge_clock_delete(clock);

    lcge_exit();

    return 0;
}
```

## License(s)

LCGE is licensed under the [GNU Lesser General Public License v2.1](https://github.com/SatvikR/LCGE/blob/main/LICENSE)

Copyright (c) 2021 Satvik Reddy

A brief summary of the license:

- You can use LCGE in any project, though if its closed source, you must dynamically link with LCGE
- If you make changes/additions to LCGE, they must be released with an LGPL compatible license (though I prefer you submit your changes back to this repository)
- More info in the `LICENSE` file in the root of the source tree

### Dependencies

| Dependency | License                                                                                             |
| ---------- | --------------------------------------------------------------------------------------------------- |
| GLFW       | [zlib/libpng](https://github.com/glfw/glfw/blob/master/LICENSE.md)                                  |
| glad       | [Public Domain/WTFPL/CC0](https://github.com/Dav1dde/glad#whats-the-license-of-glad-generated-code) |
| stb        | [MIT/Public Domain](https://github.com/nothings/stb/blob/master/LICENSE)                            |
