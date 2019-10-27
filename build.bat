MD build
CD BUILD
REM  cmake -G "Visual Studio 10 2010" ..
cmake -G "Visual Studio 15 2017" ..
cmake --build .

CD ..
