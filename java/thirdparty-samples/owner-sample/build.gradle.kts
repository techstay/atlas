plugins {
    id("java")
}

group = "tech.techstay"
version = "1.0"

repositories {
    mavenCentral()
}

dependencies {
    implementation("org.aeonbits.owner:owner-java8:latest.release")
    implementation("org.apache.logging.log4j:log4j-api:latest.release")
    implementation("org.apache.logging.log4j:log4j-core:latest.release")

    testImplementation(platform("org.junit:junit-bom:latest.release"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    testImplementation("org.assertj:assertj-core:latest.release")
}

tasks.test {
    useJUnitPlatform()
}
