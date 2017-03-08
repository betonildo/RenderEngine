#include "main.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
    // Run the message loop.
    // TODO: Parse cmd line as argv and count it as argc to pass to main definition
    printf("%d\n", nCmdShow);
    return main();
}