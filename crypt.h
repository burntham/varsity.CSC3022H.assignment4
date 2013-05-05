//NOTE : Change key trait to key policy now... (I think)

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
	template <typename cipher, typename Group,typename Pack>
	class crypt
	{
	public:
		void setKey(std::string s){
			key = s;
		}

		//encode Method
		void encode(std::istream & in, std::ostream & out){
			std::string s;
			//int keyz = key->getKEY();
			s = Encoder<Cypher, isGroup, isPacking>::encode(in, out, KeyTrait<Cypher>::convertKey(key));
		}

		void decode(std::istream & in, std::ostream & out){
			std::string s;
			s = Decoder<Cypher,isGroup, isPacking>::decode(in,out,KeyTrait<Cypher>::convertKey(key));
		}

	private:
		std::string key;
		typedef cipher Cypher;
		typedef Group isGroup;
		typedef Pack isPacking;
	};
}


#endif