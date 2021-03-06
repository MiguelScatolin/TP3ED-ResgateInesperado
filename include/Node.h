#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:
        Node() : left(nullptr), right(nullptr) {}
        Node(T item) : item(item), left(nullptr), right(nullptr) {}
        T GetItem() { return item; };
        void SetItem(T newItem) { item = newItem; };
        Node<T>* GetLeft() { return left; };
        void SetLeft(Node<T> *newLeft) { left = newLeft; };
        Node<T>* GetRight() { return right; };
        void SetRight(Node<T> *newRight) { right = newRight; };

    private:
        T item;
        Node<T> *left;
        Node<T> *right;
};

#endif