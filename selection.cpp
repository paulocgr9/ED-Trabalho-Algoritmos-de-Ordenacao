#include <iostream>
#include <chrono>
#include "LinkedList.h"

using namespace std;

void selectionSort(Node**);
void optimizedSelectionSort(Node**);

void selectionSort(Node** head)
{
    Node* currentOuter = *head;
    while(currentOuter != nullptr)
    {
        Node* currentInner = currentOuter->ptrNext;
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

void optimizedSelectionSort(Node** head)
{
    int minValue = 0;
    Node* ptrSwap = 0;

    Node* currentOuter = *head;
    while(currentOuter != nullptr)
    {
        minValue = currentOuter->iPayload;
        ptrSwap = currentOuter;

        Node* currentInner = currentOuter->ptrNext;
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
