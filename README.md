# LCGE
Lightweight C gaming library built with OpenGL.

## Build

Follow the instructions in [CONTRIBUTING.md](https://github.com/SatvikR/LCGE/blob/main/CONTRIBUTING.md#contributing-code)

## Basic usage

```c
#include <LCGE/lcge.h>

int main(int argc, char const *argv[])
{
    // Initialize LCGE
    if (lcge_init() == LCGE_INIT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create a window
    int success = lcge_create_context(500, 500, "LCGE Window Example", 
                                      LCGE_NON_RESIZEABLE);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    while (lcge_window_is_open())
    {
        lcge_clear_window();
        // Do any drawing here

        // Get ready for next iteration
        lcge_update_window();
    }
    
    lcge_exit();

    return 0;
}
```

## License

[MIT](https://github.com/SatvikR/LCGE/blob/main/LICENSE)