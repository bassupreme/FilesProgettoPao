#ifndef CONTAINER_H
#define CONTAINER_H

// direttive d'inclusione
#include <iostream>

template <class T>
class Container {
private:
    class Node {
        friend class Container<T>;
    private:
        T data;
        Node* next;
    public:
        Node(T data, Node* next);
    };
    Node* head; // basta questo per la lista singolarmente linkata.
    Node* last;
public:
    class const_iterator {
        friend class Container<T>;
    private:
        const Node* ptr;
        bool pastTheEnd;
        // iteratore indefinito IFF ptr == nullptr & pastTheEnd==false
        const_iterator(const Node* p, bool pte=false);
        const_iterator();
    public:
        // operatore ++ prefisso
        const_iterator &operator++();
        // operatore ++ postfisso
        const_iterator operator++(int);
        const T& operator*() const;
        bool operator==(const const_iterator& cit) const;
        bool operator!=(const const_iterator& cit) const;
    };

    Container();
    ~Container();
    // Node* getHead() const; // questo viene poi sostituito da una classe iteratore.
    void add(T data);
    void add_back(T data);
    void remove(T data);
    void clear();
    bool empty() const;
    unsigned int getSize() const;

    const_iterator begin() const;
    const_iterator end() const;
    const T& operator[](const const_iterator& cit) const;
};
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
    if (ptr != nullptr && !pastTheEnd) {
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
    return ptr != cit.ptr;
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
            return;
        }
        // informazioni per continuare il ciclo
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
    return head == nullptr;
}

// utile in fase di debug. potrebbe essere utile ad altri widget tuttavia.
template<class T>
unsigned int Container<T>::getSize() const {
    Container<T>::Node* aux = head;

    unsigned int size = 0;
    while (aux != nullptr) {
        size+=1;
        aux = aux->next;
    }

    return size;
}

template<class T>
typename Container<T>::const_iterator Container<T>::begin() const {
    if (head != nullptr) {
        std::cout << "lista piena" << std::endl;
        return const_iterator(head, false);
    }
    return const_iterator();
}

template<class T>
typename Container<T>::const_iterator Container<T>::end() const {
    if (head == nullptr) {
        std::cout << "lista vuota" << std::endl;
        return const_iterator();
    }

    std::cout << "lista piena" << std::endl;
    return const_iterator(last + 1, true);
}

template<class T>
const T& Container<T>::operator[](const const_iterator& cit) const {
    return *cit;
}
#endif
