#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;
using std::rand;

// Protótipos das funções
Node* createNode(int);
Node* createRandomList(int, int, int, int);
void displayList(Node*);
void insertEnd(Node**, int);
void swapValues(Node *, Node *);
void freeList(Node **);

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrPrev = nullptr;
    temp->ptrNext = nullptr;

    return temp;
}

Node *createRandomList(int iBottomLimit, int iTopLimit, int iQuantity, int iSeed)
{
    Node *head = nullptr;
    srand(iSeed);
    for (int i = 0; i < iQuantity; i++)
    {
        insertEnd(&head, iBottomLimit + (rand() % (iTopLimit - iBottomLimit)));
    }
    return head;
}

void displayList(Node* node)
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

    Node* current = node;
    cout << "Valores: ";
    while (current != nullptr)
    {
        cout << current->iPayload << " ";
        current = current->ptrNext;
    }
    cout << endl;

    return;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    Node* current = (*head);

    while (current->ptrNext != nullptr) current = current->ptrNext;

    newNode->ptrPrev = current;
    current->ptrNext = newNode;

    return;
}

void swapValues(Node* Node1, Node* Node2)
{
    // Trocando somente os Payloads
    int iTemp = Node1->iPayload;
    Node1->iPayload = Node2->iPayload;
    Node2->iPayload = iTemp;
}

void freeList(Node** head){
    Node* current = *head;
    current = current->ptrNext;
    while(current->ptrNext != nullptr){
        free(current->ptrPrev);
        current = current->ptrNext;
    }
    free(current);
}
