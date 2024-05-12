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

void bubbleSort(Node**, int);
void optimizedBubbleSort(Node**, int);

int main()
{
    int iNumeroSeeds = 100;

    long long int temposBubbleSort[iNumeroSeeds] = {};
    long long int temposOptimizedBubbleSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node* currentList1 = createRandomList(0, 1000, 10000, iIndex);
        Node* currentList2 = createRandomList(0, 1000, 10000, iIndex);
        
        auto timeStart = high_resolution_clock::now();
        bubbleSort(&currentList1, 10000);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposBubbleSort[iIndex] = timeDuration.count();
        freeList(&currentList1);

        timeStart = high_resolution_clock::now();
        optimizedBubbleSort(&currentList2, 10000);
        timeStop = high_resolution_clock::now();

        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposOptimizedBubbleSort[iIndex] = timeDuration.count();
        freeList(&currentList2);
    }
  
    cout << "Bubble Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposBubbleSort[i] << ", ";
    cout << endl;

    cout << "Optimized Bubble Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposOptimizedBubbleSort[i] << ", ";
    cout << endl;
}

void bubbleSort(Node** head, int iLenght)
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

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++)
    {
        Node* current = *head;
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

void optimizedBubbleSort(Node** head, int iLenght)
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

        Node* current = *head;
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