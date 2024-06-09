#ifndef TreesH
#define TreesH

#include <iostream>
using std::cout;
using std::endl;
using std::rand;

template <typename T>
struct NodeTree
{
    T iPayload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;

};

template struct NodeTree<int>;

template <typename T> NodeTree<T>* newNodeTree(T);
template <typename T> NodeTree<T>* insertNodeTree(NodeTree<T>*, T);
template <typename T> NodeTree<T>* lesserLeaf(NodeTree<T>*);
template <typename T> NodeTree<T>* deleteNodeTree(NodeTree<T>*, T);
template <typename T> int treeHeight(NodeTree<T>*);
template <typename T> NodeTree<T>* dfsSearchNode(NodeTree<T>*, T);
template <typename T> NodeTree<T>* bfsSearchNode(NodeTree<T>*, T);
template <typename T> void dfsTraversePreOrder(NodeTree<T>*);
template <typename T> void dfsTraverseInOrder(NodeTree<T>*);
template <typename T> void dfsTraversePostOrder(NodeTree<T>*);
template <typename T> void bfsTraverse(NodeTree<T>*);
NodeTree<int> *createRandomTree(int, int, int, int);

#endif