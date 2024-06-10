#include <iostream>
#include <chrono>
#include "LinkedList.h"
#include "bubble.h"
#include "selection.h"
#include "insert.h"
#include "shell.h"
#include "Trees.h"

using namespace std;
using namespace std::chrono;

int main()
{
    int iNumeroSeeds = 100;

    // long long int tempoCriacaoList[iNumeroSeeds] = {};
    // long long int tempoCriacaoTree[iNumeroSeeds] = {};
    // for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    // {
    //     auto testTimeStart = high_resolution_clock::now();
    //     Node<int>* testList = createRandomList(0, 100, 10000, iIndex);
    //     auto testTimeStop = high_resolution_clock::now();

    //     auto testTimeDuration = duration_cast<nanoseconds>(testTimeStop - testTimeStart);
    //     tempoCriacaoList[iIndex] = testTimeDuration.count();

    //     testTimeStart = high_resolution_clock::now();
    //     NodeTree<int>* testTree = createRandomTree(0, 100, 10000, 0);
    //     testTimeStop = high_resolution_clock::now();

    //     testTimeDuration = duration_cast<nanoseconds>(testTimeStop - testTimeStart);
    //     tempoCriacaoTree[iIndex] = testTimeDuration.count();
        
    //     freeList(&testList);
    //     freeTree(testTree);
    // }

    // cout << "Linked List" << endl;
    // for (int i = 0; i < 100; i++) cout << tempoCriacaoList[i] << ", ";
    // cout << endl;

    // cout << "Trees" << endl;
    // for (int i = 0; i < 100; i++) cout << tempoCriacaoTree[i] << ", ";
    // cout << "\n" << endl;

    long long int tempoBuscaBfs[iNumeroSeeds] = {};
    long long int tempoBuscaDfs[iNumeroSeeds] = {};
    long long int tempoBuscaLinkedList[iNumeroSeeds] = {};
    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node<int>* searchLinkedList = createRandomList(0, 5000, 10000, iIndex);
        NodeTree<int>* searchTree = createRandomTree(0, 5000, 10000, iIndex);
        int iSearchValue = rand() % 5000;
        
        auto testTimeStart = high_resolution_clock::now();
        Node<int>* resultadoList = searchList(&searchLinkedList, iSearchValue);
        auto testTimeStop = high_resolution_clock::now();

        auto testTimeDuration = duration_cast<nanoseconds>(testTimeStop - testTimeStart);
        tempoBuscaLinkedList[iIndex] = testTimeDuration.count();

        testTimeStart = high_resolution_clock::now();
        NodeTree<int>* resultado = bfsSearchNode(searchTree, iSearchValue);
        testTimeStop = high_resolution_clock::now();

        testTimeDuration = duration_cast<nanoseconds>(testTimeStop - testTimeStart);
        tempoBuscaBfs[iIndex] = testTimeDuration.count();

        testTimeStart = high_resolution_clock::now();
        resultado = dfsSearchNode(searchTree, iSearchValue);
        testTimeStop = high_resolution_clock::now();

        testTimeDuration = duration_cast<nanoseconds>(testTimeStop - testTimeStart);
        tempoBuscaDfs[iIndex] = testTimeDuration.count();

        freeTree(searchTree);
    }

    cout << "DFS" << endl;
    for (int i = 0; i < 100; i++) cout << tempoBuscaDfs[i] << ", ";
    cout << endl;

    cout << "BFS" << endl;
    for (int i = 0; i < 100; i++) cout << tempoBuscaBfs[i] << ", ";
    cout << "\n" << endl;

    cout << "LinkedList" << endl;
    for (int i = 0; i < 100; i++) cout << tempoBuscaLinkedList[i] << ", ";
    cout << "\n" << endl;

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
        Node<int>* currentList1 = createRandomList(0, 100, 10000, iIndex);
        Node<int>* currentList2 = createRandomList(0, 100, 10000, iIndex);
        
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
        Node<int>* currentList1 = createRandomList(0, 100, 10000, iIndex);

        auto timeStart = high_resolution_clock::now();
        insertSort(&currentList1, 10000);
        auto timeStop = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposInsertSort[iIndex] = timeDuration.count();
        freeList(&currentList1);
    }
  
    cout << "Insert Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposInsertSort[i] << ", ";
    cout << "\n" << endl;


    long long int temposShellSort[iNumeroSeeds] = {};

    for (int iIndex = 0; iIndex < iNumeroSeeds; iIndex++)
    {
        Node<int>* currentList1 = createRandomList(0, 100, 10000, iIndex);

        auto timeStart = high_resolution_clock::now();
        insertSort(&currentList1, 10000);
        auto timeStop = high_resolution_clock::now();
        
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        temposShellSort[iIndex] = timeDuration.count();
        freeList(&currentList1);
    }
  
    cout << "Shell Sort" << endl;
    for (int i = 0; i < 100; i++) cout << temposShellSort[i] << ", ";
    cout << endl;

}
