@echo off
echo 删除Debug目录...
set searchTar=Debug
for /f "delims=" %%i in ('dir /ad/b/s "%searchTar%"') do (rmdir /s /q %%i)
rmdir /s /q "Debug"
echo 删除调试文件...
for /f "delims=" %%i in ('dir /b/s "*.txt"') do (del /s /q %%i)
pause