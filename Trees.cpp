#include <iostream>
#include "Trees.h"

using namespace std;

//Metodos para manipulacao basica de arvores 
template <typename T> NodeTree<T>* newNodeTree(T);
template <typename T> NodeTree<T>* insertNodeTree(NodeTree<T>*, T);
template <typename T> NodeTree<T>* lesserLeaf(NodeTree<T>*);
template <typename T> NodeTree<T>* deleteNodeTree(NodeTree<T>*, T);
template <typename T> int treeHeight(NodeTree<T>*);
NodeTree<int> *createRandomTree(int, int, int, int);

//Metodos para busca
template <typename T> NodeTree<T>* dfsSearchNode(NodeTree<T>*, T);
template <typename T> NodeTree<T>* bfsSearchNode(NodeTree<T>*, T);

//Metodos para traverse
template <typename T> void dfsTraversePreOrder(NodeTree<T>*);
template <typename T> void dfsTraverseInOrder(NodeTree<T>*);
template <typename T> void dfsTraversePostOrder(NodeTree<T>*);
template <typename T> void bfsTraverse(NodeTree<T>*);

//Estrutura auxiliar de fila, so para esse arquivo
template <typename T>
struct NodeQueue
{
    NodeTree<T>* ptrPayload;
    NodeQueue* ptrNext;
};
template <typename T> void insertEndQueue(NodeQueue<T>**, NodeTree<T>*); //Funcao para auxiliar a andar na fila

template <typename T>
void insertEndQueue(NodeQueue<T>** head, NodeTree<T>* ptrPayload)
{
    NodeQueue<T>* newNode = (NodeQueue<T>*) malloc(sizeof(NodeQueue<T>));
    newNode->ptrPayload = ptrPayload;
    newNode->ptrNext = nullptr;

    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    NodeQueue<T>* current = (*head);
    while (current->ptrNext != nullptr) current = current->ptrNext;

    current->ptrNext = newNode;

    return;
}

template <typename T>
NodeTree<T>* newNodeTree(T iData)
{
    NodeTree<T>* tmp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
  
    if (tmp != nullptr)
    {
        tmp->iPayload = iData;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
    }
  
    return tmp;
}

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>* startingNode, T iData)
{
    if(startingNode == nullptr)
    {
        return newNodeTree(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNodeTree(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNodeTree(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

NodeTree<int> *createRandomTree(int iBottomLimit, int iTopLimit, int iQuantity, int iSeed)
{
    NodeTree<int> *head = nullptr;
    srand(iSeed);
    for (int i = 0; i < iQuantity; i++)
    {
        head = insertNodeTree(head, iBottomLimit + (rand() % (iTopLimit - iBottomLimit)));
    }
    return head;
}

template <typename T>
NodeTree<T>* dfsSearchNode(NodeTree<T>* startingNode, T iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return dfsSearchNode(startingNode->ptrLeft, iData);
    else return dfsSearchNode(startingNode->ptrRight, iData);
}

template <typename T>
NodeTree<T>* lesserLeaf(NodeTree<T>* startingNode)
{
    NodeTree<T>* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

template <typename T>
NodeTree<T>* deleteNodeTree(NodeTree<T>* startingNode, T iData)
{
    if (startingNode == nullptr) return nullptr;
    
    if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNodeTree(startingNode->ptrLeft, iData);
    else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNodeTree(startingNode->ptrRight, iData);
    else
    {
        NodeTree<T>* ptrTemp = nullptr;
        
        if (startingNode->ptrLeft == nullptr)
        {
            ptrTemp = startingNode->ptrRight;
            free(startingNode);
            return ptrTemp;
        }
        else if (startingNode->ptrRight == nullptr)
        {
            ptrTemp = startingNode->ptrLeft;
            free(startingNode);
            return ptrTemp;            
        }
        
        ptrTemp = lesserLeaf(startingNode->ptrRight);
        
        startingNode->iPayload = ptrTemp->iPayload;
        
        startingNode->ptrRight = deleteNodeTree(startingNode->ptrRight, ptrTemp->iPayload);
    }
    
    return startingNode;
}

template <typename T>
void dfsTraversePreOrder(NodeTree<T>* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        dfsTraversePreOrder(ptrStartingNode->ptrLeft);
        dfsTraversePreOrder(ptrStartingNode->ptrRight);
    }
}

template <typename T>
void dfsTraverseInOrder(NodeTree<T>* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        dfsTraverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        dfsTraverseInOrder(ptrStartingNode->ptrRight);
    }
}

template <typename T>
void dfsTraversePostOrder(NodeTree<T>* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        dfsTraversePostOrder(ptrStartingNode->ptrLeft);
        dfsTraversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}

template <typename T>
void bfsTraverse(NodeTree<T>* startingNode)
{
    if (startingNode == nullptr) return;
    
    // Parte 1 do Trabalho: Alterar para Lista Encadeada - feita
    NodeQueue<T>* ptrQueue = nullptr;
    insertEndQueue(&ptrQueue, startingNode);
    
    while (ptrQueue != nullptr)
    {
        NodeTree<T>* currentNode = ptrQueue->ptrPayload;
        ptrQueue = ptrQueue->ptrNext;
        
        cout << currentNode->iPayload << " ";
    
        if (currentNode->ptrLeft != nullptr)
        {
            insertEndQueue(&ptrQueue, currentNode->ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            insertEndQueue(&ptrQueue, currentNode->ptrRight);
        }
        
    }
}

template <typename T>
NodeTree<T>* bfsSearchNode(NodeTree<T>* root, T iPayload)
{
    if (root == nullptr) return nullptr;

    NodeQueue<T>* ptrQueue = nullptr;
    insertEndQueue(&ptrQueue, root);
    
    while (ptrQueue != nullptr)
    {
        NodeTree<T>* currentNode = ptrQueue->ptrPayload;
        ptrQueue = ptrQueue->ptrNext;
        
        cout << currentNode->iPayload << " ";
        if (currentNode->iPayload == iPayload) return currentNode;  
    
        if (currentNode->ptrLeft != nullptr)
        {
            insertEndQueue(&ptrQueue, currentNode->ptrLeft);
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            insertEndQueue(&ptrQueue, currentNode->ptrRight);
        }
    }

    return nullptr;
}

template <typename T>
int treeHeight(NodeTree<T>* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1;
    }
}

template NodeTree<int>* newNodeTree(int);
template NodeTree<int>* insertNodeTree(NodeTree<int>*, int);
template NodeTree<int>* lesserLeaf(NodeTree<int>*);
template NodeTree<int>* deleteNodeTree(NodeTree<int>*, int);
template int treeHeight(NodeTree<int>*);
template NodeTree<int>* dfsSearchNode(NodeTree<int>*, int);
template NodeTree<int>* bfsSearchNode(NodeTree<int>*, int);
template void dfsTraversePreOrder(NodeTree<int>*);
template void dfsTraverseInOrder(NodeTree<int>*);
template void dfsTraversePostOrder(NodeTree<int>*);
template void bfsTraverse(NodeTree<int>*);
