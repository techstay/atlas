plugins {
  id("groovy")
}

group = "tech.techstay"
version = "1.0-SNAPSHOT"

repositories {
  mavenCentral()
}

dependencies {
  implementation(fileTree("C:/Users/asddf/scoop/apps/groovy/current/lib") {
    include("*.jar")
    include("*/*.jar")
  })
  implementation("org.hsqldb:hsqldb:latest.release")
  testImplementation(platform("org.junit:junit-bom:5.9.1"))
  testImplementation("org.junit.jupiter:junit-jupiter")
}

tasks.test {
  useJUnitPlatform()
}
