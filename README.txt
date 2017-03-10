For g++ on windows use -municode for compilation.

Windows compilation to include windows entry point
 g++ src\appmain.cpp src\main.cpp src\WindowManager.cpp src\Input.cpp -o main -I"include/" -municode

Windows using SDL2
    g++ -Wall src\*.cpp -o main -I"include/" -I"external/SDL2205/include/" -L"external/SDL2205/lib/" -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2.dll -lopengl32 -lgdi32