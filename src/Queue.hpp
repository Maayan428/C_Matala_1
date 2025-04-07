
//maayan428@gmail.com

#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace graph {

    class Queue {
    private:
        int* data;
        int capacity;
        int frontIndex;
        int backIndex;
        int count;

        void resize();

    public:
        Queue();
        ~Queue();

        void enqueue(int value);
        int dequeue();
        int front() const;
        bool isEmpty() const;
    };

} // namespace graph

#endif
