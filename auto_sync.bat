@echo off
cd /d D:\MY_CODE\ACM
git pull origin main --no-edit
git add .
git commit -m "Auto sync %date%"
git push -f origin main
