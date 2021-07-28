package com.Sachin.algorithms;
import com.google.common.collect.ImmutableList;

import com.Sachin.cache.Exception.InvalidElementException;
import jdk.nashorn.internal.ir.annotations.Immutable;
import junit.framework.TestCase;
import org.junit.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class DoublyLinkedListTest{

    @Test
    public void testDLLAddition() throws InvalidElementException {
        DoublyLinkedList<Integer> dll = new DoublyLinkedList<Integer>();
        DoublyLinkedListNode<Integer> node1 = dll.addNodeAtLast(10);
        DoublyLinkedListNode<Integer> node2 = dll.addNodeAtLast(20);
        DoublyLinkedListNode<Integer> node3 = dll.addNodeAtLast(30);
        DoublyLinkedListNode<Integer> node4 = dll.addNodeAtLast(40);

//        dll.addNodeAtLast(node1.element);
//        dll.addNodeAtLast(node2.element);
        assertEquals(dll.getFirstNode().getElement(),10);
    }

    @Test
    public void testNodeDetachment() throws InvalidElementException {
        DoublyLinkedList<Integer> dll = new DoublyLinkedList<Integer>();
        DoublyLinkedListNode<Integer> node1 = dll.addNodeAtLast(10);
        DoublyLinkedListNode<Integer> node2 = dll.addNodeAtLast(20);
        DoublyLinkedListNode<Integer> node3 = dll.addNodeAtLast(30);
        DoublyLinkedListNode<Integer> node4 = dll.addNodeAtLast(40);
        verifyDll(dll, ImmutableList.of(10,20,30,40));
        dll.detachNode(node1);
//        verifyDLL()
//        assertEquals(dll.getFirstNode().getElement(),20);
    }

    public void verifyDll(DoublyLinkedList<Integer> dll, List<Integer> list)
    {

        DoublyLinkedListNode<Integer> node = dll.getFirstNode();
        assertNotNull(node);
        assertEquals(node.getElement(),list.get(0));
        for(Integer l : list)
        {
            assertEquals(node.getElement(),l);
            node = node.next;
        }
    }
}