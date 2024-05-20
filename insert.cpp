#include <iostream>
#include <chrono>
#include "LinkedList.h"

using namespace std;

template <typename T> void insertSort(Node<T>**, int);

template <typename T>
void insertSort(Node<T>** head, int iLength)
{
    if (*head == nullptr)
    {
        cout << "Impossível ordenar: lista vazia." << endl;
        return;
    }
    if ((*head)->ptrNext == nullptr)
    {
        cout << "Impossível ordenar: lista de um elemento." << endl;
        return;
    }

    int iInsertValue = 0;
    Node<T>* iInnerLoop = nullptr;

    Node<T>* current = (*head)->ptrNext;
    while (current != nullptr)
    {
        iInsertValue = current->iPayload;
        iInnerLoop = current;

        while (iInnerLoop->ptrPrev != nullptr && iInsertValue < iInnerLoop->ptrPrev->iPayload)
        {
            iInnerLoop->iPayload = iInnerLoop->ptrPrev->iPayload;
            iInnerLoop = iInnerLoop->ptrPrev; 
        }

        iInnerLoop->iPayload = iInsertValue;
        current = current->ptrNext;
    }
}

template void insertSort(Node<int>**, int);
