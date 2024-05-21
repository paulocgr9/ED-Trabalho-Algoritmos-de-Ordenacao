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
    Node<T>* currentBack = nullptr;

    Node<T>* current = (*head)->ptrNext;
    while (current != nullptr)
    {
        iInsertValue = current->iPayload;
        currentBack = current;

        while (currentBack->ptrPrev != nullptr && iInsertValue < currentBack->ptrPrev->iPayload)
        {
            currentBack->iPayload = currentBack->ptrPrev->iPayload;
            currentBack = currentBack->ptrPrev; 
        }

        currentBack->iPayload = iInsertValue;
        current = current->ptrNext;
    }
}

template void insertSort(Node<int>**, int);
