//USEFULL!!!

#ifndef _CYPHERPOLICIES_H_
#define _CYPHERPOLICIES_H_

#include "cyphers.h"
#include <sstream>
#include <cmath>
namespace brndan022{

//Encoder general template:
template <typename Type,typename Group, typename Pack> 
	class Encoder{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int key)
		{	
			return "testEncode";
		};
		
	};

//Encoder template - Ceaser cypher, no grouping no packing
template <>
	class Encoder<Ceaser, NoGrouping, NoPacking>{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int key)
		{
			std::string plain;
			std::getline(in, plain);
			std::cout<<"about to encode: "<<plain<<std::endl;

			//make everything upper case and each character capable of being read
			std::transform (plain.begin(), plain.end(), plain.begin(), 
				[](char& c){return ((c>=65 && c<=90)? c: (c>=96 && c<=122) ? (toupper(c)) : (c==' ')?' ':'?');});

			std::transform (plain.begin(), plain.end(),plain.begin(),
				[&key] (char& c){return (c!=' ' && c!= '?')? (((c-65)+key)%26)+65: c;});

			std::cout<<"encoded:"<<plain<<std::endl;
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

			std::cout<<"Decode attempt: "<<cypherText<<std::endl;
			//Convert cypherText into normal text
			std::transform (cypherText.begin(), cypherText.end(), cypherText.begin(), 
				[&key](char &c){return (c==' ' || c== '?')? c : ((c-65-key)%26>=0)? (c-65-key)%26+65 : 65+(26-abs((c-key-65)%26));});

			//some output
			std::cout<<"decoded:"<<cypherText<<std::endl;
			out<<cypherText;
			return cypherText;	
		}
	};
}
#endif