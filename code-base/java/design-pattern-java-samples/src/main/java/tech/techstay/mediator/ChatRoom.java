package tech.techstay.mediator;

import java.util.ArrayList;
import java.util.List;

public class ChatRoom {
  private List<Message> messages = new ArrayList<>();

  public void sendMessage(Message message) {
    messages.add(message);
    System.out.println(message);
  }
}
