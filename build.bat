mkdir build
cd build
cmake ..\ -G "MinGW Makefiles"
mingw32-make
rem cmake ..\ -G "Visual Studio 15 2017 Win64"
rem MSBuild /m /v:q /clp:ErrorsOnly All_Build.sln
cd ..