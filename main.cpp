#include <iostream>
#include <chrono>
#include "LinkedList.h"
#include "bubble.h"
#include "selection.h"
#include "insert.h"

using namespace std;
using namespace std::chrono;

int main()
{
    int iNumeroSeeds = 100;

    long long int temposBubbleSort[iNumeroSeeds] = {};
    long long int temposOptimizedBubbleSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node<int>* currentList1 = createRandomList(0, 100, 10000, iIndex);
        Node<int>* currentList2 = createRandomList(0, 100, 10000, iIndex);
        
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
    cout << "\n" << endl;

    long long int temposSelectionSort[iNumeroSeeds] = {};
    long long int temposOptimizedSelectionSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node<int>* currentList1 = createRandomList(0, 1000, 10000, iIndex);
        Node<int>* currentList2 = createRandomList(0, 1000, 10000, iIndex);
        
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
    cout << "\n" << endl;


    long long int temposInsertSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node<int>* currentList1 = createRandomList(0, 1000, 10000, iIndex);

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
