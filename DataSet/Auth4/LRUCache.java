package lru_cache;

import java.util.LinkedHashMap;
import java.util.Map;

public class LRUCache {
    private LinkedHashMap<Integer, Integer> map;

    @SuppressWarnings("serial")
    public LRUCache(final int capacity) {
        assert capacity > 0;
        map = new LinkedHashMap<Integer, Integer>(16, 0.75f, true) {
            protected boolean removeEldestEntry(
                    Map.Entry<Integer, Integer> eldest) {
                return size() > capacity;
            }
        };
    }

    public int get(int key) {
        Integer value = map.get(key);
        if (value == null) {
            return -1;
        }
        return value;
    }

    public void set(int key, int value) {
        map.put(key, value);
    }
}
