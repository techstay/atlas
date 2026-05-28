package tech.techstay.memento;

public class Document {
  private String content;
  private DocumentManager documentManager = new DocumentManager();
  private int editCount = 0;
  private int autosaveId = 0;

  public Document(String content) {

    this.content = content;
  }

  public String getContent() {
    return content;
  }

  public void setContent(String content) {
    this.content = content;
    editCount++;
  }

  public void save(int id) {
    documentManager.saveDocument(id, content);
  }

  public void autoSave() {
    autosaveId = editCount;
    documentManager.saveDocument(editCount, content);
  }

  public void load(int id) {
    content = documentManager.loadDocument(id);
  }


  public void autoLoad() {
    content = documentManager.loadDocument(autosaveId);
  }

}
