package yitian.study.memento;

import yitian.study.Sample;

public class MementoSample implements Sample {
    @Override
    public void run() {
        Document document = new Document("content");
        document.setContent("content1");
        document.autosave();

        document.setContent("content2");
        document.autoload();
        System.out.println("上次结果:" + document.getContent());
    }
}
