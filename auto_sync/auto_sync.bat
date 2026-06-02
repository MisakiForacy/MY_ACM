@echo off
if "%1"=="setup" goto setup
powershell -NoProfile -ExecutionPolicy Bypass -File "D:\MY_CODE\ACM\auto_sync\auto_sync_runner.ps1"
exit /b

:setup
powershell -NoProfile -ExecutionPolicy Bypass -File "D:\MY_CODE\ACM\auto_sync\setup_task.ps1"
exit /b
