package yitian.study.mediator;

import java.util.ArrayList;
import java.util.List;

public class ChatRoom {
    private List<Message> messages = new ArrayList<>();

    public void sendMessage(Message message) {
        System.out.println(message);
        messages.add(message);
    }
}
