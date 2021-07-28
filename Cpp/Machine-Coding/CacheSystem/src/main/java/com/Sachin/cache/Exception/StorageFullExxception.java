package com.Sachin.cache.Exception;

public class StorageFullExxception extends Throwable {
    private String result;
    public StorageFullExxception(String s) {
        this.result = s;
    }

    @Override
    public String toString() {
        return "StorageFullExxception {} " + result;
    }
}
