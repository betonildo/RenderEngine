#ifndef OSEXPORT_H
#define OSEXPORT_H

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
    #define OS_WIN 1
#endif

#ifdef OS_WIN
    #ifdef ENGINE_EXPORTING  
        #define ENGINE_API    __declspec(dllexport)  
    #else  
        #define ENGINE_API    __declspec(dllimport)  
    #endif

    #include <Windows.h>

    typedef void(*pConMsg)(char*, ...);

    pConMsg ConMsg;

    void newThread(){
        ConMsg = (pConMsg)GetProcAddress(GetModuleHandle("tier0.dll"), "Msg");
        ConMsg("Hello world! I'm at: %.8X", ConMsg);
    }

    BOOL WINAPI DllMain(HINSTANCE instHandle, DWORD reason, LPVOID reserved) {
        if(reason == DLL_PROCESS_ATTACH){
            CreateThread(0, 0,(LPTHREAD_START_ROUTINE)newThread, 0, 0, 0);
        }
        return true;
    }
#else
    #define ENGINE_API
#endif


#endif /*OSEXPORT_H*/