package tech.techstay.chainofresponsibility;

public interface Response {
  String getMessage();
}


class ResponseImpl implements Response {
  private String msg;

  public ResponseImpl(String msg) {
    this.msg = msg;
  }

  @Override
  public String getMessage() {
    return msg;
  }
}
