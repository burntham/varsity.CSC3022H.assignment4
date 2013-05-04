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
		KeyTrait(std::string key_): keyz(std::stoi(key_)){};

	//test/////
	void printKey(void){
		std::cout<<keyz<<std::endl;
	}

	private:
		int keyz;

};
	
}
#endif