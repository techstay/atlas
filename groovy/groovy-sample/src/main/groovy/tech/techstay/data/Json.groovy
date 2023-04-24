package tech.techstay.data

import groovy.json.JsonGenerator
import groovy.json.JsonOutput
import groovy.json.JsonSlurper

// parse json to objects
def slurper = new JsonSlurper()

def obj = slurper.parseText('{"name":"techstay","age":18}')
assert obj instanceof Map
assert obj == [name: 'techstay', age: 18]

obj = slurper.parseText('{"list":[1,2,3,4,5]}')
assert obj.list instanceof List
assert obj.list == [1, 2, 3, 4, 5]

// parse objects to json
def generator = new JsonGenerator.Options()
  .excludeNulls()
  .build()
def json = JsonOutput.toJson([name: 'techstay', age: 18])
// pretty formatted json
println(JsonOutput.prettyPrint(json))
// raw json
println(generator.toJson([list: [1, 2, 3, 4, 5]]))
