# LCGE
A Lightweight C graphics engine built with OpenGL.

## Build

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
        lcge_window_udpate();
    }

    lcge_exit();

    return 0;
}
```

## License

[MIT](https://github.com/SatvikR/LCGE/blob/main/LICENSE)
