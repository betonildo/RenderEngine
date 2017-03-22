echo "Starting Compilation..."
cd build
cmake ..\ -G "MinGW Makefiles"
mingw32-make verbose=1
mingw32-make install
cd ..
echo "Finished Compilation"