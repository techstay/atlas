val toolkitV = "0.7.0"
val toolkit = "org.scala-lang" %% "toolkit" % toolkitV
val toolkitTest = "org.scala-lang" %% "toolkit-test" % toolkitV

ThisBuild / scalaVersion := "3.7.0"
libraryDependencies += toolkit
libraryDependencies += (toolkitTest % Test)
