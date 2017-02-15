#include "BST.hpp"

//Check hpp for more comments on functions.

//Defualt constructor. defaults to sort by name
BST::BST() : sortByThis(Name)
{
    size = 0;
    root = nullptr;
}

BST::BST(int x) : sortByThis((sortingVariable(x)))
{
    size = 0;
    root = nullptr;
}

BST::BST(std::string name, std::string address, std::string phone, int x) : sortByThis((sortingVariable(x)))
{
    size = 1;
    root = new node<std::string>(name, address, phone);
}

void BST::sortBy(int x)
{
    BST NewTree(x);

    NewTree.fillTree(root);

    *this = NewTree;
}
