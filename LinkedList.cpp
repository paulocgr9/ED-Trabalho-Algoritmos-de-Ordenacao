#include <iostream>
#include "LinkedList.h"

using namespace std;

// Protótipos das funções
template <typename T> Node<T> *createNode(T);
template <typename T>  void displayList(Node<T>*);
template <typename T>  void insertEnd(Node<T>**, T);
template <typename T>  void swapValues(Node<T> *, Node<T> *);
template <typename T> void freeList(Node<T> **);

template <typename T>
Node<T>* createNode(T iPayload)
{
    Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
    temp->iPayload = iPayload;
    temp->ptrPrev = nullptr;
    temp->ptrNext = nullptr;

    return temp;
}

Node<int> *createRandomList(int iBottomLimit, int iTopLimit, int iQuantity, int iSeed)
{
    Node<int> *head = nullptr;
    srand(iSeed);
    for (int i = 0; i < iQuantity; i++)
    {
        insertEnd(&head, iBottomLimit + (rand() % (iTopLimit - iBottomLimit)));
    }
    return head;
}

template <typename T>
void displayList(Node<T>* node)
{
    if (node == nullptr)
    {
        cout << "Impossível mostrar lista: Lista inexistente." << endl;
        return;
    }
    if (node->ptrPrev != nullptr)
    {
        cout << "Impossível mostrar lista: Meio da lista." << endl;
        return;
    }

    Node<T>* current = node;
    cout << "Valores: ";
    while (current != nullptr)
    {
        cout << current->iPayload << " ";
        current = current->ptrNext;
    }
    cout << endl;

    return;
}

template <typename T>
void insertEnd(Node<T>** head, T iPayload)
{
    Node<T>* newNode = createNode<T>(iPayload);
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    Node<T>* current = (*head);

    while (current->ptrNext != nullptr) current = current->ptrNext;

    newNode->ptrPrev = current;
    current->ptrNext = newNode;

    return;
}

template <typename T>
void swapValues(Node<T>* Node1, Node<T>* Node2)
{
    // Trocando somente os Payloads
    int iTemp = Node1->iPayload;
    Node1->iPayload = Node2->iPayload;
    Node2->iPayload = iTemp;
}

template <typename T>
void freeList(Node<T>** head){
    Node<T>* current = *head;
    current = current->ptrNext;
    while(current->ptrNext != nullptr){
        free(current->ptrPrev);
        current = current->ptrNext;
    }
    free(current);
}

template Node<int> *createNode(int);
template void displayList(Node<int> *);
template void insertEnd(Node<int> **, int);
template void swapValues(Node<int> *, Node<int> *);
template void freeList(Node<int> **);
