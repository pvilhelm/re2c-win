@echo off
echo Building re2c for Windows in %~dp0 with Visual Studio 15
echo ---
cd %~dp0
cmake -G"Visual Studio 15 2017 Win64" -B"build/w64" "./"
MSBuild.exe build/w64/re2c.sln
xcopy /F /R /Y build\w64\Debug\re2c.exe re2c.exe*