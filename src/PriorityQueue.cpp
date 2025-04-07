
//maayan428@gmail.com

#include "PriorityQueue.hpp"
#include <stdexcept>

namespace graph {

    PriorityQueue::PriorityQueue() : capacity(10), size(0) {
        arr = new Element[capacity];
    }

    PriorityQueue::~PriorityQueue() {
        delete[] arr;
    }

    void PriorityQueue::resize() {
        capacity *= 2;
        Element* newArr = new Element[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void PriorityQueue::heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index].priority < arr[parent].priority) {
                Element temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                index = parent;
            } else break;
        }
    }

    void PriorityQueue::heapify_down(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && arr[left].priority < arr[smallest].priority) {
                smallest = left;
            }
            if (right < size && arr[right].priority < arr[smallest].priority) {
                smallest = right;
            }
            if (smallest == index) break;

            Element temp = arr[index];
            arr[index] = arr[smallest];
            arr[smallest] = temp;
            index = smallest;
        }
    }

    void PriorityQueue::enqueue(int value, int priority) {
        if (size == capacity) resize();
        arr[size] = {value, priority};
        heapify_up(size);
        ++size;
    }

    int PriorityQueue::dequeue() {
        if (is_empty()) throw std::underflow_error("Queue is empty");
        int result = arr[0].value;
        arr[0] = arr[--size];
        heapify_down(0);
        return result;
    }

    int PriorityQueue::find_index(int value) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i].value == value) return i;
        }
        return -1;
    }

    void PriorityQueue::decrease_key(int value, int new_priority) {
        int idx = find_index(value);
        if (idx == -1) throw std::invalid_argument("Value not found");
        if (new_priority >= arr[idx].priority) return;
        arr[idx].priority = new_priority;
        heapify_up(idx);
    }

    bool PriorityQueue::contains(int value) const {
        return find_index(value) != -1;
    }

    bool PriorityQueue::is_empty() const {
        return size == 0;
    }

}
