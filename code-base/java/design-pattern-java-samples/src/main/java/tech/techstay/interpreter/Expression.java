package tech.techstay.interpreter;

public interface Expression {
  int interpret(Context context);
}


class Constant implements Expression {
  private int i;

  public Constant(int i) {
    this.i = i;
  }

  @Override
  public int interpret(Context context) {
    return i;
  }
}


class Variable implements Expression {
  @Override
  public int interpret(Context context) {
    return context.getValue(this);
  }
}


class Add implements Expression {
  private Expression a;
  private Expression b;

  public Add(Expression a, Expression b) {
    this.a = a;
    this.b = b;
  }

  @Override
  public int interpret(Context context) {
    return a.interpret(context) + b.interpret(context);
  }
}


class Sub implements Expression {
  private Expression a;
  private Expression b;

  public Sub(Expression a, Expression b) {
    this.a = a;
    this.b = b;
  }

  @Override
  public int interpret(Context context) {
    return a.interpret(context) - b.interpret(context);
  }
}


class Mul implements Expression {
  private Expression a;
  private Expression b;

  public Mul(Expression a, Expression b) {
    this.a = a;
    this.b = b;
  }

  @Override
  public int interpret(Context context) {
    return a.interpret(context) * b.interpret(context);
  }
}


class Div implements Expression {
  private Expression a;
  private Expression b;

  public Div(Expression a, Expression b) {
    this.a = a;
    this.b = b;
  }

  @Override
  public int interpret(Context context) {
    return a.interpret(context) / b.interpret(context);
  }
}
