#ifndef __QUEUE_H_
#define __QUEUE_H_

template <typename T>
class Queue
{
public:
    Queue(int size);
    Queue();
    ~Queue();

    void enqueue(T element);
    T& peek();
};

#endif // __QUEUE_H_
