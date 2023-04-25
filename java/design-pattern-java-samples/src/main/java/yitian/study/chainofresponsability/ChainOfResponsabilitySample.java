package yitian.study.chainofresponsability;

import yitian.study.Sample;

import java.util.ArrayList;
import java.util.List;

public class ChainOfResponsabilitySample implements Sample {
    @Override
    public void run() {
        Filter filter1 = new FilterImpl1();
        Filter filter2 = new FilterImpl2();
        List<Filter> filters = new ArrayList<>();
        filters.add(filter1);
        filters.add(filter2);
        FilterChain chain = new FilterChain(filters);

        Request request = new RequestImpl("request1");
        Response response = new ResponseImpl("response1");

        chain.doFilter(request, response);
        System.out.println();

        filters.add(0,new FilterImpl3());
        chain.doFilter(request, response);
    }
}
