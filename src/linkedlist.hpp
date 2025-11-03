#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    bool isEmpty() const { return head == nullptr; }
    void insertBack(const T& val) {
        Node<T>* n = new Node<T>(val);
        if (isEmpty()) head = n;
        else {
            Node<T>* p = head;
            while (p->next) p = p->next;
            p->next = n;
        }
    }
    Node<T>* getHead() const { return head; }
};
#endif
