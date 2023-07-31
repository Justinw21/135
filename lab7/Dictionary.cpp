#include "Dictionary.h"
#include <cmath>

//Makes a dictionary full of lists
Dictionary::Dictionary()
{
    for(int i = 0; i < 101; i++)
    {
        list[i] = new List();
    }
}

//iterates through the dictionary and deletes
Dictionary::~Dictionary()
{
    for(int i = 0; i < 101; i++)
    {
        delete list[i];
        list[i] = nullptr;
    }
}

//String folding function from https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/HashFuncExamp.html 
int Dictionary::sfold(std::string s)
{
    long sum = 0;
    long mul = 1;
    for (int i = 0; i < s.length(); i++)
    {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += s[i] * mul;
    }
    return (int)(abs(sum) % 101);
}

//inserts into the linked list based on the hash_index from string folding
void Dictionary::insert(Person p)
{
    int hash_index = sfold(p.get_name());
    list[hash_index] -> insert(p);
}

//returns the node that the Person is in
Node* Dictionary::retrieve(Person p)
{
    int hash_index = sfold(p.get_name());
    return list[hash_index] -> contains(p);
}

//Iterates through the dictionary and prints if theres a person or nullptr
std::string Dictionary::getKeys()
{
    std::string result = "";
    for(int i = 0; i < 101; i++)
    {
        result = result + list[i] -> toString();
    }
    return result;
}