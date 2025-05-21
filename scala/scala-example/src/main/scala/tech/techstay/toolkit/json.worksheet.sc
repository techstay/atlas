import upickle.default.*

// serializing objects to json
case class Employee(
    id: Int,
    name: String,
    age: Int,
    contacts: List[String]
) derives ReadWriter

val employee = Employee(
  id = 1,
  name = "techstay",
  age = 18,
  contacts = List("1234", "12345", "1234567")
)

val json = write(employee)

// deserializing json to objects
val employee2 = read[Employee](json)

// accessing json properties
val jsonObject = ujson.read(json)
jsonObject("name").str
jsonObject("age").num
jsonObject("contacts").arr
