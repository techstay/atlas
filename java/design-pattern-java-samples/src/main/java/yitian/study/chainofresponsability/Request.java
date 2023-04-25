package yitian.study.chainofresponsability;

public interface Request {
    String getMessage();
}

class RequestImpl implements Request{
private String msg;

    public RequestImpl(String msg) {
        this.msg = msg;
    }

    @Override
    public String getMessage() {
        return msg;
    }
}