package yitian.study.interator;

public class MyCollection implements Iterable {
    private int[] array;

    public MyCollection(int[] array) {
        this.array = array;
    }

    @Override
    public Iterator getIterator() {
        return new MyCollectionIterator(array);
    }
}

class MyCollectionIterator implements Iterator {
    private int[] array;
    private int current;

    public MyCollectionIterator(int[] array) {
        this.array = array;
        current = -1;
    }

    @Override
    public boolean hasNext() {
        return current <= array.length - 2;
    }

    @Override
    public int next() {
        return array[++current];
    }
}