package com.Sachin.algorithms;

import com.Sachin.cache.Exception.InvalidElementException;

public class DoublyLinkedList<E>{
    DoublyLinkedListNode<E> head;
    DoublyLinkedListNode<E> tail;

    public DoublyLinkedList()
    {
        head = new DoublyLinkedListNode<E>(null);
        tail = new DoublyLinkedListNode<E>(null);

        head.next = tail;
        tail.prev = head;
    }

    public void detachNode(DoublyLinkedListNode<E> node)
    {
        if(node!=null)
        {
            node.prev.next = node.next;
            node.next.prev = node.prev;
        }
    }

    public DoublyLinkedListNode<E> addNodeAtLast(E element) throws InvalidElementException {
        if(element == null) {
            throw new InvalidElementException();
        }
        DoublyLinkedListNode<E> node = new DoublyLinkedListNode<E>(element);
        DoublyLinkedListNode temp = tail.prev;
        temp.next = node;
        node.prev = temp;
        node.next = tail;
        tail.prev = node;
        return node;
    }
    public DoublyLinkedListNode<E> getFirstNode()
    {
        if(NodeExists())
        {
            return head.next;
        }
        return null;
    }
    public boolean NodeExists()
    {
        if(head.next==tail)
            return false;
        return true;
    }
}
