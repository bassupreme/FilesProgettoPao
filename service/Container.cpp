#include "Container.h"


template<typename T>
Container<T>::Node::Node(T data, Node *next) : data(data), next(next) {}

template<typename T>
T Container<T>::Node::getData() const {
    return data;
}

template<typename T>
void Container<T>::Node::setData(T data) {
    data = data;
}

/*
template<typename T>
Container::Node* Container<T>::Node::getNext() const {
    return next;
}

template<typename T>
Container::Node& Container<T>::Node::setNext(Node *next) {
    next = next;
    return *this;
}
*/

template<typename T>
Container<T>::Container() : head(nullptr), last(nullptr) { }

template<typename T>
Container<T>::~Container() {
    clear();
}

template<typename T>
void Container<T>::add(T data) {
    head = new Node(data, head);
}

template<typename T>
void Container<T>::add_back(T data) {
    if (head == nullptr) {
        head = new Node(data, head);
        last = head;
    } else {
        Node* aux = last;
        last = new Node(data, nullptr);
        aux->next = last;
    }
}

template<typename T>
void Container<T>::remove(T data) {
    Node* previous = 0;
    Node* current = head;
    while (current != 0) {
        if (current->data == data) {
            if (previous == 0 && current->next == nullptr) { // eliminazione dell'unico nodo nella lista.
                head = last = nullptr;
            } else if (previous == 0) { // eliminazione primo nodo
                head = current->next;
            } else if (current->next == nullptr) { // eliminazione dell'ultimo nodo
                last = previous;
                previous->next = nullptr;
            } else {
                previous->next = current->next;
            }
            delete current;
        }
        previous = current;
        current = current->next;
    }
}

template<typename T>
void Container<T>::clear() {
    while (head != 0) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}
