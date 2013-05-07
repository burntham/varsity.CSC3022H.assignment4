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
	//crypt Policy
	template <typename cipher, typename Group,typename Pack, typename keyType = typename KeyTrait<cipher>::Key>
	class Crypt
	{
	public:
		void setKey(keyType s){
			keyz = s;
		}

		//encode Method
		void encode(std::istream & in, std::ostream & out){
			std::string s;
			s = Encoder<Cypher, isGroup, isPacking>::encode(in, out, keyz);
		}

		void decode(std::istream & in, std::ostream & out){
			std::string s;
			s = Decoder<Cypher, isGroup, isPacking>::decode(in,out,keyz);
		}

	private:
		keyType keyz;
		typedef keyType key;
		typedef cipher Cypher;
		typedef Group isGroup;
		typedef Pack isPacking;
	};
}


#endif