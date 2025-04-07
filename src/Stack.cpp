
//maayan428@gmail.com

#include "Stack.hpp"
#include <stdexcept>

namespace graph {

    Stack::Stack() : capacity(10), topIndex(-1) {
        data = new int[capacity];
    }

    Stack::~Stack() {
        delete[] data;
    }

    void Stack::resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    void Stack::push(int value) {
        if (topIndex + 1 == capacity) {
            resize();
        }
        data[++topIndex] = value;
    }

    int Stack::pop() {
        if (isEmpty()) throw std::underflow_error("Stack is empty");
        return data[topIndex--];
    }

    int Stack::top() const {
        if (isEmpty()) throw std::underflow_error("Stack is empty");
        return data[topIndex];
    }

    bool Stack::isEmpty() const {
        return topIndex == -1;
    }

}
