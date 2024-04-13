Get-NetAdapter |
  Where-Object { $_.Status -eq 'up' -and $_.InterfaceName -like 'ethernet*' -and $_.Virtual -ne $True } |
    Select-Object -ExpandProperty MacAddress
