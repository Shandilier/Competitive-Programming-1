package com.Sachin;

import com.Sachin.cache.Factory.CacheFactory;

public class Main {
    public static void main(String[] args)
    {
        System.out.println("Hello");
        CacheFactory cacheFactory = new CacheFactory();
        cacheFactory.defaultCache(5);

    }
}
