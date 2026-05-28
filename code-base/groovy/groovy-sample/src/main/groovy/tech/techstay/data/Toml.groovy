package tech.techstay.data

import groovy.toml.TomlBuilder
import groovy.toml.TomlSlurper

def builder = new TomlBuilder()
builder.Person {
  name 'techstay'
  age 22
  nickname 'lele'
}
def toml = builder.toString()
println(toml)

def slurper = new TomlSlurper()
def obj = slurper.parseText(toml)
assert obj instanceof Map
println(obj)

