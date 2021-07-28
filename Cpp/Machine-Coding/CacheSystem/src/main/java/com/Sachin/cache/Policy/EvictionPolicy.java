package com.Sachin.cache.Policy;

import com.Sachin.cache.Exception.InvalidElementException;

public interface EvictionPolicy<Key> {
    public void keyAccessed(Key key) throws InvalidElementException;

    public Key evict();
}
