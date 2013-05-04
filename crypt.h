

#ifndef _CRYPT_H_
#define _CRYPT_H_

#include <iostream>
#include "crypt_trait.h"
#include "cyphers.h"

namespace brndan022
{
	//crypt trait - this will allow the correct type of crypt to be called
	template <typename cipher, typename group,typename pack, typename keyTrait = KeyTrait<cipher> >
	class crypt
	{
	public:
		void setKey(std::string s){
			keyTrait key(s);

			//test///
			key.printKey();
		}
	private:
		//typedef Keytype Key;
		typedef keyTrait key;
	};
};


#endif