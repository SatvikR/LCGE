# LCGE
A Lightweight C game engine built with OpenGL.

## Capabilities

 - Create a window
 - Maintain an FPS
 - Render 2D rectangles
 - Render 2D images
 - More coming soon!

# Use in your project

1. Download the latest binaries from [the releases page](https://github.com/SatvikR/LCGE/releases)
2. Link with glfw3, glad, and LCGE when compiling your project.
3. Include `lcge.h` that will be in the `include` directory from the release
4. Make sure you pass in the relative path to the `res` directory that you downloaded from the release page when calling `lcge_init()`
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

## License

[MIT](https://github.com/SatvikR/LCGE/blob/main/LICENSE)
