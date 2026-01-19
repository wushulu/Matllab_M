$target = Get-Location
$keep = @('.md', '.m', '.slx', '.ioc', '.png', '.xlsx', '.py', '.ps1')

Write-Host "Target Directory: $target"
Write-Host "Allowed Extensions: $($keep -join ', ')"

$confirmation = Read-Host "This will delete files NOT in the allowed list. Type 'yes' to continue"
if ($confirmation -ne 'yes') {
    Write-Host "Operation cancelled."
    exit
}

# 1. Delete files
Get-ChildItem -Path $target -Recurse -File | ForEach-Object {
    if ($keep -notcontains $_.Extension.ToLower()) {
        Write-Host "Deleting file: $($_.FullName)"
        Remove-Item -Path $_.FullName -Force
    }
}

# 2. Delete empty directories
# Retrieve directories again to handle possibly emptied ones, sort descending safely by property
Get-ChildItem -Path $target -Recurse -Directory | Sort-Object FullName -Descending | ForEach-Object {
    if ((Get-ChildItem -Path $_.FullName).Count -eq 0) {
        Write-Host "Deleting empty dir: $($_.FullName)"
        Remove-Item -Path $_.FullName -Force
    }
}

Write-Host "Cleanup complete."
