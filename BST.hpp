#include "Tree_template.hpp"

#ifndef BST_HPP
#define BST_HPP

class BST : public Tree_Template<std::string>
{
  public:
    //This needs to use the root and size of the Tree_template, so there are
    // no members here.

    //We define a new enum for this with 3 variables just like the one in the derived class.
    //We do this so that we know what we are stroing in data1, data2, and data3.
    
    enum sortingVariable
    {
        Name = 1,
        Address = 2,
        PhoneNumber = 3
    };

    sortingVariable sortByThis;

    //Constructors
    BST();

    BST(int x);

    BST(std::string name, std::string address, std::string phone, int x);

    //This function makes a new tree that is sorted by the sortingVariable
    //corresponding to the given integer
    void sortBy(int x);

    //Sets the given value to the corresponding value in the node
    //based on what variable is currently being sorted by
    //Needed to be defined in the header file, I think because it is a pure
    //virtual function.
    void findSortingVariable(std::string &value, node<std::string> *temp)
    {
        
        if (sortByThis == Name)
        {
            value = temp->data1;
        }

        else if (sortByThis == Address)
        {
            value = temp->data2;
        }

        else if (sortByThis == PhoneNumber)
        {
            value = temp->data3;
        }
    }

    //Sets the given value to the corresponding value in the node
    //based on what variable is currently being sorted by
    //Needed to be defined in the header file, I think because it is a pure
    //virtual function.
    void findSortingVariable(std::string &value, std::string &key, std::string &var1, std::string &var2, std::string &var3, node<std::string> *temp)
    {

        if (sortByThis == Name)
        {
            value = temp->data1;
            key = var1;
        }

        else if (sortByThis == Address)
        {
            value = temp->data2;
            key = var2;
        }

        else if (sortByThis == PhoneNumber)
        {
            value = temp->data3;
            key = var3;
        }
    }
};

#endif
