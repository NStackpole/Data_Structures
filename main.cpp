#include "BST.hpp"
#include "ListSearch.hpp"
#include <string>
#include <vector>
#include <time.h>

ListSearch *searchVector(std::vector<ListSearch *> V, std::string key);
int getIndex(std::vector<ListSearch *> V, std::string key);

int main()
{
    //I apologize in advance if it seems like there werent many elements
    // worked with in these test cases. It was very difficult
    // and tedious to get the few I had in. If I had been smart and done
    // something with integers, I could have had many more.

    //Start a comment on the line below using /* and place a */ at the next indicated location to comment out all test code.

    clock_t t1, t2;

    //Contructiong new tree.
    BST TestTree(1);

    //Test insert for BST by inserting 20 new nodes.
    t1 = clock();
    TestTree.insert("John Smith", "2653 1st Street", "330-555-1203");
    TestTree.insert("Dave Smith", "1732 2nd Street", "254-555-2313");
    TestTree.insert("Pier Bordeux", "1623 32nd Street", "125-555-4231");
    TestTree.insert("Donald Knuth", "5423 Knuth Drive", "542-555-3214");
    TestTree.insert("Edsger Dijkstra", "6852 Rotterdam Road", "542-555-4212");
    TestTree.insert("Ada Lovelace", "1815 London Road", "523-555-5212");
    TestTree.insert("Alan Turing", "1912 Maida Road", "121-555-5322");
    TestTree.insert("Grace Hopper", "1906 Arlington Street", "421-555-9274");
    TestTree.insert("Bjarne Stroustrup", "1950 Aaurhus Drive", "865-555-7573");
    TestTree.insert("Dennis Ritchie", "1941 Unix Avenue", "451-555-3616");
    TestTree.insert("Blaise Pascal", "1623 Auvernge Road", "754-555-96251");
    TestTree.insert("Charles Thomas", "1785 Colmar Avenue", "542-555-7525");
    TestTree.insert("Charles Babbage", "1791 Marlebone Road", "145-555-4212");
    TestTree.insert("George Boole", "1815 Licolnshire Road", "315-555-6362");
    TestTree.insert("John Backus", "1924 Philadelphia Street", "154-555-5321");
    TestTree.insert("John Atanasoff", "1903 Hamilton Road", "321-555-4212");
    TestTree.insert("Jean Bartik", "1924 Gentry Drive", "554-555-2124");
    TestTree.insert("Noam Chomsky", "1928 Pennsylvania Road", "758-555-2142");
    TestTree.insert("Alan Kay", "9652 Rotterdam Road", "214-555-212");
    TestTree.insert("John McCarthy", "7852 Rotterdam Road", "876-555-2314");
    t2 = clock();

    std::cout << "BST inserted 20 elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n";

    //Test insert for the vector
    //I include the construction of the ListSearch objects because
    // these are similar to the consturction of the nodes for the tree,
    // and obviously the nodes need to be constructor when inserting
    // into the tree.
    t1 = clock();

    ListSearch *first = new ListSearch("John Smith", "2653 1st Street", "330-555-1203");
    ListSearch *second = new ListSearch("Pier Bordeux", "1623 32nd Street", "125-555-4231");
    ListSearch *third = new ListSearch("Donald Knuth", "5423 Knuth Drive", "542-555-3214");
    ListSearch *fourth = new ListSearch("Edsger Dijkstra", "6852 Rotterdam Road", "542-555-4212");
    ListSearch *fifth = new ListSearch("Ada Lovelace", "1815 London Road", "523-555-5212");
    ListSearch *six = new ListSearch("Alan Turing", "1912 Maida Road", "121-555-5322");
    ListSearch *seven = new ListSearch("Grace Hopper", "1906 Arlington Street", "421-555-9274");
    ListSearch *eight = new ListSearch("Bjarne Stroustrup", "1950 Aaurhus Drive", "865-555-7573");
    ListSearch *nine = new ListSearch("Dennis Ritchie", "1941 Unix Avenue", "451-555-3616");
    ListSearch *ten = new ListSearch("Blaise Pascal", "1623 Auvernge Road", "754-555-96251");
    ListSearch *eleven = new ListSearch("Charles Thomas", "1785 Colmar Avenue", "542-555-7525");
    ListSearch *twelve = new ListSearch("Charles Babbage", "1791 Marlebone Road", "145-555-4212");
    ListSearch *thirteen = new ListSearch("George Boole", "1815 Licolnshire Road", "315-555-6362");
    ListSearch *fourteen = new ListSearch("John Backus", "1924 Philadelphia Street", "154-555-5321");
    ListSearch *fifteen = new ListSearch("John Atanasoff", "1903 Hamilton Road", "321-555-4212");
    ListSearch *sixteen = new ListSearch("Jean Bartik", "1924 Gentry Drive", "554-555-2124");
    ListSearch *seventeen = new ListSearch("Noam Chomsky", "1928 Pennsylvania Road", "758-555-2142");
    ListSearch *eighteen = new ListSearch("Alan Kay", "9652 Rotterdam Road", "214-555-212");
    ListSearch *nineteen = new ListSearch("John McCarthy", "7852 Rotterdam Road", "876-555-2314");
    ListSearch *twenty = new ListSearch("Dave Smith", "1732 2nd Street", "254-555-2313");

    std::vector<ListSearch *> V;

    //Push back is the quickest way to insert into a vector.
    V.push_back(first);
    V.push_back(second);
    V.push_back(third);
    V.push_back(fourth);
    V.push_back(fifth);
    V.push_back(six);
    V.push_back(seven);
    V.push_back(eight);
    V.push_back(nine);
    V.push_back(ten);
    V.push_back(eleven);
    V.push_back(twelve);
    V.push_back(thirteen);
    V.push_back(fourteen);
    V.push_back(fifteen);
    V.push_back(sixteen);
    V.push_back(seventeen);
    V.push_back(eighteen);
    V.push_back(nineteen);
    V.push_back(twenty);

    t2 = clock();

    std::cout << "Vector inserted 20 elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n\n";

    //Testing search for the bst

    t1 = clock();
    node<std::string> *BSTfound = TestTree.find("John Smith");
    BSTfound = TestTree.find("Dave Smith");
    BSTfound = TestTree.find("Pier Bordeux");
    BSTfound = TestTree.find("Donald Knuth");
    BSTfound = TestTree.find("Edsger Dijkstra");
    BSTfound = TestTree.find("Ada Lovelace");
    BSTfound = TestTree.find("Alan Turing");
    BSTfound = TestTree.find("Grace Hopper");
    BSTfound = TestTree.find("Bjarne Stroustrup");
    BSTfound = TestTree.find("Dennis Ritchie");
    BSTfound = TestTree.find("Blaise Pascal");
    BSTfound = TestTree.find("Charles Thomas");
    BSTfound = TestTree.find("Charles Babbage");
    BSTfound = TestTree.find("George Boole");
    BSTfound = TestTree.find("John Backus");
    BSTfound = TestTree.find("John Atanasoff");
    BSTfound = TestTree.find("Jean Bartik");
    BSTfound = TestTree.find("Noam Chomsky");
    BSTfound = TestTree.find("Alan Kay");
    BSTfound = TestTree.find("John McCarthy");
    t2 = clock();

    std::cout << "BST found all 20 elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n";

    //Testing search for the vector

    t1 = clock();

    ListSearch *found = searchVector(V, first->phonenumber);
    found = searchVector(V, second->phonenumber);
    found = searchVector(V, third->phonenumber);
    found = searchVector(V, fourth->phonenumber);
    found = searchVector(V, fifth->phonenumber);
    found = searchVector(V, six->phonenumber);
    found = searchVector(V, seven->phonenumber);
    found = searchVector(V, eight->phonenumber);
    found = searchVector(V, nine->phonenumber);
    found = searchVector(V, ten->phonenumber);
    found = searchVector(V, eleven->phonenumber);
    found = searchVector(V, twelve->phonenumber);
    found = searchVector(V, thirteen->phonenumber);
    found = searchVector(V, fourteen->phonenumber);
    found = searchVector(V, fifteen->phonenumber);
    found = searchVector(V, sixteen->phonenumber);
    found = searchVector(V, seventeen->phonenumber);
    found = searchVector(V, eighteen->phonenumber);
    found = searchVector(V, nineteen->phonenumber);
    found = searchVector(V, twenty->phonenumber);
    t2 = clock();

    std::cout << "Vector found all 20 elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n\n";

    int VectorSize = V.size();

    //Testing clear for the tree

    t1 = clock();
    TestTree.clearTree(TestTree.root);
    t2 = clock();

    //std::cout<<TestTree.isEmpty()<<"\n"; // for if you want to test if it is actually empty

    std::cout << "BST deleted all 20 elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n";

    //Testing clear for the vector

    t1 = clock();
    for (int i = 0; i < VectorSize; ++i)
    {
        delete V[i];
    }
    t2 = clock();

    //std::cout<<V[3]->name<<"name\n"; //for if you want to test to see if it is actually empty

    std::cout << "Vector deleted all 20 elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n\n";

    //Inserting the values again so I can test random deletion.

    TestTree.insert("John Smith", "2653 1st Street", "330-555-1203");
    TestTree.insert("Dave Smith", "1732 2nd Street", "254-555-2313");
    TestTree.insert("Pier Bordeux", "1623 32nd Street", "125-555-4231");
    TestTree.insert("Donald Knuth", "5423 Knuth Drive", "542-555-3214");
    TestTree.insert("Edsger Dijkstra", "6852 Rotterdam Road", "542-555-4212");
    TestTree.insert("Ada Lovelace", "1815 London Road", "523-555-5212");
    TestTree.insert("Alan Turing", "1912 Maida Road", "121-555-5322");
    TestTree.insert("Grace Hopper", "1906 Arlington Street", "421-555-9274");
    TestTree.insert("Bjarne Stroustrup", "1950 Aaurhus Drive", "865-555-7573");
    TestTree.insert("Dennis Ritchie", "1941 Unix Avenue", "451-555-3616");
    TestTree.insert("Blaise Pascal", "1623 Auvernge Road", "754-555-96251");
    TestTree.insert("Charles Thomas", "1785 Colmar Avenue", "542-555-7525");
    TestTree.insert("Charles Babbage", "1791 Marlebone Road", "145-555-4212");
    TestTree.insert("George Boole", "1815 Licolnshire Road", "315-555-6362");
    TestTree.insert("John Backus", "1924 Philadelphia Street", "154-555-5321");
    TestTree.insert("John Atanasoff", "1903 Hamilton Road", "321-555-4212");
    TestTree.insert("Jean Bartik", "1924 Gentry Drive", "554-555-2124");
    TestTree.insert("Noam Chomsky", "1928 Pennsylvania Road", "758-555-2142");
    TestTree.insert("Alan Kay", "9652 Rotterdam Road", "214-555-212");
    TestTree.insert("John McCarthy", "7852 Rotterdam Road", "876-555-2314");

    V.push_back(first);
    V.push_back(second);
    V.push_back(third);
    V.push_back(fourth);
    V.push_back(fifth);
    V.push_back(six);
    V.push_back(seven);
    V.push_back(eight);
    V.push_back(nine);
    V.push_back(ten);
    V.push_back(eleven);
    V.push_back(twelve);
    V.push_back(thirteen);
    V.push_back(fourteen);
    V.push_back(fifteen);
    V.push_back(sixteen);
    V.push_back(seventeen);
    V.push_back(eighteen);
    V.push_back(nineteen);
    V.push_back(twenty);

    //Testing random deletion with the BST
    t1 = clock();
    TestTree.erase("Donald Knuth");
    TestTree.erase("Alan Kay");
    TestTree.erase("Blaise Pascal");
    TestTree.erase("Ada Lovelace");
    TestTree.erase("John Atanasoff");
    t2 = clock();

    //TestTree.printDetails(TestTree.find("Ada Lovelace")); // to test if erase worked. If it worked you wont be able to tell if you uncommented this line or not.

    std::cout << "BST deleted 5 specified elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n";

    //Testing random deletion with the vector

    t1 = clock();
    V.erase(V.begin() + getIndex(V, "Donald Knuth"));
    V.erase(V.begin() + getIndex(V, "Alan Kay"));
    V.erase(V.begin() + getIndex(V, "Blaise Pascal"));
    V.erase(V.begin() + getIndex(V, "Ada Lovelace"));
    V.erase(V.begin() + getIndex(V, "John Atanasoff"));
    t2 = clock();

    //std::cout<<getIndex(V, "Ada Lovelace")<<"\n"; // To test if erase worked.

    std::cout << "Vector deleted the same 5 specified elements in " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " seconds\n\n";

    // **** Put the */ below this to comment out all the test code. ****

    //Below is code that tests most if not all of the functions of the BST.
    //If you would like to see any of the functions not used above used,
    //all you need to do is uncomment it below. some names may have been
    //deleted in the above tests, so it might be a good idea to copy
    //the inserts from above. I dont want to add more lines of code to
    //this if I do not have to, so I will leave that decision to you.

    //std::cout<<"Printing whole Tree\n";
    //TestTree.printTree(TestTree.root);

    //TestTree.printDetails(TestTree.find("Pier Bordeux"));

    //std::cout<<"Finished Printing\n";

    //In order to search by Address, we must use the sortBy function.
    //This function resorts the tree by the member variable you are searching for
    // and also sets the sortingVariable sortByThis to the given number
    // so that its knows which member variable to use.
    // if you want to change it to name, you give this functinon 1.
    // if you want to change it to address, you give it 2.
    // if you want to change it to date of birth, give it 3.
    /*TestTree.sortBy(2);
    
    std::cout<<"Resorted to look for address\n";    
    
    std::string findThis = "1732 2nd Street";
    std::cout<<"Searchng for "<<findThis<<". Details should appear below if client exists\n";
        
    TestTree.printDetails(TestTree.find(findThis));
    
    std::cout<<"This client has decided to leave us, removing their entry in the system.\n";
    TestTree.erase(findThis);
    
    std::cout<<"Searching for recently deleted entry, if nothing appears on the line below, it was properly deleted\n\n";
    TestTree.printDetails(TestTree.find(findThis));
    std::cout<<"If nothing appeared it is gone\n";
    
    std::cout<<"Inserting done, printing new tree\n";
    
    //TestTree.printTree(TestTree.root);

    std::cout<<"Resorted to look for phone number\n";
    TestTree.sortBy(3);
    
    findThis = "542-555-4212";
    
    std::cout<<"Searching for "<<findThis<<". Details should appear below if the client exists\n";
    TestTree.printDetails(TestTree.find(findThis));
    std::cout<<TestTree.size<<"\n";*/

    //std::cout<<"Printing tree\n";
    //TestTree.printTree(TestTree.root);

    //std::cout << "Test";

    return 0;
}

ListSearch *searchVector(std::vector<ListSearch *> V, std::string key)
{
    for (int i = 0; i < V.size(); ++i)
    {
        if (V[i]->name == key || V[i]->address == key || V[i]->phonenumber == key)
            return V[i];
    }
}

int getIndex(std::vector<ListSearch *> V, std::string key)
{
    for (int i = 0; i < V.size(); ++i)
    {
        if (V[i]->name == key || V[i]->address == key || V[i]->phonenumber == key)
            return i;
    }
}
