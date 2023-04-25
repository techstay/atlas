open System.IO

let readHosts =
  // auto closed when block ends
  use hostFile = File.OpenRead(@"C:\Windows\system32\drivers\etc\hosts")
  let canRead = hostFile.CanRead
  canRead
