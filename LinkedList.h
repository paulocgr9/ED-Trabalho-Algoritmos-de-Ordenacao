#ifndef LinkedListH
#define LinkedListH

// Criando uma estrutura de nó
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

void foo(int id, char *name);
Node* createNode(int);
Node* createRandomList(int, int, int, int);
void displayList(Node*);
void insertEnd(Node**, int);
void swapValues(Node *, Node *);
void freeList(Node **);

#endif
