#ifndef LinkedListH
#define LinkedListH

#include <iostream>
using std::cout;
using std::endl;
using std::rand;

// Criando uma estrutura de nós
template <typename T>
struct Node
{
    T iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

template struct Node<int>;
template <typename T> Node<T> *createNode(T);
template <typename T> void displayList(Node<T> *);
template <typename T> void insertEnd(Node<T> **, T);
template <typename T> void swapValues(Node<T> *, Node<T> *);
template <typename T> void freeList(Node<T> **);
Node<int>* createRandomList(int, int, int, int);
template <typename T> Node<T>* walkList(Node<T>*, int);
template <typename T> Node<T>* searchList(Node<T>**, T);

#endif
