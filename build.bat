echo "Starting Compilation..."
copy external\SDL2-2.0.5\WinMinGW64\bin\SDL2.dll build\SDL2.dll
g++ -Wall -std=c++11 -g -o build\main src/* -Iinclude/ -Itest/ -Iexternal/LinearMath/include/ -Iexternal/SDL2-2.0.5/WinMinGW64/include/ -Lexternal/SDL2-2.0.5/WinMinGW64/lib/ -lSDL2 -lSDL2main -lGL -pthread -ldl
echo "Finished Compilation"