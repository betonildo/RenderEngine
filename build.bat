mkdir build
cd build
cmake ..\ -G "Visual Studio 15 2017 Win64"
msbuild /m /v:q All_Build.sln