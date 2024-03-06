mkdir build
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -S . -B build -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release

cd build
nmake
cd ..
