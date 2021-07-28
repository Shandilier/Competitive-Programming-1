package com.Sachin.cache.Policy;

import com.Sachin.algorithms.DoublyLinkedList;
import com.Sachin.algorithms.DoublyLinkedListNode;
import com.Sachin.cache.Exception.InvalidElementException;

import java.util.HashMap;
import java.util.Map;

public class LRUEvictionPolicy<Key> implements EvictionPolicy<Key> {
    private DoublyLinkedList<Key> doublyLinkedList;
    private Map<Key,DoublyLinkedListNode<Key> >mapper;

    public LRUEvictionPolicy() {
        this.doublyLinkedList = new DoublyLinkedList<Key>();
        this.mapper = new HashMap<Key, DoublyLinkedListNode<Key>>();
    }

    @Override
    public void keyAccessed(Key key) throws InvalidElementException {
        if(mapper.containsKey(key))
        {
            doublyLinkedList.detachNode(mapper.get(key));
            DoublyLinkedListNode<Key> temp = doublyLinkedList.addNodeAtLast(key);
        }
        else
        {
            DoublyLinkedListNode<Key> newNode = new DoublyLinkedListNode<Key>(key);
            mapper.put(key,newNode);

            System.out.println(newNode.getElement());
        }
    }

    @Override
    public Key evict() {
        DoublyLinkedListNode<Key> node = doublyLinkedList.getFirstNode();
        if(node==null)
            return null;
        doublyLinkedList.detachNode(node);
        return node.getElement();
    }
}
