package com.Sachin.cache.Factory;

import com.Sachin.cache.Cache;
import com.Sachin.cache.Policy.LRUEvictionPolicy;
import com.Sachin.cache.Storage.HashMapBasedStorage;

public class CacheFactory<Key,Value> {
    public CacheFactory() {
        System.out.println("Constructor of CacheFactory");
    }
    public Cache<Key,Value> defaultCache(int capacity){
        System.out.println(capacity);
        return new Cache<Key, Value>(new LRUEvictionPolicy<Key>(), new HashMapBasedStorage<Key,Value>(capacity));
    }
}
