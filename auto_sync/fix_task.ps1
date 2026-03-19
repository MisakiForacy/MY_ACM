$a = New-ScheduledTaskAction -Execute "D:\MY_CODE\ACM\auto_sync\auto_sync.bat"
$t = New-ScheduledTaskTrigger -Daily -At "00:00"
$s = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable
Unregister-ScheduledTask -TaskName "ACM_Auto_Sync" -Confirm:$false -ErrorAction SilentlyContinue
Register-ScheduledTask -TaskName "ACM_Auto_Sync" -Action $a -Trigger $t -Settings $s -Force
Write-Host "Task created. Current path: D:\MY_CODE\ACM\auto_sync\auto_sync.bat"
Write-Host "To add 30-minute interval, use: schtasks /change /tn ACM_Auto_Sync /ri 30"
