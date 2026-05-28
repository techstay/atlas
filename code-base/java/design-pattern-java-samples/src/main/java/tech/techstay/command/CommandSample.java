package tech.techstay.command;

public class CommandSample {
  public static void main(String[] args) {
    RequirementChecker javaChecker = new JavaCommand();
    if (javaChecker.available()) {
      System.out.println(javaChecker.getInfo());
    }

    RequirementChecker pythonChecker = new PythonCommand();
    if (pythonChecker.available()) {
      System.out.println(pythonChecker.getInfo());
    }

    RequirementChecker windowsChecker = new WindowsCommand();
    if (windowsChecker.available()) {
      System.out.println(windowsChecker.getInfo());
    }

    RequirementChecker badChecker = new BadCommand();
    if (badChecker.available()) {
      System.out.println(badChecker.getInfo());
    }
  }
}
