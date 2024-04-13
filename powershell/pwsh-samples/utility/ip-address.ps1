Get-NetIPAddress -AddressFamily IPv4 -InterfaceAlias '以太网*' |
  Where-Object { $_.PrefixLength -lt 32 } |
    Select-Object -ExpandProperty IPAddress

Get-NetIPAddress -AddressFamily IPv6 -InterfaceAlias '以太网*' |
  Where-Object { $_.PrefixLength -lt 100 } |
    Select-Object -ExpandProperty IPAddress
