@echo off
:: Navigate to the script directory (in case it's executed from another location)
cd /d "%~dp0"

:: Set up variables
set BUILD_DIR=build
set EXECUTABLE=%BUILD_DIR%\bin\Mephisto.exe

:: Clean the build directory if needed
if exist %BUILD_DIR% (
    echo Cleaning up previous build...
    rmdir /s /q %BUILD_DIR%
)

:: Create build directory
echo Creating build directory...
mkdir %BUILD_DIR%

:: Navigate to build directory
cd %BUILD_DIR%

:: Generate build files using CMake
echo Running CMake configuration...
cmake -G "MinGW Makefiles" ..

:: Build the project
echo Building the project...
mingw32-make

:: Check if the executable was built successfully
if exist %EXECUTABLE% (
    echo Launching Mephisto...
    "%EXECUTABLE%"
) else (
    echo Build failed! Check for errors in the output.
)

:: Pause to keep the terminal open after execution
pause
