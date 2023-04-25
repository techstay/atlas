package yitian.study.command;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.Collectors;

public abstract class AbstractCommand implements RequirementChecker {
    private ProcessBuilder processBuilder;
    private String info;
    private String encoding = "GBK";

    public AbstractCommand(String command) {
        processBuilder = new ProcessBuilder("cmd", "/C", command);
        processBuilder.redirectErrorStream(true);
    }

    @Override
    public boolean isReady() {
        Boolean result = false;
        try {
            Process process = processBuilder.start();
            process.waitFor();
            result = process.exitValue() == 0;
            if (result) {
                BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream(), encoding));
                info = reader.lines()
                        .collect(Collectors.joining("\n"));
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return result;
    }

    @Override
    public String getInfo() {
        return info;
    }
}

class PythonCommand extends AbstractCommand {

    public PythonCommand() {
        super("python --version");
    }
}

class JavaCommand extends AbstractCommand {
    public JavaCommand() {
        super("java -version");
    }
}

class WindowsCommand extends AbstractCommand {
    public WindowsCommand() {
        super("ver");
    }
}

class BadCommand extends AbstractCommand {
    public BadCommand() {
        super("fuck");
    }
}