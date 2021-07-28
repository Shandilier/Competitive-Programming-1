package com.Sachin.cache;

import com.Sachin.cache.Exception.InvalidElementException;
import com.Sachin.cache.Exception.NotFoundException;
import com.Sachin.cache.Exception.StorageFullExxception;
import com.Sachin.cache.Policy.LRUEvictionPolicy;
import com.Sachin.cache.Storage.HashMapBasedStorage;

public class Cache<Key,Value> {
    LRUEvictionPolicy<Key> lruEvictionPolicy;
    HashMapBasedStorage<Key,Value> hashMapBasedStorage;

    public Cache(LRUEvictionPolicy<Key> keyLRUEvictionPolicy, HashMapBasedStorage<Key, Value> keyValueHashMapBasedStorage) {
        this.hashMapBasedStorage = keyValueHashMapBasedStorage;
        this.lruEvictionPolicy = keyLRUEvictionPolicy;
    }
    public void put(Key key, Value value) throws NotFoundException, InvalidElementException {
        try{
            hashMapBasedStorage.add(key,value);
            lruEvictionPolicy.keyAccessed(key);
        }
        catch (StorageFullExxception storageFullExxception) {
            storageFullExxception.printStackTrace();
            Key keyToRemove = lruEvictionPolicy.evict();
            if (keyToRemove == null) {
                throw new RuntimeException("Unexpected error..storage is full and no key found");
            }
            lruEvictionPolicy.keyAccessed(keyToRemove);
        } catch (InvalidElementException e) {
            e.printStackTrace();
        }
    }

    public Value get(Key key) throws InvalidElementException {
        try
        {
            Value value = hashMapBasedStorage.get(key);
            lruEvictionPolicy.keyAccessed(key);
            return value;
        }
        catch (NotFoundException notFoundException)
        {
            notFoundException.printStackTrace();
            return null;
        }
    }

}
