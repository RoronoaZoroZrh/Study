@echo off
echo ɾ��DebugĿ¼...
set searchTar=Debug
for /f "delims=" %%i in ('dir /ad/b/s "%searchTar%"') do (rmdir /s /q %%i)
rmdir /s /q "Debug"
echo ɾ�������ļ�...
for /f "delims=" %%i in ('dir /b/s "*.txt"') do (del /s /q %%i)
pause