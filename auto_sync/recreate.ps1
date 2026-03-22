$a = New-ScheduledTaskAction -Execute "D:\MY_CODE\ACM\auto_sync\auto_sync.bat"
$t = New-ScheduledTaskTrigger -Daily -At "00:00"
$s = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable
Register-ScheduledTask -TaskName "ACM_Auto_Sync" -Action $a -Trigger $t -Settings $s -Force
Write-Host "Task created"
