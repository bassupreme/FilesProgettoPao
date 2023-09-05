#include "Container.h"

// nodo
template<class T>
Container<T>::Node::Node(T data, Node *next) : data(data), next(next) {}

// CONST ITERATOR
template<class T>
Container<T>::const_iterator::const_iterator(const Node* p, bool pte) : ptr(p), pastTheEnd(pte) {}

template<class T>
Container<T>::const_iterator::const_iterator() : ptr(nullptr), pastTheEnd(false) {}

// prefisso
template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++() {
    if (ptr && !pastTheEnd) {
        if (ptr->next == nullptr) { ptr = ptr + 1; pastTheEnd = true; }
        else ptr = ptr->next;
    }
    return *this;
}

// postfisso
template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int) {
    const_iterator aux(*this);
    if (ptr && !pastTheEnd) {
        if (ptr->next == nullptr) { ptr = ptr + 1; pastTheEnd = true; }
        else ptr = ptr->next;
    }
    return aux;
}

template<class T>
const T& Container<T>::const_iterator::operator*() const {
    return ptr->data;
}

template<class T>
bool Container<T>::const_iterator::operator==(const const_iterator& cit) const {
    return ptr == cit.ptr;
}

template<class T>
bool Container<T>::const_iterator::operator!=(const const_iterator& cit) const {
    return ptr == cit.ptr;
}

// container

template<class T>
Container<T>::Container() : head(nullptr), last(nullptr) { }

template<class T>
Container<T>::~Container() {
    clear();
}

template<class T>
void Container<T>::add(T data) {
    head = new Node(data, head);
}

template<class T>
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

template <class T>
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

template <class T>
void Container<T>::clear() {
    while (head != 0) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

template<class T>
bool Container<T>::empty() const {
    return head == last == nullptr;
}

template<class T>
typename Container<T>::const_iterator Container<T>::begin() const {
    if (head != nullptr) return const_iterator(head, false);
    return const_iterator();
}

template<class T>
typename Container<T>::const_iterator Container<T>::end() const {
    if (head == nullptr) return const_iterator();
    return const_iterator(last + 1, true);
}

template<class T>
const T& Container<T>::operator[](const const_iterator& cit) const {
    return *cit;
}
