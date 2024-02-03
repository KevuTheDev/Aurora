@ echo off

echo Compiling Aurora
cmake --build build

echo Running Aurora.exe
cd build\Aurora\Debug\
Aurora.exe

cd ..\..\..