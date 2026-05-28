package tech.techstay.mediator;

public class MediatorSample {
  public static void main(String[] args) {
    ChatRoom chatRoom = new ChatRoom();
    User u1 = new User("techstay");
    User u2 = new User("leo");

    u1.sendMessage(new Message(u1, u2, "Hello leo"), chatRoom);
    u2.sendMessage(new Message(u2, u1, "I'm fine, thank you"), chatRoom);

  }
}
