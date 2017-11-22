mkdir build
cd build
cmake ..\ -G "Visual Studio 15 2017 Win64"
MSBuild /m /v:q /clp:ErrorsOnly All_Build.sln