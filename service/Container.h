#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container {
public:
    class Node {
        friend class Container;
    private:
        T data;
        Node* next;

    public:
        Node(T data, Node* next): data(data), next(next) {
        }
        T getData() const {
            return data;
        }

        Node& setData(T data) {
            this->data = data;
            return *this;
        }

        Node* getNext() const {
            return next;
        }

        Node& setNext(Node* next) {
            this->next = next;
            return *this;
        }
    };

private:
    Node* head; // basta questo per la lista singolarmente linkata.
    Node* last;
public:

    Container(): head(0), last(0) {
    }

    ~Container() {
        clear();
    }

    unsigned int getSize() const {
        unsigned int size = 0;
        Node* n = head;
        while (n != 0) {
            n = n->next;
            size++;
        }
        return size;
    }

    Node* getHead() const {
        return head;
    }

    Container& add(T data) {
        head = new Node(data, head);
        return *this;
    }

    Container& add_back(T data) {
        if (head == nullptr) {
            head = new Node(data, head);
            last = head;
        } else {
            Node* aux = last;
            last = new Node(data, nullptr);
            aux->next = last;
        }
        return *this;
    }

    Container& remove(T data) {
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
                return *this;
            }
            previous = current;
            current = current->next;
        }
        return *this;
    }

    Container& clear() {
        while (head != 0) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        return *this;
    }


};

#endif // CONTAINER_H
