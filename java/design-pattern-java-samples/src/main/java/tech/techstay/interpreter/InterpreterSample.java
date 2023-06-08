package tech.techstay.interpreter;

public class InterpreterSample {
  public static void main(String[] args) {
    Variable a = new Variable();
    Variable b = new Variable();
    Context context = new Context();
    context.putValue(a, 3);
    context.putValue(b, 4);

    Expression expression = new Add(a, new Add(new Mul(b, new Sub(a, b)), new Constant(2)));
    System.out.println("a+b*(a-b)+2=" + expression.interpret(context));
  }
}
