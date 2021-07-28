package com.Sachin.algorithms;


public class DoublyLinkedListNode<E> {
    public DoublyLinkedListNode<E> prev;
    public DoublyLinkedListNode<E> next;
    private E element;

    public DoublyLinkedListNode(E element) {
        this.next = null;
        this.prev = null;
        this.element = element;
    }

    public E getElement() {
        return element;
    }

    public void setElement(E element) {
        this.element = element;
    }
}

