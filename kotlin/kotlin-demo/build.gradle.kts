plugins {
    // Apply the org.jetbrains.kotlin.jvm Plugin to add support for Kotlin.
    id("org.jetbrains.kotlin.jvm") version "1.8.10"
    id("org.jetbrains.kotlinx.benchmark") version "latest.release"
    kotlin("plugin.serialization") version "latest.release"
}

repositories {
    // Use Maven Central for resolving dependencies.
    mavenCentral()
}

dependencies {
    // Use the Kotlin JUnit 5 integration.
    testImplementation("org.jetbrains.kotlin:kotlin-test-junit5")

    // Use the JUnit 5 integration.
    testImplementation("org.junit.jupiter:junit-jupiter-engine:5.9.1")

    // This dependency is used by the application.
    implementation("com.google.guava:guava:31.1-jre")

    // assertion library
    implementation("com.google.truth:truth:latest.release")

    // coroutines
    implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:latest.release")
    // reflections
    implementation("org.jetbrains.kotlin:kotlin-reflect:latest.release")
    // serialization
    implementation("org.jetbrains.kotlinx:kotlinx-serialization-json:latest.release")
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(17))
    }
}

tasks.named<Test>("test") {
    // Use JUnit Platform for unit tests.
    useJUnitPlatform()
}
