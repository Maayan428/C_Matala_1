
//maayan428@gmail.com

#ifndef STACK_HPP
#define STACK_HPP

namespace graph {

    class Stack {
    private:
        int* data;
        int capacity;
        int topIndex;

        void resize();

    public:
        Stack();
        ~Stack();

        void push(int value);
        int pop();
        int top() const;
        bool isEmpty() const;
    };

} // namespace graph

#endif
