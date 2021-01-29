#include "../colecciones/StringKey.h"
#ifndef STRINGKEY_CPP
#define STRINGKEY_CPP

void StringKey::Stringkey(string id)
{
    this->id=id;
}
bool StringKey::equals(IKey * id) const{
    StringKey * key = (StringKey *) id;
    return this->id==key->id;
}

string StringKey::getString()
{
    return this->id;
}

StringKey::~StringKey()
{

}
#endif