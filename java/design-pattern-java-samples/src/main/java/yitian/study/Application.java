package yitian.study;


import yitian.study.abstractfactory.AbstractFactorySample;
import yitian.study.adapter.AdapterSample;
import yitian.study.bridge.BridgeSample;
import yitian.study.builder.BuilderSample;
import yitian.study.chainofresponsability.ChainOfResponsabilitySample;
import yitian.study.command.CommandSample;
import yitian.study.composite.CompositeSample;
import yitian.study.decorator.DecoratorSample;
import yitian.study.facade.FacadeSample;
import yitian.study.factory.FactorySample;
import yitian.study.filter.FilterSample;
import yitian.study.flyweight.FlyWeightSample;
import yitian.study.interator.IteratorSample;
import yitian.study.interpreter.InterpreterSample;
import yitian.study.mediator.MediatorSample;
import yitian.study.memento.MementoSample;
import yitian.study.observer.ObserverSample;
import yitian.study.prototype.PrototypeSample;
import yitian.study.proxy.ProxySample;
import yitian.study.state.StateSample;
import yitian.study.strategy.StrategySample;
import yitian.study.template.TemplateSample;
import yitian.study.visitor.VisitorSample;

public class Application {
    public static void main(String[] args) {
        System.out.println("23种设计模式");
        System.out.println("工厂模式");
        Sample factorySample = new FactorySample();
        factorySample.run();

        System.out.println("抽象工厂模式");
        Sample abstractFactorySample = new AbstractFactorySample();
        abstractFactorySample.run();

        System.out.println("建造者模式");
        Sample builderSample = new BuilderSample();
        builderSample.run();

        System.out.println("原型模式");
        Sample prototypeSample = new PrototypeSample();
        prototypeSample.run();

        System.out.println("适配器模式");
        Sample adapterSample = new AdapterSample();
        adapterSample.run();

        System.out.println("桥接模式");
        Sample bridgeSample = new BridgeSample();
        bridgeSample.run();

        System.out.println("过滤器模式");
        Sample filterSample = new FilterSample();
        filterSample.run();

        System.out.println("组合模式");
        Sample compositeSample = new CompositeSample();
        compositeSample.run();

        System.out.println("装饰器模式");
        Sample decoratorSample = new DecoratorSample();
        decoratorSample.run();

        System.out.println("外观模式");
        Sample facadeSample = new FacadeSample();
        facadeSample.run();

        System.out.println("享元模式");
        Sample flyweightSample = new FlyWeightSample();
        flyweightSample.run();

        System.out.println("代理模式");
        Sample proxySample = new ProxySample();
        proxySample.run();

        System.out.println("责任链模式");
        Sample chainOfResponsibilitySample=new ChainOfResponsabilitySample();
        chainOfResponsibilitySample.run();

        System.out.println("命令模式");
        Sample commandSample=new CommandSample();
        commandSample.run();

        System.out.println("解释器模式");
        Sample interpreterSample=new InterpreterSample();
        interpreterSample.run();

        System.out.println("迭代器模式");
        Sample iteratorSample=new IteratorSample();
        iteratorSample.run();

        System.out.println("中介者模式");
        Sample mediatorSample=new MediatorSample();
        mediatorSample.run();

        System.out.println("备忘录模式");
        Sample mementoSample=new MementoSample();
        mementoSample.run();

        System.out.println("观察者模式");
        Sample observerSample=new ObserverSample();
        observerSample.run();

        System.out.println("状态模式");
        Sample stateSample=new StateSample();
        stateSample.run();

        System.out.println("策略模式");
        Sample strategySample=new StrategySample();
        strategySample.run();

        System.out.println("模板模式");
        Sample templateSample=new TemplateSample();
        templateSample.run();

        System.out.println("访问者模式");
        Sample visitorSample=new VisitorSample();
        visitorSample.run();
    }
}
