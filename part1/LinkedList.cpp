#include "LinkedList.h"
#include <stdio.h>


template <typename T>
ListIter<T>::ListIter(Node<T>* start)
    :current(start)
{}

template <typename T>
T* ListIter<T>::next()
{
    if(!current)
    {
        return nullptr;
    }

    T* tmp = &(current->data);
    current = current->next;
    return tmp;
}




template <typename T>
LinkedList<T>::~LinkedList()
{
    while(head)
    {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void LinkedList<T>::add_first(T data)
{
    // inserts new element in first position
    Node<T>* tmp = new Node<T>;
    tmp->next = head;
    tmp->data = data;
    head = tmp;

    if(size == 0)
        tail = tmp;

    size++;
}

template <typename T>
void LinkedList<T>::add_last(T data)
{
    // inserts new element in last position
    Node<T>* tmp = new Node<T>;
    if(size != 0)
    {
        tail->next = tmp;
        tmp->data = data;
        tail = tmp;
    }
    else
    {
        head = tmp;
        tail = tmp;
        tmp->data = data;
    }

    size++;
}

template <typename T>
bool LinkedList<T>::add(T data, int idx)
{
    if(idx == 0)
    {
        add_first(data);
        return true;
    }
    if(idx == size)
    {
        add_last(data);
        return true;
    }

    Node<T>* target = at(idx-1);
    if(!target)
        return false;

    Node<T>* tmp = new Node<T>;
    tmp->next = target->next;
    tmp->data = data;
    target->next = tmp;
    size++;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(int idx)
{
    Node<T>* tmp;
    if(idx == 0)
    {
        if(head == nullptr)
        {
            return false;
        }
        tmp = head;
        head = head->next;
        if(size == 1)
            tail = head;
    }
    else
    {
        Node<T>* target = at(idx-1);
        if(target == nullptr || target->next == nullptr)
        {
            return false;
        }

        tmp = target->next;
        target->next = tmp->next;

        if(idx == size-1)
            tail = target;
    }

    delete tmp;
    size--;
    return true;
}

template <typename T>
T* LinkedList<T>::get(int idx)
{
    Node<T>* tmp= at(idx);
    if(tmp != nullptr)
        return &(at(idx)->data);
    else
        return nullptr;
}

template <typename T>
ListIter<T> LinkedList<T>::get_iter()
{
    return ListIter<T>(head);
}

template <typename T>
unsigned int LinkedList<T>::get_size()
{
    return size;
}

template <typename T>
Node<T>* LinkedList<T>::at(int idx)
{
    Node<T>* current = head;
    int i = 0;

    while(i < idx)
    {
        if(!current)
            return nullptr;
        current = current->next;
        i++;
    }

    return current;
}
