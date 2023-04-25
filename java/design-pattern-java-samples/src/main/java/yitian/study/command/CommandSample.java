package yitian.study.command;

import yitian.study.Sample;

public class CommandSample implements Sample {
    @Override
    public void run() {
        RequirementChecker javaChecker = new JavaCommand();
        if (javaChecker.isReady()) {
            System.out.println(javaChecker.getInfo());
        }

        RequirementChecker pythonChecker = new PythonCommand();
        if (pythonChecker.isReady()) {
            System.out.println(pythonChecker.getInfo());
        }

        RequirementChecker windowsChecker = new WindowsCommand();
        if (windowsChecker.isReady()) {
            System.out.println(windowsChecker.getInfo());
        }

        RequirementChecker badChecker = new BadCommand();
        if (badChecker.isReady()) {
            System.out.println(badChecker.getInfo());
        }
    }
}
