#ifndef TreesH
#define TreesH

#include <iostream>
using std::cout;
using std::endl;
using std::rand;

struct NodeTree
{
    int iPayload;
    
    NodeTree* ptrLeft;
    NodeTree* ptrRight;

};

#endif