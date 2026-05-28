package tech.techstay.chainofresponsibility;

import java.util.List;

public interface Filter {
  void doFilter(Request request, Response response, FilterChain chain);
}


class FilterChain {
  private List<Filter> filters;
  private int current;

  public FilterChain(List<Filter> filters) {
    this.filters = filters;
    current = 0;
  }

  void doFilter(Request request, Response response) {
    if (current <= filters.size() - 1) {
      Filter currentFilter = filters.get(current);
      current++;
      currentFilter.doFilter(request, response, this);
    } else {
      current = 0;
    }
  }
}


class FilterImpl1 implements Filter {

  @Override
  public void doFilter(Request request, Response response, FilterChain chain) {
    System.out.println("In filter1: " + request.getMessage() + " -> " + response.getMessage());
    chain.doFilter(request, response);
  }
}


class FilterImpl2 implements Filter {

  @Override
  public void doFilter(Request request, Response response, FilterChain chain) {
    System.out.println("In filter2: " + request.getMessage() + " -> " + response.getMessage());
    chain.doFilter(request, response);
  }
}


class FilterImpl3 implements Filter {

  @Override
  public void doFilter(Request request, Response response, FilterChain chain) {
    System.out.println("In filter3: " + request.getMessage() + " -> " + response.getMessage());
  }
}
