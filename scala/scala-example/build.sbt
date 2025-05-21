val toolkitVersion = "0.7.0"

ThisBuild / version := "0.1.0-SNAPSHOT"
ThisBuild / scalaVersion := "3.7.1"

lazy val root = (project in file("."))
  .settings(
    name := "scala-example",
    libraryDependencies += "org.scala-lang" %% "toolkit" % toolkitVersion,
    libraryDependencies += "org.scala-lang" %% "toolkit-test" % toolkitVersion % Test,
    // https://mvnrepository.com/artifact/org.apache.logging.log4j/log4j-core
    libraryDependencies += "org.apache.logging.log4j" % "log4j-core" % "2.24.3",
    libraryDependencies += "org.scala-lang.modules" %% "scala-parallel-collections" % "1.2.0"
  )
