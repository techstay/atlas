plugins {
    id("java")
}

group = "tech.techstay"
version = "1.0"

repositories {
    mavenCentral()
}

dependencies {
    implementation("net.datafaker:datafaker:latest.release")
    testImplementation(platform("org.junit:junit-bom:latest.release"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    testImplementation("org.assertj:assertj-core:latest.release")
}

tasks.test {
    useJUnitPlatform()
}
