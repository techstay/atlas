package yitian.study.interpreter;

import yitian.study.Sample;

public class InterpreterSample implements Sample {
    @Override
    public void run() {
        Variable a = new Variable();
        Variable b = new Variable();
        Context context = new Context();
        context.putValue(a, 3);
        context.putValue(b, 4);

        //a+b*(a-b)+2
        Expression expression = new Add(a, new Add(new Mul(b, new Sub(a, b)), new Constant(2)));
        System.out.println("a+b*(a-b)+2=" + expression.interpret(context));
    }
}
