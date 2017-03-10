#include "renderer_local_includes.h"
#include "WindowManager.h"



int main( int argc, char **argv ) {
    WindowManager win;

    if (!win.Create("Learn to Program Windows 2"))
    {
        return 0;
    }

    win.Show();

    // Run the message loop.
    return win.Watch();
}