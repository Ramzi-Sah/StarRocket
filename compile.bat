@echo off
cls

REM set vars
set EXEC_NAME=final.exe
set C_COMPILER=gcc.exe
set CPP_COMPILER=g++.exe
set RC_COMPILER=windres.exe
set MAKE_BIN=mingw32-make.exe

REM create build directory
mkdir build
cd build || goto end

REM cmake project
mkdir data
xcopy ..\data data /y /e
echo ---------------- Compiling ----------------
cmake .. -G"MinGW Makefiles" -DCMAKE_RC_COMPILER=%RC_COMPILER% -DCMAKE_C_COMPILER=%C_COMPILER% -DCMAKE_CXX_COMPILER=%CPP_COMPILER% -DCMAKE_MAKE_PROGRAM=%MAKE_BIN% -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1 || goto end

REM make project
%MAKE_BIN% || goto end
echo ------------ build successfull ------------

REM execute program
%EXEC_NAME%

:end
cd ..
pause
