#include <iostream>
#include <chrono>
#include <cmath>
#include "LinkedList.h"

using namespace std;

template <typename T> void shellSort(Node<T>**, int);
template <typename T> void shellSortExplained(Node<T>**, int);

template <typename T>
void shellSort(Node<T>** head, int iLength)
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

    int iGapsCount = 0;
    for (int i = 1; (pow(2, i) - 1) < iLength; i++) iGapsCount++;

    for (int i = iGapsCount; i >0; i--)
    {    
        int iGap = pow(2, i) - 1;
        int iInsertValue = 0;
        Node<T>* current = walkList((*head), iGap);

        while (current != nullptr)
        {
            iInsertValue = current->iPayload;
            Node<T>* iInnerLoop = current;
            Node<T>* iBacker = walkList(current, -iGap);

            while (iBacker != nullptr && iInsertValue < iBacker->iPayload)
            {
                iInnerLoop->iPayload = iBacker->iPayload;
                iInnerLoop = iBacker;
                iBacker = walkList(iBacker, -iGap);
            }
            iInnerLoop->iPayload = iInsertValue;
            current = current->ptrNext;
        }
    }
}

template <typename T>
void shellSortExplained(Node<T>** head, int iLength)
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
    cout << "O shell sort é, por debaixo dos panos, um insert sort feito com diferentes intervalos da "
    << "lista. Ele define alguns números de gaps, e aplica o insert sort na lista, mas retrocedendo "
    << "o número gap de elementos no lugar de retroceder um por vez." << endl << "Logo, o primeiro "
    << "passo para fazer o shell sort é definir esses gaps. No caso dessa implementação, os gaps são "
    << "os números da sequencia n_k = 2^k - 1 que são menores do que o tamanho da lista. Diferentes "
    << "formas de determinar a lista de gaps determinam diferentes comportamentos do algoritmo, "
    << "e por isso a complexidade dele não é muito bem estabelecida, e depende da sequência de gaps. ";

    int iGapsCount = 0;
    for (int i = 1; (pow(2, i) - 1) < iLength; i++) iGapsCount++;

    cout << "Para uma lista de " << iLength << " elementos, a nossa implementação terá " << iGapsCount << " gaps." << endl;

    for (int i = iGapsCount; i >0; i--)
    {
        int iGap = pow(2, i) - 1;
        cout << "Iterando por toda a lista com um gap igual à " << iGap << ". Atualmente, a lista está "
        << "ordenada da seguinte forma:" << endl << "  ";
        displayList(*head);
        int iInsertValue = 0;
        int iPos = iGap;
        Node<T>* current = walkList((*head), iGap);
        cout << "  Agora, vamos partir do " << iGap << "º elemento e ir até o final da lista, elemento a elemento." << endl;

        while (current != nullptr)
        {
            cout << "  Elemento atual: " << iPos << "º. Será realizado um insert sort com os elementos " << iPos;
            for(int j = iPos - iGap; j >= 0; j = j - iGap) cout << ", " << j;
            cout << " da lista." << endl;
            iInsertValue = current->iPayload;
            Node<T>* iInnerLoop = current;
            Node<T>* iBacker = walkList(current, -iGap);
            int iRetrocedidos = 0;

            while (iBacker != nullptr && iInsertValue < iBacker->iPayload)
            {
                cout << "    O elemento na posição " << iPos - iRetrocedidos*iGap << "(" << iInsertValue << ") é menor que o elemento da posição"
                << iPos - (iRetrocedidos+1)*iGap << "(" << iBacker->iPayload << ") e por isso eles serão trocados." << endl;
                iInnerLoop->iPayload = iBacker->iPayload;
                iInnerLoop = iBacker;
                iBacker = walkList(iBacker, -iGap);
                iRetrocedidos++;
            }
            iInnerLoop->iPayload = iInsertValue;
            if (iRetrocedidos != 0)
            {
                cout << "    Após as trocas, a lista ficou desta forma:" << endl << "    ";
                displayList(*head);
            }

            current = current->ptrNext;
            iPos++;

            
        }
    }
}

template void shellSort(Node<int>**, int);
template void shellSortExplained(Node<int>**, int);
