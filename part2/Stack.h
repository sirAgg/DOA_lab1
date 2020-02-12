#ifndef __STACK_H_
#define __STACK_H_

#include <cstring>
#include <iostream>

#define STACK_DEFAULT_SIZE 64

template<typename T>
class Stack
{
public:
    Stack(int size);
    Stack();
    ~Stack();

    void push(T element);
    T& peek();
    void pop();

    int size();
    void print();

private:
    T* data;
    int block_size = 0;
    int top_idx = -1;
};

template<typename T>
void Stack<T>::print()
{
    for(int i = 0; i<=top_idx; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}


template<typename T>
Stack<T>::Stack(int size) : block_size(size)
{
    data = new T[block_size];
}

template<typename T>
Stack<T>::Stack() : Stack(STACK_DEFAULT_SIZE)
{}

template<typename T>
Stack<T>::~Stack()
{
    delete[] data;
}

template<typename T>
void Stack<T>::push(T element)
{
    if(top_idx == block_size -1)
    {
        // reallocate array and copy over current data
        // the array size is doubled every time it's
        // reallocated
        T* tmp = new T[block_size*2];
        memcpy(tmp, data, (top_idx+1)*sizeof(T));
        delete[] data;
        data = tmp;
        block_size *= 2;
        // std::cout << "reallocating stack: " << block_size << " | " << size() << "\n";
    }

    top_idx++;
    data[top_idx] = element;
}

template<typename T>
T& Stack<T>::peek()
{
    return data[top_idx];
}

template<typename T>
void Stack<T>::pop()
{
    if(top_idx >= 0)
        top_idx--;
}

template<typename T>
int Stack<T>::size()
{
    return top_idx +1;
}


#endif // __STACK_H_
