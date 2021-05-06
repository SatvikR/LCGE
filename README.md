# LCGE

A Lightweight C game engine built with OpenGL.

## Capabilities

- Create a window
- Maintain an FPS
- Render 2D rectangles
- Render 2D images
- Get keyboard input
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
        lcge_window_udpate();
    }

    // Clean up
    lcge_clock_delete(clock);

    lcge_exit();

    return 0;
}
```

## License(s)

LCGE is licensed under the [GNU Lesser General Public License v2.1](https://github.com/SatvikR/LCGE/blob/main/LICENSE)

A brief summary of the license:

- You can use LCGE in any project you want (closed or open source)
- If you make changes/additions to LCGE you must they must be release with either a LGPL compatible license (though I prefer you submit your changes back to this repository)
- More info in the `LICENSE` file in the root of the source tree

### Dependencies

| Dependency | License                                                                                             |
| ---------- | --------------------------------------------------------------------------------------------------- |
| GLFW       | [zlib/libpng](https://github.com/glfw/glfw/blob/master/LICENSE.md)                                  |
| glad       | [Public Domain/WTFPL/CC0](https://github.com/Dav1dde/glad#whats-the-license-of-glad-generated-code) |
| stb        | [MIT/Public Domain](https://github.com/nothings/stb/blob/master/LICENSE)                            |
