package com.Sachin.cache;
import static org.junit.jupiter.api.Assertions.*;
import com.Sachin.cache.Exception.InvalidElementException;
import com.Sachin.cache.Policy.LRUEvictionPolicy;
import junit.framework.TestCase;
import org.junit.Test;

public class EvictionPolicyTest{

//    LRUEvictionPolicy<Integer> lruEvictionPolicy;
//
//    public EvictionPolicyTest(LRUEvictionPolicy<Integer> lruEvictionPolicy) {
//        this.lruEvictionPolicy = lruEvictionPolicy;
//    }

    @Test
    public void testNoEviction()
    {
        LRUEvictionPolicy<Integer> lruEvictionPolicy = new LRUEvictionPolicy<Integer>();
        assertNull(lruEvictionPolicy.evict());
    }

    @Test
    public void testEvictionPolicy() throws InvalidElementException {
        LRUEvictionPolicy<Integer> lruEvictionPolicy = new LRUEvictionPolicy<Integer>();
        lruEvictionPolicy.keyAccessed(1);
        lruEvictionPolicy.keyAccessed(2);
        lruEvictionPolicy.keyAccessed(3);
        lruEvictionPolicy.keyAccessed(4);
        assertEquals(1,lruEvictionPolicy.evict());
    }
}