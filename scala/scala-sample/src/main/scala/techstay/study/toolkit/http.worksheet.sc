import sttp.client4.quick.*
import sttp.client4.Response

// if you have local docker httpbin, use local url, otherwise use remote url
val remoteHttpBinUrl = "https://httpbin.org"
val localHttpBinUrl = "http://localhost"
val uriBase = localHttpBinUrl

// custom headers
val headers =
  Map("user-agent" -> "Edge Browser 110", "xxx-inspection" -> "abcdefg")

// sending http requests
val queryParameters = Map("name" -> "techstay", "id" -> "2", "q" -> "0.3")
var response: Response[String] = quickRequest
  .get(uri"$uriBase/get?$queryParameters")
  .headers(headers)
  .send()

response.code
response.body

// sending post requests
response = quickRequest
  .post(uri"$uriBase/post")
  .body("foo bar")
  .send()

response.code
var jsonObject = ujson.read(response.body)

// binary body
val bytes = "foo bar".getBytes()
var request = quickRequest
  .post(uri"$uriBase/post")
  .body(bytes)

response = request.send()
response.body

// uploading files
val hostsFile = os.root / "windows" / "system32" / "drivers" / "etc" / "hosts"
response = quickRequest
  .post(uri"$uriBase/post")
  .body(hostsFile.toNIO)
  .send()

response.body
