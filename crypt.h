

#ifndef _CRYPT_H_
#define _CRYPT_H_

#include <iostream>
#include "crypt_trait.h"
#include "crypt_policy.h"
#include "cyphers.h"
#include <sstream>

namespace brndan022
{
	//crypt trait - this will allow the correct type of crypt to be called
	template <typename cipher, typename Group,typename Pack, typename keyTrait = KeyTrait<cipher> >
	class crypt
	{
	public:
		void setKey(std::string s){
			keyTrait key(s);
		}
		//encode Method
		void encode(std::istream & in, std::ostream & out){
			std::string input;
			std::getline(in, input);

			std::cout<<"PlainText: "<<input<<std::endl;


			for (char & ch:input)//0 represents Null
			{	
				if (ch>=97 && ch<=122)
				{ 
					ch=toupper(ch) - 64;//refactor
				}
				else if(ch>=65 && ch<=90){//if letters are caps already set values under 32 (1 - 27)
					ch-=64;
				}
				else if(ch==32){//handle spaces
					ch=28;
				}
				
			}

		 //Encoder<keyTrait>::encode(input, std::cout, key.KEY());

			//std::cout<<"PlainText: "<<input<<std::endl;

			//out<<input<<std::endl;
		}
	private:
		//typedef Keytype Key;
		typedef keyTrait key;
	};
};


#endif