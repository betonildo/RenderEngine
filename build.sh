echo "Starting Compilation..."
mkdir build
cd build
cmake ..
make
make install
cd ..
echo "Finished Compilation"