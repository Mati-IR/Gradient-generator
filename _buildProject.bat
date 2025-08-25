@echo off
setlocal

:: Set project directory and build directory variables
set PROJECT_DIR=%cd%
set BUILD_DIR=%PROJECT_DIR%\build

:: Check if the build directory exists, create it if it doesn't
if not exist %BUILD_DIR% (
    echo Creating build directory...
    mkdir %BUILD_DIR%
)

:: Navigate to the build directory
cd %BUILD_DIR%

:: Run CMake to configure the project (specify a generator if needed, like MinGW or Ninja)
echo Configuring the project with CMake...
cmake %PROJECT_DIR% -G "Ninja"

:: Build the project and specify the target "program"
echo Building the program...
cmake --build . --target program --config Debug

:: Check if the build was successful
if %ERRORLEVEL% NEQ 0 (
    echo Build failed! Exiting...
    exit /b %ERRORLEVEL%
)

:: Return to the project root
cd %PROJECT_DIR%

echo Program built successfully! Executable is located in the build directory.
endlocal
