package yitian.study.proxy;

public class StringResource implements Resource {
    private String content;

    public StringResource(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String getResource() {
        return content;
    }
}
