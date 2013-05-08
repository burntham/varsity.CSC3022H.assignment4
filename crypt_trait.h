//USEFULL

#ifndef _CRYPT_TRAIT_H_
#define _CRYPT_TRAIT_H_

#include "cyphers.h"
#include <iostream>

namespace brndan022{


//generalised keytrait template
template <typename cyphertype> 

class KeyTrait{
public:
	typedef std::string Key;
};

//template for key used on Ceaser cypher
template <>
class KeyTrait <Ceaser> 
{
public:
	typedef int Key;
};

template <>
class KeyTrait<Vignere>
{
public:
	typedef std::string Key;
};
}
#endif