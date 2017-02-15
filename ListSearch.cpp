#include "ListSearch.hpp"

//Check hpp for comments on functions.

ListSearch::ListSearch(): 
    name(), 
    address(), 
    phonenumber()
{}

ListSearch::ListSearch(std::string n, std::string a, std::string p):
    name(n),
    address(a),
    phonenumber(p)
{}

ListSearch::~ListSearch()
{}

void ListSearch::printDetails()
{
    std::cout<<name<<"\n";
    std::cout<<address<<"\n";
    std::cout<<phonenumber<<"\n\n";
}
