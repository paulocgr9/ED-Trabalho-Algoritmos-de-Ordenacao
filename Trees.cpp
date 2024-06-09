#include <iostream>
#include "Trees.h"

using namespace std;

//Metodos para manipulacao basica de arvores 
NodeTree* newNodeTree(int);
NodeTree* insertNodeTree(NodeTree*, int);
NodeTree* lesserLeaf(NodeTree*);
NodeTree* deleteNodeTree(NodeTree*, int);
int treeHeight(NodeTree*);

//Metodos para busca
NodeTree* dfsSearchNode(NodeTree*, int);
NodeTree* bfsSearchNode(NodeTree*, int);

//Metodos para traverse
void dfsTraversePreOrder(NodeTree*);
void dfsTraverseInOrder(NodeTree*);
void dfsTraversePostOrder(NodeTree*);
void bfsTraverse(NodeTree*);

//Estrutura auxiliar de fila, so para esse arquivo
struct NodeQueue
{
    NodeTree* ptrPayload;
    NodeQueue* ptrNext;
};
void insertEndQueue(NodeQueue**, NodeTree*); //Funcao para auxiliar a andar na fila

int main()
{
    NodeTree* root = nullptr;

    root = insertNodeTree(root, 42);
    root = insertNodeTree(root, 13);
    root = insertNodeTree(root, 11);
    root = insertNodeTree(root, 10);
    root = insertNodeTree(root, 28);
    root = insertNodeTree(root, 51);
    root = insertNodeTree(root, 171);
    root = insertNodeTree(root, 25);
    root = insertNodeTree(root, 32);

    cout << "BFS Traversal: ";
    bfsTraverse(root);
    cout << endl;

    cout << "Tree Height: " << treeHeight(root) << endl;

    NodeTree* dfsSearchFor28 = dfsSearchNode(root, 28);
    cout << dfsSearchFor28->iPayload << endl;
    cout << dfsSearchFor28->ptrLeft->iPayload << endl;
    cout << dfsSearchFor28->ptrRight->iPayload << endl;

    return 0;
}

void insertEndQueue(NodeQueue** head, NodeTree* ptrPayload)
{
    NodeQueue* newNode = (NodeQueue*) malloc(sizeof(NodeQueue));
    newNode->ptrPayload = ptrPayload;
    newNode->ptrNext = nullptr;

    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    NodeQueue* current = (*head);
    while (current->ptrNext != nullptr) current = current->ptrNext;

    current->ptrNext = newNode;

    return;
}

NodeTree* newNodeTree(int iData)
{
    NodeTree* tmp = (NodeTree*) malloc(sizeof(NodeTree));
  
    if (tmp != nullptr)
    {
        tmp->iPayload = iData;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
    }
  
    return tmp;
}

NodeTree* insertNodeTree(NodeTree* startingNode, int iData)
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

NodeTree* dfsSearchNode(NodeTree* startingNode, int iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return dfsSearchNode(startingNode->ptrLeft, iData);
    else return dfsSearchNode(startingNode->ptrRight, iData);
}

NodeTree* lesserLeaf(NodeTree* startingNode)
{
    NodeTree* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

NodeTree* deleteNodeTree(NodeTree* startingNode, int iData)
{
    if (startingNode == nullptr) return nullptr;
    
    if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNodeTree(startingNode->ptrLeft, iData);
    else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNodeTree(startingNode->ptrRight, iData);
    else
    {
        NodeTree* ptrTemp = nullptr;
        
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

void dfsTraversePreOrder(NodeTree* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        dfsTraversePreOrder(ptrStartingNode->ptrLeft);
        dfsTraversePreOrder(ptrStartingNode->ptrRight);
    }
}

void dfsTraverseInOrder(NodeTree* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        dfsTraverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        dfsTraverseInOrder(ptrStartingNode->ptrRight);
    }
}

void dfsTraversePostOrder(NodeTree* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        dfsTraversePostOrder(ptrStartingNode->ptrLeft);
        dfsTraversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}

void bfsTraverse(NodeTree* startingNode)
{
    if (startingNode == nullptr) return;
    
    // Parte 1 do Trabalho: Alterar para Lista Encadeada - feita
    NodeQueue* ptrQueue = nullptr;
    insertEndQueue(&ptrQueue, startingNode);
    
    while (ptrQueue != nullptr)
    {
        NodeTree* currentNode = ptrQueue->ptrPayload;
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

NodeTree* bfsSearchNode(NodeTree* root, int iPayload)
{
    if (root == nullptr) return nullptr;

    NodeQueue* ptrQueue = nullptr;
    insertEndQueue(&ptrQueue, root);
    
    while (ptrQueue != nullptr)
    {
        NodeTree* currentNode = ptrQueue->ptrPayload;
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

int treeHeight(NodeTree* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1;
    }
}
