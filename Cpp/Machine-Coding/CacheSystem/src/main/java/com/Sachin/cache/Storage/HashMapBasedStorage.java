package com.Sachin.cache.Storage;

import com.Sachin.cache.Exception.NotFoundException;
import com.Sachin.cache.Exception.StorageFullExxception;

import java.util.HashMap;
import java.util.Map;

public class HashMapBasedStorage<Key,Value> implements Storage<Key,Value>{

    public final int capacity;
    Map<Key,Value> storage;
    public HashMapBasedStorage(int capacity) {

        this.capacity = capacity;
//        storage = new HashMap<Key, Value>();
    }

    public boolean isStorageFull()
    {
        if(capacity == storage.size())
            return true;
        return false;
    }
    public void add(Key key, Value value) throws StorageFullExxception {
        if(isStorageFull()) {
            throw new StorageFullExxception("No space left...");
        }
        storage.put(key,value);
    }

    public void remove(Key key) throws NotFoundException {
        if(!storage.containsKey(key))
        {
            throw new NotFoundException("No key found...");
        }
        System.out.println("Removed key {}"+ key);
        storage.remove(key);

    }

    public Value get(Key key) throws NotFoundException {
        if(!storage.containsKey(key)) {
            throw new NotFoundException("No key found...");
        }
        System.out.println("Found key {}"+ key);
        return storage.get(key);
    }
}
