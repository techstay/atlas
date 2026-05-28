<#
.SYNOPSIS 重建windows图标缓存
 #>

function RebuildIconCache {
  param()
  Stop-Process -Name explorer -Force
  $iconCache = "$env:LOCALAPPDATA/IconCache.db"
  Remove-Item -Path $iconCache -ErrorAction SilentlyContinue
}
