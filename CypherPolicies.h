#ifndef _CYPHERPOLICIES_H_
#define _CYPHERPOLICIES_H_

#include "cyphers.h"
#include <sstream>
namespace brndan022{

//Encoder general template:
template <typename Type,typename Group, typename Pack> 
	class Encoder{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int key){return "testEncode";};
		
	};

//Encoder template - Ceaser cypher, no grouping no packing
template <>
	class Encoder<Ceaser, NoGrouping, NoPacking>{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int key)
		{
			std::string plain;
			std::getline(in, plain);
			std::cout<<"about to incode: "<<plain<<std::endl;

			//make everything upper case and each character capable of being read
			std::transform (plain.begin(), plain.end(), plain.begin(), 
				[](char &c){return (c>=97 && c<=122) ? (toupper(c) -64) : (c>=65 && c<=90) ? (c-64): (c==32) ? 28 : c;});
			out<<plain<< std::endl;
			return plain;
		};
	};

//Decoder Template
template <typename Type,typename Group, typename Pack> 
	class Decoder
	{

	public:
		static std::string decode(std::istream & in, std::ostream & out, int key){return "testDecode";};		
	};
//Decode an unpacked Ceaser Cipher
template <typename Group>
	class Decoder<Ceaser, Group ,NoPacking>
	{
	public:
		static std::string decode(std::istream & in, std::ostream & out, int key)
		{
			std::string cypherText;
			getline(in, cypherText);

			std::transform (cypherText.begin(), cypherText.end(), cypherText.begin(), 
				[](char &c){return (c>0 && c<28)? c+64 : (c == 28)? 32: c;});

			return "testDecode";	
		}
	};
}
#endif