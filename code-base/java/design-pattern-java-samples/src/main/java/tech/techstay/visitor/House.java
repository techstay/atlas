package tech.techstay.visitor;

public class House {
  private LivingRoom livingRoom;
  private Kitchen kitchen;
  private BedRoom bedRoom;

  public House() {
    livingRoom = new LivingRoom();
    kitchen = new Kitchen();
    bedRoom = new BedRoom();
  }

  public void accept(Visitor visitor) {
    visitor.visit(this);
    livingRoom.accept(visitor);
    bedRoom.accept(visitor);
    kitchen.accept(visitor);
  }
}


class LivingRoom {
  public void accept(Visitor visitor) {
    visitor.visit(this);
  }
}


class Kitchen {
  public void accept(Visitor visitor) {
    visitor.visit(this);
  }
}


class BedRoom {
  public void accept(Visitor visitor) {
    visitor.visit(this);
  }
}
