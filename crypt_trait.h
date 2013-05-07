//USEFULL

#ifndef _CRYPT_TRAIT_H_
#define _CRYPT_TRAIT_H_

#include "cyphers.h"


namespace brndan022{


//generalised keytrait template
template <typename cyphertype> 
class KeyTrait{
};

//template for key used on Ceaser cypher
template <>
class KeyTrait <Ceaser> 
{
public:
	typedef int Key;
};
}
#endif