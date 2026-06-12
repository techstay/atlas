param(
    [string]$file_path
)

if (-not $file_path) {
    Write-Error "Error: no file path provided"
    exit 1
}

# Normalize path separators
$file_path = $file_path -replace '\\', '/'

# Validate the file is a .cpp source
if ($file_path -notmatch '\.cpp$') {
    Write-Error "Error: $file_path is not a .cpp file"
    exit 1
}

# Derive the xmake target name: <subdir>_<basename>
$file_basename = [System.IO.Path]::GetFileNameWithoutExtension($file_path)
$parent_dir = Split-Path $file_path -Parent
$parent_dir_name = Split-Path $parent_dir -Leaf
$target_name = "${parent_dir_name}_${file_basename}"

Write-Host "--- Running xmake target: ${target_name} ---"
xmake run -y "$target_name"

