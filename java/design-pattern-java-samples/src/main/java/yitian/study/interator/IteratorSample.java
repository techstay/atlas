package yitian.study.interator;

import yitian.study.Sample;

import java.util.ArrayList;
import java.util.Enumeration;

public class IteratorSample implements Sample {
    @Override
    public void run() {
        int[] array = {1, 2, 3, 4, 5, 6};
        MyCollection myCollection = new MyCollection(array);

        Iterator iterator = myCollection.getIterator();
        while (iterator.hasNext()) {
            System.out.printf("%d ", iterator.next());
        }
        System.out.println();
    }
}
