#include <iostream>

using namespace std;

typedef struct Node
{
  int iPayload;
  
  Node* ptrLeft;
  Node* ptrRight;

} Node;

Node* newNode(int);
Node* insertNode(Node*, int);
Node* dfsSearchNode(Node*, int);
Node* lesserLeaf(Node*);
Node* deleteNode(Node*, int);

void dfsTraversePreOrder(Node*);
void dfsTraverseInOrder(Node*);
void dfsTraversePostOrder(Node*);

int main()
{
    return 0;
}


Node* newNode(int iData)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
  
    if (tmp != nullptr)
    {
        tmp->iPayload = iData;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
    }
  
    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return newNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

Node* dfsSearchNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return dfsSearchNode(startingNode->ptrLeft, iData);
    else return dfsSearchNode(startingNode->ptrRight, iData);
}

Node* lesserLeaf(Node* startingNode)
{
    Node* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

Node* deleteNode(Node* startingNode, int iData)
{
    if (startingNode == nullptr) return nullptr;
    
    if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
    else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
    else
    {
        Node* ptrTemp = nullptr;
        
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
        
        startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
    }
    
    return startingNode;
}

void dfsTraversePreOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        dfsTraversePreOrder(ptrStartingNode->ptrLeft);
        dfsTraversePreOrder(ptrStartingNode->ptrRight);
    }
}

void dfsTraverseInOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        dfsTraverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        dfsTraverseInOrder(ptrStartingNode->ptrRight);
    }
}

void dfsTraversePostOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        dfsTraversePostOrder(ptrStartingNode->ptrLeft);
        dfsTraversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}

void bfsTraverse(Node* startingNode)
{
    if (startingNode == nullptr) return;
    
    // Parte 1 do Trabalho: Alterar para Lista Encadeada
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
    
    while (iQueueFront < iQueueRear)
    {
        Node* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;
        
        cout << currentNode->iPayload << " ";
    
        if (currentNode->ptrLeft != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrLeft;
            iQueueRear++;
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrRight;
            iQueueRear++;
        }
        
    }
}

int treeHeight(Node* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1;
    }
}