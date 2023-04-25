package yitian.study.visitor;

import yitian.study.Sample;

public class VisitorSample implements Sample {
    @Override
    public void run() {
        Visitor visitor = new HouseVisitor();
        House house = new House();
        visitor.visit(house);
    }
}
