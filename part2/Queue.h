#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <cstring>
#include <iostream>

#define QUEUE_DEFAULT_SIZE 64

template <typename T>
class Queue
{
public:
    Queue(int size);
    Queue();
    ~Queue();

    void enqueue(T element);
    T& peek();
    void dequeue();

    int size();
    void print();

private:
    T* data;
    int block_size = 0;
    int begining = 0;
    int end = -1;
};

template<typename T>
void Queue<T>::print()
{
    for(int i = begining; i <= end; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
Queue<T>::Queue(int size) : block_size(size)
{
    data = new T[block_size];
}

template <typename T>
Queue<T>::Queue() : Queue(QUEUE_DEFAULT_SIZE)
{}

template<typename T>
Queue<T>::~Queue()
{
    delete[] data;
}

template<typename T>
void Queue<T>::enqueue(T element)
{
    if (end == block_size-1)
    {
        // reallocate array and copy over current data
        // the allocated size may shrink or grow depending on used size
        if(size() < block_size/4)
            block_size /= 2;
        else if (size() > block_size*3/4)
            block_size *= 2;

        T* tmp = new T[block_size];
        memcpy(tmp, data+begining, (end-begining+1)*sizeof(T));
        delete[] data;
        data = tmp;

        end = end-begining;
        begining = 0;
        // std::cout << "reallocating queue: " << block_size << " | " << size() << "\n";
    }

    end++;
    data[end] = element;
}

template<typename T>
T& Queue<T>::peek()
{
    return data[begining];
}

template<typename T>
void Queue<T>::dequeue()
{
    if(begining <= end)
        begining++;
}

template<typename T>
int Queue<T>::size()
{
    return end-begining +1;
}

#endif // __QUEUE_H_
