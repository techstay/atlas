package yitian.study.mediator;

import java.time.LocalDateTime;

public class Message {
    private User from;
    private User to;
    private LocalDateTime originDate;
    private String message;

    public Message(User from, User to, String message) {
        this.from = from;
        this.to = to;
        this.message = message;
        originDate = LocalDateTime.now();
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Message{");
        sb.append("from=").append(from.getName());
        sb.append(", to=").append(to.getName());
        sb.append(", originDate=").append(originDate);
        sb.append(", message='").append(message).append('\'');
        sb.append('}');
        return sb.toString();
    }
}
