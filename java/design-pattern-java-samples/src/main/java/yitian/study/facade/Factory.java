package yitian.study.facade;

public class Factory {
    public Product produce(Request request){
        Product product=new Product(request.getMsg());
        return product;
    }
}
