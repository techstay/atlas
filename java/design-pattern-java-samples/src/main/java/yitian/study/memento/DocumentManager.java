package yitian.study.memento;

import java.util.HashMap;
import java.util.Map;

public class DocumentManager {
    private Map<Integer, String> map = new HashMap<>();

    public void saveDocument(int id, String content) {
        map.put(id, content);
    }

    public String loadDocument(int id) {
        return map.get(id);
    }

}
