$ErrorActionPreference = "Continue"

$RepoPath  = "D:\MY_CODE\ACM"
$LogFile   = Join-Path $RepoPath "auto_sync\sync_log.txt"
$MaxLog    = 200

function Write-Log {
    param([string]$Level, [string]$Msg)
    $ts  = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $line = "$ts [$Level] $Msg"
    Add-Content -Path $LogFile -Value $line -Encoding UTF8
    $all = @(Get-Content $LogFile -Encoding UTF8 -ErrorAction SilentlyContinue)
    if ($all.Count -gt $MaxLog) {
        $all[-$MaxLog..-1] | Set-Content $LogFile -Encoding UTF8
    }
}

function Test-ProxyAvailable {
    try {
        $proxy = & git config --get http.proxy 2>$null
        if (-not $proxy) { return $false }
        if ($proxy -match '://([^:/]+):(\d+)') {
            $hostname = $matches[1]
            $port     = [int]$matches[2]
            $tcp = New-Object System.Net.Sockets.TcpClient
            if ($tcp.ConnectAsync($hostname, $port).Wait(2000)) {
                $tcp.Close()
                return $true
            }
            $tcp.Close()
        }
    } catch { }
    return $false
}

function Do-Push {
    Write-Log "INFO" "Attempting git push..."

    $env:GIT_TERMINAL_PROMPT = '0'

    if (Test-ProxyAvailable) {
        Write-Log "INFO" "Proxy detected, pushing with proxy..."
        try {
            $LASTEXITCODE = 0
            $pushOut = & git -c http.postBuffer=524288000 push origin main 2>&1 | Out-String
            if ($LASTEXITCODE -eq 0) {
                Write-Log "INFO" "Push OK (proxy): $($pushOut.Trim())"
                return $true
            } else {
                Write-Log "WARN" "Push with proxy failed: $($pushOut.Trim())"
            }
        } catch {
            Write-Log "WARN" "Push with proxy exception: $_"
        }
    } else {
        Write-Log "WARN" "Proxy not available, skipping proxy push attempt"
    }

    Write-Log "INFO" "Retrying push without proxy..."
    try {
        $LASTEXITCODE = 0
        $pushOut = & git -c http.proxy= -c https.proxy= -c http.postBuffer=524288000 push origin main 2>&1 | Out-String
        if ($LASTEXITCODE -eq 0) {
            Write-Log "INFO" "Push OK (direct): $($pushOut.Trim())"
            return $true
        } else {
            Write-Log "WARN" "Push (direct) failed: $($pushOut.Trim())"
            return $false
        }
    } catch {
        Write-Log "WARN" "Push (direct) exception: $_"
        return $false
    }
}

# ── Main ──────────────────────────────────────────
try {
    Set-Location $RepoPath

    # 1. Update stats (README + SVG charts)
    Write-Log "INFO" "Running update_stats.py..."
    $LASTEXITCODE = 0
    $pyOut = & python (Join-Path $RepoPath "auto_sync\update_stats.py") 2>&1 | Out-String
    Write-Log "INFO" "update_stats.py: $($pyOut.Trim())"

    # 2. Stage changes
    Write-Log "INFO" "Staging changes..."
    $LASTEXITCODE = 0
    git add . 2>$null

    # 3. Check for staged changes
    $LASTEXITCODE = 0
    git diff --staged --quiet 2>$null
    if ($LASTEXITCODE -ne 0) {
        $msg = "Auto sync " + (Get-Date -Format "yyyy-MM-dd HH:mm:ss")
        $LASTEXITCODE = 0
        git commit -m $msg 2>$null
        Write-Log "INFO" "Committed: $msg"

        # 4. Push (with proxy fallback)
        $pushed = Do-Push
        if (-not $pushed) {
            Write-Log "WARN" "Push failed this cycle - will retry on next run"
        }
    } else {
        Write-Log "INFO" "No changes to commit"
    }
} catch {
    Write-Log "ERROR" "Script error: $_"
}
