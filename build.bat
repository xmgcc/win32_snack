RMDIR /Q /S build
MD build
CD BUILD
cmake -G "Visual Studio 10 2010" ..
REM  cmake -G "Visual Studio 15 2017" ..
cmake --build .

ctest -VV
CD ..
