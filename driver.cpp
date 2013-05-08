//USEFULL!

#include <iostream>
#include "crypt.h"
#include "cyphers.h"
#include <fstream>
#include <ostream>
#include "cmdline_parser.h"
#include <cmath>


using namespace brndan022;
using namespace std;

template <typename CypherType, typename Group, typename Pack, typename KeyType>
	void levelAction(KeyType key, bool encode, std::istream & in, std::ostream & out)
	{
		Crypt<CypherType,Group,Pack> c;
		c.setKey(key);
		if (encode){
			c.encode(in,out);
		}else{
			c.decode(in,out);
		}
	}

template<typename CypherType, typename Group, typename KeyType>
	void level2(KeyType key, bool encode, bool packing , std::istream & in, std::ostream & out)
	{
		if (packing){
			levelAction<CypherType, Group, Packing, KeyType>(key, encode, in, out);
		}else{
			levelAction<CypherType, Group, NoPacking, KeyType>(key, encode, in, out);
		}
	}

template <typename CypherType, typename KeyType = typename KeyTrait<CypherType>::Key >
	void level1(KeyType key, bool encode, bool grouping, bool packing , std::istream & in, std::ostream & out)
	{	
		if (grouping){
			level2<CypherType, Grouping, KeyType>(key, encode, packing , in, out);
		}
		else{
			level2<CypherType, NoGrouping, KeyType>(key, encode,packing , in, out);
		}		
	}

int main(int argc, char * argv[])
{
	cmdline_parser parser;
	if(!parser.process_cmdline(argc, argv))
	{
		// Complain to the standard error stream
		parser.print_errors(cerr);
		// Follow up with help on standard output
		parser.print_help(cout);
		return 1;
	}
	//char cypherType = parser.get_cypher();
	string inFileName = parser.get_input_filename();
	ifstream input(inFileName);

	string outFileName = parser.get_output_filename();
	ofstream output(outFileName);

	if (parser.get_cypher()=='c'){
		level1<Ceaser>(parser.get_ckey(), parser.get_encoding(), parser.should_group(), parser.should_pack(), input, output);
	}else if(parser.get_cypher()=='v'){
		level1<Vignere>(parser.get_vkey(), parser.get_encoding(), parser.should_group(), parser.should_pack(), input, output);
	}


	return 0;
};
