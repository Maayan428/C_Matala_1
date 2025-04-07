
//maayan428@gmail.com

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

namespace graph {

    struct Element {
        int value;
        int priority;
    };

    class PriorityQueue {
    private:
        Element* arr;
        int capacity;
        int size;

        void resize();
        void heapify_up(int index);
        void heapify_down(int index);
        int find_index(int value) const;

    public:
        PriorityQueue();
        ~PriorityQueue();

        void enqueue(int value, int priority);
        int dequeue();
        void decrease_key(int value, int new_priority);
        bool contains(int value) const;
        bool is_empty() const;
    };

}

#endif
