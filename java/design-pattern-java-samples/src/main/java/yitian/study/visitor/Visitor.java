package yitian.study.visitor;

public interface Visitor {
    void visit(House house);

    void visit(Kitchen kitchen);

    void visit(LivingRoom livingRoom);

    void visit(BedRoom bedRoom);
}

class HouseVisitor implements Visitor {
    public void visit(House house) {
        System.out.println("访问了房子");
    }

    public void visit(BedRoom bedRoom) {
        System.out.println("访问了卧室");
    }

    public void visit(LivingRoom livingRoom) {
        System.out.println("访问了客厅");
    }

    public void visit(Kitchen kitchen) {
        System.out.println("访问了厨房");
    }
}
