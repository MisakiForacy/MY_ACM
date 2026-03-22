@echo off
if "%1"=="setup" goto setup
cd /d D:\MY_CODE\ACM
python "D:\MY_CODE\ACM\auto_sync\update_stats.py" >nul 2>&1
git add . >nul 2>&1
git diff --staged --quiet
if errorlevel 1 (
    git commit -m "Auto sync %date% %time%" >nul 2>&1
    git push -f origin main >nul 2>&1
)
exit /b

:setup
powershell -ExecutionPolicy Bypass -Command "$a=New-ScheduledTaskAction -Execute 'D:\MY_CODE\ACM\auto_sync\auto_sync.bat'; $t=New-ScheduledTaskTrigger -Daily -At '00:00'; $s=New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable; Unregister-ScheduledTask -TaskName 'ACM_Auto_Sync' -Confirm:`$false -ErrorAction SilentlyContinue; Register-ScheduledTask -TaskName 'ACM_Auto_Sync' -Action $a -Trigger $t -Settings $s -Force"
exit /b
