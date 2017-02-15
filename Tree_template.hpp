#include <iostream>
#include <string>

#ifndef TREE_TEMPLATE
#define TREE_TEMPLATE

template <typename T>
class node
{

  public:
        /*
         * This is the node class used by Tree_template and all of its
         * derived classes. It contains 3 pointers for the right and left
         * children and the parent. It also contains 3 data member variables.
         * This could be expanded to hold more data, but it would mean
         * rewriting the constructors for the node, then the enum of the
         * tree class, which then would require a rewrite of the
         * findSoringVariable function.
         * */

    node<T> *left, *right, *parent;
    T data1, data2, data3;

    node() : data1(), data2(), data3(), parent(), left(), right()
    {
    }

    node(T value1, T value2, T value3, node<T> *l, node<T> *r, node<T> *p) : left(l), right(r), parent(p), data1(value1), data2(value2), data3(value3)
    {
    }

    node(T value1, T value2, T value3, node<T> *p) : left(), right(), parent(p), data1(value1), data2(value2), data3(value3)
    {
    }

    node(T value1, T value2, T value3) : left(), right(), parent(), data1(value1), data2(value2), data3(value3)
    {
    }
};

template <typename T>
class Tree_Template
{
  public:
    int size;      //Added or subtracted from at the apporpriate times. Keeps track of how many nodes are in the tree
    node<T> *root; //The root of the tree.

    /* This enum tells the program which variable is being used to sort
     * and search the tree. Any inheriting classes should use the same
     * format of setting the the variables equal to 1,2, and 3 respectively.
     * If they do not, nothing will work right.
    */
    enum sortingVariable
    {
        Variable1 = 1,
        Variable2 = 2,
        Variable3 = 3
    };
    sortingVariable sortByThis;

  public:
    //Empty constructor
    Tree_Template() : size(),
                      root(nullptr),
                      sortByThis(Variable1)
    {
    }

    //Constructor that takes only an int. This is so you can set which variable
    // the tree sorts by when you construct it.
    Tree_Template(int x) : size(),
                           root(nullptr),
                           sortByThis((sortingVariable(x)))
    {
    }

    //Takes 3 variables of type T and an integer so that you can construct
    //the root node and set which variable the tree sorts by when you construct it.
    Tree_Template(T variable1, T variable2, T variable3, int x) : size(1),
                                                                  root(new node<T>(variable1, variable2, variable3)),
                                                                  sortByThis((sortingVariable(x)))
    {
    }

    /*
    * The following findSortingVariable() function is the vritual function
    * that is key to this implementations of a BTS. It allows you to 
    * create a BTS that sorts by a certain member variable of the node
    * and then allows you to define a search function that searches by looking
    * at that member variable. This allows you to have all the benefits 
    * of a BST, while having multiple pieces of data in the nodes that you
    * can search for and sort by. The findSortingVariable function is 
    * overloaded for all the scenarios that it can be used.
    */

    virtual void findSortingVariable(T &x, node<T> *temp) = 0;
    virtual void findSortingVariable(T &x, T &y, T &var1, T &var2, T &var3, node<T> *temp) = 0;

    void sortBy(int x)
    {
        Tree_Template<T> NewTree(x);

        NewTree.fillTree(root);

        *this = NewTree;
    }

    //Below are the template functions used in this tree. The algorithms
    //for all of these functions would be the same for any binary search
    //tree, but with multiple pieces of data, you may only know one part,
    //and need to find the rest based on that piece.

    //This function finds and returns a node given a key to look for.
    //findSortingVariable is used to decide which value in the node
    // to check the key against.
    node<T> *find(T key)
    {
        T data;
        node<T> *temp = root;

        findSortingVariable(data, temp);

        if (key == data)
            return temp;

        while (data != key)
        {

            if (temp->left == nullptr && temp->right == nullptr)
                return nullptr;

            if (key > data)
            {
                if (temp->right == nullptr)
                    return nullptr;

                temp = temp->right;

                findSortingVariable(data, temp);
            }

            else if (key < data)
            {
                if (temp->left == nullptr)
                    return nullptr;

                temp = temp->left;

                findSortingVariable(data, temp);
            }
        }

        return temp;
    }

    //This function is given a key and uses it to find and erase a node
    void erase(const T &key)
    {

        node<T> *temp = find(key);

        if (temp == nullptr)
            return;

        if (temp->left == nullptr && temp->right == nullptr) //leaf node or head node situation
        {

            if (temp != root)
            {
                if (temp == temp->parent->right)
                    temp->parent->right = nullptr;

                if (temp == temp->parent->left)
                    temp->parent->left = nullptr;
            }

            delete temp;
            --size;
            return;
        }

        if (temp->right && !(temp->left))
        {
            temp->right->parent = temp->parent;

            if (temp == temp->parent->right)
                temp->parent->right = temp->right;
            if (temp == temp->parent->left)
                temp->parent->left = temp->right;
        }

        else if (temp->left && !(temp->right))
        {
            temp->left->parent = temp->parent;

            if (temp == temp->parent->right)
                temp->parent->right = temp->left;
            if (temp == temp->parent->left)
                temp->parent->left = temp->left;
        }

        if (temp->right != nullptr)
        {
            temp->data1 = temp->right->data1;
            temp->data2 = temp->right->data2;
            temp->data3 = temp->right->data3;
            erase(temp->right);
            return;
        }

        else if (temp->left != nullptr)
        {
            temp->data1 = temp->left->data1;
            temp->data2 = temp->left->data2;
            temp->data3 = temp->left->data3;
            erase(temp->left);
            return;
        }

        if (temp->right->right == nullptr && temp->right->left == nullptr) //right
        {
            temp->data1 = temp->right->data1;
            temp->data2 = temp->right->data2;
            temp->data3 = temp->right->data3;
            delete temp->right;
            temp->right = nullptr;
            --size;
            return;
        }

        else if (temp->left->right == nullptr && temp->left->left == nullptr) //left
        {
            temp->data1 = temp->left->data1;
            temp->data2 = temp->left->data2;
            temp->data3 = temp->left->data3;
            delete temp->left;
            temp->left = nullptr;
            --size;
            return;
        }
    }

    //An overload of the erase function so that it can be used recursively.
    void erase(node<T> *temp)
    {
        if (temp == nullptr)
            return;

        if (temp->left == nullptr && temp->right == nullptr) //leaf node
        {

            if (temp == root)
            {
                root = nullptr;
                return;
            }

            if (temp == temp->parent->right)
                temp->parent->right = nullptr;

            if (temp == temp->parent->left)
                temp->parent->left = nullptr;

            delete temp;
            --size;
            return;
        }

        if (temp->right && !(temp->left))
        {
            temp->right->parent = temp->parent;

            if (temp == temp->parent->right)
                temp->parent->right = temp->right;
            if (temp == temp->parent->left)
                temp->parent->left = temp->right;
        }

        else if (temp->left && !(temp->right))
        {
            temp->left->parent = temp->parent;

            if (temp == temp->parent->right)
                temp->parent->right = temp->left;
            if (temp == temp->parent->left)
                temp->parent->left = temp->left;
        }

        if (temp->right != nullptr)
        {
            temp->data1 = temp->right->data1;
            temp->data2 = temp->right->data2;
            temp->data3 = temp->right->data3;
            erase(temp->right);
            return;
        }

        else if (temp->left != nullptr)
        {
            temp->data1 = temp->left->data1;
            temp->data2 = temp->left->data2;
            temp->data3 = temp->left->data3;
            erase(temp->left);
            return;
        }

        if (temp->right->right == nullptr && temp->right->left == nullptr) //right
        {
            temp->data1 = temp->right->data1;
            temp->data2 = temp->right->data2;
            temp->data3 = temp->right->data3;
            delete temp->right;
            temp->right = nullptr;
            --size;
            return;
        }

        else if (temp->left->right == nullptr && temp->left->left == nullptr) //left
        {
            temp->data1 = temp->left->data1;
            temp->data2 = temp->left->data2;
            temp->data3 = temp->left->data3;
            delete temp->left;
            temp->left = nullptr;
            --size;
            return;
        }
    }

    //Inserts a node with the given data elements.
    //Uses findSortingVariable to decided which variables from the two
    // nodes to check against each other.
    void insert(T variable1, T variable2, T variable3)
    {

        if (root == nullptr)
        {
            node<T> *theRoot = new node<T>(variable1, variable2, variable3);
            root = theRoot;
            ++size;
            return;
        }

        node<T> *temp = new node<T>(variable1, variable2, variable3);
        node<T> *subroot = root;

        T value, key;

        findSortingVariable(value, key, variable1, variable2, variable3, subroot);

        while (subroot)
        {
            if (key >= value)
            {
                if (subroot->right == nullptr)
                {
                    subroot->right = temp;
                    temp->parent = subroot;
                    subroot = nullptr;
                }

                else
                {
                    subroot = subroot->right;
                    findSortingVariable(value, key, variable1, variable2, variable3, subroot);
                }
            }

            else if (key < value)
            {
                if (subroot->left == nullptr)
                {
                    subroot->left = temp;
                    temp->parent = subroot;
                    subroot = nullptr;
                }

                else
                {
                    subroot = subroot->left;
                    findSortingVariable(value, key, variable1, variable2, variable3, subroot);
                }
            }
        }

        ++size;
    }

    //Deletes all the elements in the tree.
    //Must set root equal to nullptr so that isEmpty works.
    void clearTree(node<T> *temp)
    {
        if (temp == nullptr)
            return;

        clearTree(temp->left);
        clearTree(temp->right);
        if (temp == root)
            root = nullptr;
        delete temp;
    }

    bool isEmpty()
    {
        if (root)
            return false;
        return true;
    }

    //Prints out all of the member variables of the given node.
    void printDetails(node<T> *x)
    {
        if (x == nullptr)
            return;
        std::cout << x->data1 << "\n";
        std::cout << x->data2 << "\n";
        std::cout << x->data3 << "\n\n";
    }

    //Prints all of the member variables for every node in the tree.
    void printTree(node<T> *p)
    {
        if (p == nullptr)
            return;

        printDetails(p);
        printTree(p->right);
        printTree(p->left);
    }

    //Used by the sortBy function to fill in the new tree.
    void fillTree(node<T> *x)
    {
        if (x == nullptr)
            return;

        insert(x->data1, x->data2, x->data3);
        fillTree(x->right);
        fillTree(x->left);
    }
};

#endif
