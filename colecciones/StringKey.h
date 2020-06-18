#include "../interfaces/IKey.cpp"
#include <iostream>
#ifndef STRINGKEY_H
#define STRINGKEY_H

using namespace std;
class StringKey : public Ikey
{
private:
    string id;
public:
    StringKey(string); 
    bool equals(IKey * id) const;
    string getString();
    virtual ~StringKey();
}
#endif