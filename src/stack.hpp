#ifndef STACK_HPP
#define STACK_HPP
#include <stdexcept>

template <typename T>
struct StackNode {
    T data;
    StackNode<T>* next;
    StackNode(const T& v) : data(v), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* topNode;
public:
    Stack() : topNode(nullptr) {}
    bool isEmpty() const { return topNode == nullptr; }
    void push(const T& val) {
        StackNode<T>* n = new StackNode<T>(val);
        n->next = topNode;
        topNode = n;
    }
    T pop() {
        if (isEmpty()) throw std::runtime_error("Stack underflow");
        StackNode<T>* tmp = topNode;
        T val = tmp->data;
        topNode = topNode->next;
        delete tmp;
        return val;
    }
    T top() const {
        if (isEmpty()) throw std::runtime_error("Stack empty");
        return topNode->data;
    }
};
#endif
