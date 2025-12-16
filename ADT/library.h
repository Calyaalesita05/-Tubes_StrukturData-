#ifndef BST_LIBRARY_H
#define BST_LIBRARY_H
#include "lagu.h"
#include <string>

struct NodeBST {
    Lagu data;
    NodeBST* left;
    NodeBST* right;
};

typedef NodeBST* BSTree;

void InsertLagu(BSTree& root, Lagu newLagu);
NodeBST* FindLagu(BSTree root, std::string id);
void DisplayInOrder(BSTree root);
void DeleteLagu(BSTree& root, std::string id);
// filepath: library.h
void UpdateLagu(BSTree root, std::string id);

#endif