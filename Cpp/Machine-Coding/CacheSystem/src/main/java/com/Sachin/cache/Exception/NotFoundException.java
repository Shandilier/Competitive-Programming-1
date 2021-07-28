package com.Sachin.cache.Exception;

public class NotFoundException extends Throwable {
    private String result;

    public NotFoundException(String s) {
        this.result = s;
    }

    @Override
    public String toString() {
        return "NotFoundException {} " + result;
    }
}
