package com.Sachin.cache.Storage;

import com.Sachin.cache.Exception.NotFoundException;
import com.Sachin.cache.Exception.StorageFullExxception;

public interface Storage<Key,Value> {
    public void add(Key key, Value value) throws StorageFullExxception;

    public void remove(Key key) throws NotFoundException;

    public Value get(Key key) throws NotFoundException;
}
