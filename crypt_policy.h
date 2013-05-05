#ifndef _CRYPT_POLICY_H_
#define _CRYPT_POLICY_H_

#include <iostream>
#include <sstream>

namespace brndan022{

	//Encoding
	template <typename keyTrait> class Encoder
	{
	public:
		static std::string encoded;
	};

	

	template <> class Encoder <KeyTrait<Ceaser>>{
	public:
		static std::string encode(std::string & input, std::ostream & output , int key){
			std::istringstream is(input);

			for (char & c : input){
				std::cout<<c;
				//c+=key.KEY();
				output<<c;
			}

			//test///
			std::string test("pie");
			return test;
		}
	};
};
#endif