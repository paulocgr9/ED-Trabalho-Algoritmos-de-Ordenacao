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

void insertSort(Node**, int);

int main()
{
    int iNumeroSeeds = 100;

    long long int temposInsertSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node* currentList1 = createRandomList(0, 1000, 10000, iIndex);

        auto timeStart = high_resolution_clock::now();
        insertSort(&currentList1, 10000);
        auto timeStop = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposInsertSort[iIndex] = timeDuration.count();
        freeList(&currentList1);
    }
  
    cout << "Insert Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposInsertSort[i] << ", ";
    cout << endl;
 
}
void insertSort(Node** head, int iLength)
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
    Node* iInnerLoop = nullptr;

    Node* current = (*head)->ptrNext;
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