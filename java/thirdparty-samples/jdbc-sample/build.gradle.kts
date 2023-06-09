plugins {
    id("java")
}

group = "tech.techstay"
version = "unspecified"

repositories {
    mavenCentral()
}

dependencies {
    implementation("org.apache.logging.log4j:log4j-api:latest.release")
    implementation("org.apache.logging.log4j:log4j-core:latest.release")
    implementation("mysql:mysql-connector-java:latest.release")
    implementation("net.datafaker:datafaker:latest.release")

    testImplementation(platform("org.junit:junit-bom:latest.release"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    testImplementation("org.assertj:assertj-core:latest.release")
}

tasks.test {
    useJUnitPlatform()
}
