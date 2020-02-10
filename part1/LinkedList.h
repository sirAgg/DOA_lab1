#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

template <typename T>
struct Node
{
    Node<T>* next = nullptr;
    T data;
};

// iterator for the list
template <typename T>
struct ListIter
{
    ListIter(Node<T>* start);
    T* next();
private:
    Node<T>* current = nullptr;
};

template <typename T>
class LinkedList
{
public:
    ~LinkedList();
    void add_first(T data);
    void add_last(T data);
    bool add(T data, int idx);
    bool remove(int idx);
    T* get(int idx);
    ListIter<T> get_iter();
    unsigned int get_size();

private:
    Node<T>* at(int idx);

    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    unsigned int size = 0;
};

#include "LinkedList.cpp"

#endif // __LINKEDLIST_H_
