$action = New-ScheduledTaskAction -Execute "wscript.exe" -Argument '"D:\MY_CODE\ACM\auto_sync\run_hidden.vbs"'
$trigger = New-ScheduledTaskTrigger -Daily -At "00:00"
$settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable

Unregister-ScheduledTask -TaskName "ACM_Auto_Sync" -Confirm:$false -ErrorAction SilentlyContinue
Register-ScheduledTask -TaskName "ACM_Auto_Sync" -Action $action -Trigger $trigger -Settings $settings -Force | Out-Null

cmd /c "schtasks /change /tn ACM_Auto_Sync /ri 30" | Out-Null

Write-Host "Task created with hidden VBS wrapper, every 30 minutes"
