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
        Node(T data, Node* next);
        T getData() const;
        void setData(T data);
        // Node* getNext() const; // rimpiazzabile da funzioni iteratrici.
        // Node& setNext(Node* next);
    };
private:
    Node* head; // basta questo per la lista singolarmente linkata.
    Node* last;
public:
    Container();
    ~Container();
    // Node* getHead() const; // questo viene poi sostituito da una classe iteratore.
    void add(T data);
    void add_back(T data);
    void remove(T data);
    void clear();
};

#endif // CONTAINER_H
