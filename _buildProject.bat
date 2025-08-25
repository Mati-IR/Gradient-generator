@echo off
setlocal

set PROJECT_DIR=%cd%
set BUILD_DIR=%PROJECT_DIR%\build

if not exist %BUILD_DIR% (
    echo Creating build directory...
    mkdir %BUILD_DIR%
)

cd %BUILD_DIR%

:: Run CMake to configure the project (specify a generator if needed, like MinGW or Ninja)
echo Configuring the project with CMake...
cmake %PROJECT_DIR% -G "Ninja"

:: Build the project and specify the target "program"
echo Building the program...
cmake --build . --target program --config Debug

if %ERRORLEVEL% NEQ 0 (
    echo Build failed! Exiting...
    exit /b %ERRORLEVEL%
)

cd %PROJECT_DIR%

echo Program built successfully! Executable is located in the build directory.
endlocal
