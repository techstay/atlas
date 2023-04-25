package yitian.study.mediator;

public class User {
    private String name;

    public User(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void sendMessage(Message message, ChatRoom chatRoom) {
        chatRoom.sendMessage(message);
    }
}
