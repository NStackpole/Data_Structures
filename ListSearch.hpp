#include <iostream>
#include <string>

class ListSearch
{
  public:
    //Member variables
    std::string name, address, phonenumber;

    //Constructors
    ListSearch();

    ListSearch(std::string n, std::string a, std::string p);

    //Destructor
    ~ListSearch();

    //Prints out the member variables of the class instance.
    void printDetails();
};
