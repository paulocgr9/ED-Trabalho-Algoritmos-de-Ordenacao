#include <iostream>
#include <chrono>
#include "LinkedList.h"

using namespace std;

template <typename T> void bubbleSort(Node<T>**, int);
template <typename T> void optimizedBubbleSort(Node<T>**, int);

template <typename T>
void bubbleSort(Node<T>** head, int iLenght)
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

    for (int iLoop = 0; iLoop < iLenght-1; iLoop++)
    {
        Node<T>* current = *head;
        do
        {
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swapValues(current, current->ptrNext);
            }
            current = current->ptrNext;
        }
        while (current->ptrNext != nullptr);
    }
}

template <typename T>
void optimizedBubbleSort(Node<T>** head, int iLenght)
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

    bool bUnordered = false;
    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++)
    {
        bUnordered = false;

        Node<T>* current = *head;
        for(int iInnerLoop = 0; iInnerLoop < iLenght - iOuterLoop - 1; iInnerLoop++) {
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swapValues(current, current->ptrNext);
                bUnordered = true;
            }
            current = current->ptrNext;
        }
        if (bUnordered == false) break;
    }
}

template void bubbleSort(Node<int>**, int);
template void optimizedBubbleSort(Node<int>**, int);
