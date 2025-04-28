@echo off
setlocal

:: Define paths
set QT_PATH=C:\Qt\6.8.3\msvc2022_64\bin
set BUILD_DIR=C:\Users\Luke\Documents\Games\Star Control II\QuasiSpaceMap\build\Desktop_Qt_6_8_3_MSVC2022_64bit-Release
set TARGET_DIR=C:\Users\Luke\Documents\Games\Star Control II\QuasiSpaceMapRelease

:: Create target directory if it doesn’t exist
if not exist "%TARGET_DIR%" mkdir "%TARGET_DIR%"

:: Copy the executable to the target directory
echo Copying executable...
copy "%BUILD_DIR%\QuasiSpaceMap.exe" "%TARGET_DIR%\QuasiSpaceMap.exe"

:: Deploy the application
echo Deploying application...
"%QT_PATH%\windeployqt" --no-opengl-sw --no-quick-import --no-system-d3d-compiler --no-system-dxc-compiler --no-translations --release --dir "%TARGET_DIR%" "%BUILD_DIR%\QuasiSpaceMap.exe"

echo Deployment complete. Files are in: "%TARGET_DIR%"
pause