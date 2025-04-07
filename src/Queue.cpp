
//maayan428@gmail.com

#include "Queue.hpp"
#include <stdexcept>

namespace graph {

    Queue::Queue() : capacity(10), frontIndex(0), backIndex(0), count(0) {
        data = new int[capacity];
    }

    Queue::~Queue() {
        delete[] data;
    }

    void Queue::resize() {
        int* newData = new int[capacity * 2];
        for (int i = 0; i < count; ++i) {
            newData[i] = data[(frontIndex + i) % capacity];
        }
        frontIndex = 0;
        backIndex = count;
        capacity *= 2;
        delete[] data;
        data = newData;
    }

    void Queue::enqueue(int value) {
        if (count == capacity) resize();
        data[backIndex] = value;
        backIndex = (backIndex + 1) % capacity;
        ++count;
    }

    int Queue::dequeue() {
        if (isEmpty()) throw std::underflow_error("Queue is empty");
        int value = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return value;
    }

    int Queue::front() const {
        if (isEmpty()) throw std::underflow_error("Queue is empty");
        return data[frontIndex];
    }

    bool Queue::isEmpty() const {
        return count == 0;
    }

}
