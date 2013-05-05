

#ifndef _CRYPT_H_
#define _CRYPT_H_

#include <iostream>
#include "crypt_trait.h"
//#include "crypt_policy.h"
#include "cyphers.h"
#include <sstream>
#include <algorithm>
#include "CypherPolicies.h"

namespace brndan022
{
	//crypt trait - this will allow the correct type of crypt to be called
	template <typename cipher, typename Group,typename Pack, typename keyTrait = KeyTrait<cipher> >
	class crypt
	{
	public:

		void setKey(std::string s){
			keyTrait key(s);
			// /std::cout<<key.KEY()<<std::endl;
		}
		//encode Method
		void encode(std::istream & in, std::ostream & out){
			std::string s;
			s = Encoder<Cypher, isGroup, isPacking>::encode(in, out, 2);
		}

		void decode(std::istream & in, std::ostream & out){
			std::string s;
			s = Decoder<Cypher,isGroup, isPacking>::decode(in,out,2);
		}

	private:
		typedef keyTrait key;
		typedef cipher Cypher;
		typedef Group isGroup;
		typedef Pack isPacking;
	};
}


#endif