#ifndef CONTAINER_H
#define CONTAINER_H

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
    const_iterator begin() const;
    const_iterator end() const;
    const T& operator[](const const_iterator& cit) const;
};

#endif // CONTAINER_H
