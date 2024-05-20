#include <iostream>
#include <chrono>
#include "LinkedList.h"

using namespace std;

template <typename T> void selectionSort(Node<T>**);
template <typename T> void optimizedSelectionSort(Node<T>**);

template <typename T>
void selectionSort(Node<T>** head)
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
    Node<T>* currentOuter = *head;
    while(currentOuter != nullptr)
    {
        Node<T>* currentInner = currentOuter->ptrNext;
        while(currentInner != nullptr)
        {
            if (currentOuter->iPayload > currentInner->iPayload)
            {
                swapValues(currentOuter, currentInner);
            }
        currentInner = currentInner->ptrNext;
        }
    currentOuter = currentOuter->ptrNext;
    }
}

template <typename T>
void optimizedSelectionSort(Node<T>** head)
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
    int minValue = 0;
    Node<T>* ptrSwap = 0;

    Node<T>* currentOuter = *head;
    while(currentOuter != nullptr)
    {
        minValue = currentOuter->iPayload;
        ptrSwap = currentOuter;

        Node<T>* currentInner = currentOuter->ptrNext;
        while(currentInner != nullptr)
        {
            if (minValue > currentInner->iPayload)
            {
                minValue = currentInner->iPayload;
                ptrSwap = currentInner;
            }
            currentInner = currentInner->ptrNext;
        }
        swapValues(currentOuter, ptrSwap);
        currentOuter = currentOuter->ptrNext;
    }
}

template void selectionSort(Node<int>**);
template void optimizedSelectionSort(Node<int>**);
