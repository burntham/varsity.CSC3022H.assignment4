//USEFULL!!!

#ifndef _CYPHERPOLICIES_H_
#define _CYPHERPOLICIES_H_

#include "cyphers.h"
#include <sstream>
#include <cmath>
namespace brndan022{

//Grouping
template <typename group>
	class Groupit
	{
		public:
			static std::string groupMyString(std::string s){
			return s;
		}
	};

//Group it!!!
template <>
	class Groupit<Grouping>{
	public:
		static std::string groupMyString(std::string s){
			//std::cout<<"before grouping:"<<s<<std::endl;
			s.erase(std::remove_if(s.begin(),s.end(),[](char & ch){return(ch == ' '); } ),s.end());
			int length = s.length();
			for (int i = 5; i < s.length(); i+=6)
			{
				s.insert(i," ");						
			}
			//std::cout<<"after grouping:"<<s<<std::endl;
			return s;
		};
	};

//Encoder general template:
template <typename Type,typename Group, typename Pack> 
	class Encoder{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int key)
		{	
			return "testEncode";
		};		
	};

//Encoder template - Ceaser Cypher
//cypher and grouping working
template <typename Group, typename Pack>
	class Encoder<Ceaser, Group , Pack>{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int key)
		{
			std::string plain;
			std::getline(in, plain);
			
			std::cout<<"about to encode: "<<plain<<std::endl;

			//ENCODING
			//make everything upper case and each character capable of being read
			std::transform (plain.begin(), plain.end(), plain.begin(), 
				[](char& c){return ((c>=65 && c<=90)? c: (c>=96 && c<=122) ? (toupper(c)) : (c==' ')?' ':'?');});

			std::transform (plain.begin(), plain.end(),plain.begin(),
				[&key] (char& c){return (c!=' ' && c!= '?')? (((c-65)+key)%26)+65: c;});
			//END OF ENCODING
			std::cout<<"encoded:"<<plain<<std::endl;
			plain = Groupit<Group>::groupMyString(plain);
			out<<plain<<std::endl;
			return plain;
		};
	};

//Encoder template - Ceaser Cypher
//wip vignere
template <typename Group, typename Pack>
	class Encoder<Vignere, Group , Pack>{
	public:
		static std::string encode(std::istream & in, std::ostream & out, std::string key)
		{
			std::string plain;
			std::getline(in, plain);

			std::cout<<"about to encode: "<<plain<<std::endl;
			

			//ENCODING
			//make everything upper case and each character capable of being read
			std::transform (plain.begin(), plain.end(), plain.begin(), 
				[](char& c){return ((c>=65 && c<=90)? c-65: (c>=96 && c<=122) ? (toupper(c)-65) : (c==' ')?26:27);});


			int keypos=0;
			std::transform(plain.begin(), plain.end(), plain.begin(), 
				[&key,&keypos](char& c)
				{
					char keyChar = std::toupper(key[keypos])-65;
					c = (c==26)? ' ' : ( c==27)? '?' : ((c+keyChar)%26)+65;
					keypos = (keypos + 1)%key.length();
					if (c==' ' || c=='?') keypos=(keypos -1)%key.length();
					return c;});
			//END OF ENCODING		

			//Group it
			plain = Groupit<Group>::groupMyString(plain);
			//OUTPUT IT
			std::cout<<"encoded:"<<plain<<std::endl;
			out<<plain<<std::endl;
			return plain;//returned for testing purposes
		};
	};

template <typename Group, typename Pack>
	class Encoder<Xor, Group , Pack>{
	public:
		static std::string encode(std::istream & in, std::ostream & out, int32_t key)
		{//TO BE IMPLEMENTED
			std::string plain;
/*			std::getline(in, plain);
			
			std::cout<<"about to encode: "<<plain<<std::endl;

			//ENCODING
			//make everything upper case and each character capable of being read
			std::transform (plain.begin(), plain.end(), plain.begin(), 
				[](char& c){return ((c>=65 && c<=90)? c: (c>=96 && c<=122) ? (toupper(c)) : (c==' ')?' ':'?');});

			std::transform (plain.begin(), plain.end(),plain.begin(),
				[&key] (char& c){return (c!=' ' && c!= '?')? (((c-65)+key)%26)+65: c;});
			//END OF ENCODING
			std::cout<<"encoded:"<<plain<<std::endl;
			plain = Groupit<Group>::groupMyString(plain);
			out<<plain<<std::endl;*/
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
template <typename Group, typename Pack>
	class Decoder<Ceaser, Group ,Pack>
	{
	public:
		static std::string decode(std::istream & in, std::ostream & out, int key)
		{
			std::string cypherText;
			getline(in, cypherText);

			std::cout<<"Decode attempt: "<<cypherText<<std::endl;
			//Convert cypherText into normal text
			std::transform (cypherText.begin(), cypherText.end(), cypherText.begin(), 
				[&key](char &c){return (c==' ' || c== '?')? c : ((c-65-key)%26>=0)? (c-65-key)%26+65 : 65+((26-abs((c-key-65)%26)));});

			//some output
			std::cout<<"decoded:"<<cypherText<<std::endl;
			out<<cypherText;
			return cypherText;	
		}
	};

//Decode an unpacked Ceaser Cipher
template <typename Group, typename Pack>
	class Decoder<Vignere, Group ,Pack>
	{
	public:
		static std::string decode(std::istream & in, std::ostream & out, std::string key)
		{
			std::string cypherText;
			getline(in, cypherText);

			std::cout<<"Decode attempt: "<<cypherText<<std::endl;

			int keypos=0;
			std::transform(cypherText.begin(), cypherText.end(), cypherText.begin(), 
				[&key,&keypos](char& c)
				{
					char keyChar = std::toupper(key[keypos])-65;
					char posC = (c-65-keyChar)%26;
					c = (c=='?')? c: (c==' ')? c: (posC>=0)? posC+65 : 26+posC+65;
					keypos = (keypos + 1)%key.length();
					if (c==' ' || c=='?') keypos=(keypos -1)%key.length();
					return c;});
			//some output
			std::cout<<"decoded:"<<cypherText<<std::endl;
			out<<cypherText;
			return cypherText;	
		}
	};


}
#endif