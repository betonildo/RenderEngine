//#include "main.h"
#include <windows.h>
extern "C" {
    int main( int argc, char **argv ) ;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
    // Run the message loop.
    // TODO: Parse cmd line as argv and count it as argc to pass to main definition
    return main(0, NULL);
}