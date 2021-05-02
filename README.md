# LCGE
A Lightweight C game engine built with OpenGL.

## Build

Follow the instructions in [CONTRIBUTING.md](https://github.com/SatvikR/LCGE/blob/main/CONTRIBUTING.md#contributing-code)

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
        lcge_clear_window();

        // Get ready for next iteration
        lcge_update_window();
    }

    lcge_exit();

    return 0;
}
```

## License

[MIT](https://github.com/SatvikR/LCGE/blob/main/LICENSE)
