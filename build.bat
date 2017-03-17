echo "Starting Compilation..."
cd build
cmake ..\ -G "MinGW Makefiles"
mingw32-make
mingw32-make install
cd ..
echo "Finished Compilation"