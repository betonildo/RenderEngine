echo "Starting Compilation..."
g++ -Wall -std=c++11 -g -o main src/* -Iinclude/ -Iexternal/SDL2-2.0.5/Ubuntu14_x86_64/include/ -Lexternal/SDL2-2.0.5/Ubuntu14_x86_64/lib/ -lSDL2 -lSDL2main -lGL -pthread -ldl

echo "Finished Compilation"