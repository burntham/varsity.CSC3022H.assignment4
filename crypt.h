//USEFULL

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
	template <typename cipher, typename Group,typename Pack, 
		typename keyType = typename KeyTrait<cipher>::Key>
	class Crypt
	{
	public:
		void setKey(keyType s){
			keyz = s;
			std::cout<<"The key is:"<<s<<std::endl;
		}

		//encode Method
		void encode(std::istream & in, std::ostream & out){
			Encoder<cipher, Group, Pack>::encode(in, out, keyz);
		}

		void decode(std::istream & in, std::ostream & out){			
			Decoder<cipher, Group, Pack>::decode(in , out,keyz);
		}

	private:
		
		typedef keyType key;
		keyType keyz;
		//typedef cipher Cypher;
/*		typedef Group isGroup;
		typedef Pack isPacking;*/
	};
}


#endif