package tech.techstay.data

import groovy.yaml.YamlBuilder
import groovy.yaml.YamlSlurper

def builder = new YamlBuilder()
builder.records {
  car {
    name 'HSV Maloo'
    make 'Holden'
    year 2006
    homepage new URL('http://example.org')
  }
}
def yaml = builder.toString()
println(yaml)

def slurper = new YamlSlurper()
def obj = slurper.parseText(yaml)
println(obj)
