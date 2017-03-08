#include "renderer_local_includes.h"
#include "WindowManager.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    WindowManager win;

    if (!win.Create(L"Learn to Program Windows 2", WS_OVERLAPPEDWINDOW))
    {
        return 0;
    }

    win.Show(nCmdShow);

    // Run the message loop.
    return win.Watch();
}