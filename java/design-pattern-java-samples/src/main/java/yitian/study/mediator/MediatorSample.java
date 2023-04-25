package yitian.study.mediator;

import yitian.study.Sample;

public class MediatorSample implements Sample {
    @Override
    public void run() {
        ChatRoom chatRoom = new ChatRoom();
        User yitian = new User("yitian");
        User leo = new User("leo");

        yitian.sendMessage(new Message(yitian, leo, "Hello leo"), chatRoom);
        leo.sendMessage(new Message(leo, yitian, "I'm fine, thank you"), chatRoom);

    }
}
