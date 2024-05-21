#include <iostream>
#include "LinkedList.h"
#include "shell.h"

int main()
{
    Node<int>* LinkedList1 = createRandomList(1, 30, 10, 1);

    shellSortExplained(&LinkedList1, 15);
}