$action = New-ScheduledTaskAction -Execute "D:\MY_CODE\ACM\auto_sync.bat"
$trigger = New-ScheduledTaskTrigger -Daily -At "00:00"
Register-ScheduledTask -TaskName "ACM_Auto_Sync" -Action $action -Trigger $trigger -Force
