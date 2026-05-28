package tech.techstay.memento;

public class MementoSample {
  public static void main(String[] args) {
    Document document = new Document("content");
    document.setContent("content1");
    document.autoSave();

    document.setContent("content2");
    document.autoLoad();
    System.out.println("上次结果: " + document.getContent());
  }
}
