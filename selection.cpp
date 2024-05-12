#include <iostream>
#include <chrono>
#include "LinkedList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void selectionSort(Node**);
void optimizedSelectionSort(Node**);

int main()
{
    int iNumeroSeeds = 100;

    long long int temposSelectionSort[iNumeroSeeds] = {};
    long long int temposOptimizedSelectionSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node* currentList1 = createRandomList(0, 1000, 10000, iIndex);
        Node* currentList2 = createRandomList(0, 1000, 10000, iIndex);
        
        auto timeStart = high_resolution_clock::now();
        selectionSort(&currentList1);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposSelectionSort[iIndex] = timeDuration.count();
        freeList(&currentList1);

        timeStart = high_resolution_clock::now();
        optimizedSelectionSort(&currentList2);
        timeStop = high_resolution_clock::now();

        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposOptimizedSelectionSort[iIndex] = timeDuration.count();
        freeList(&currentList2);
    }
  
    cout << "Selection Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposSelectionSort[i] << ", ";
    cout << endl;

    cout << "Optimized Selection Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposOptimizedSelectionSort[i] << ", ";
    cout << endl;
}

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
