#include <iostream>
#include "crypt.h"
#include "cyphers.h"
#include <fstream>
#include <ostream>
#include "cmdline_parser.h"


	using namespace brndan022;
	using namespace std;

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

	char cypherType = parser.get_cypher();



	//test///
	string encodeinput = "in.txt";

	string decodeinput = "CeaserOut.txt";

	ifstream ein(encodeinput);

	//Ceaser Crypt test
	Crypt<Ceaser,NoGrouping,NoPacking> c;

	ofstream eout(decodeinput);
	//test/// - still to be implemented
	c.setKey("2");

	c.encode( ein, eout);
	
	ifstream decin(decodeinput);
	ofstream decout(encodeinput);

	c.decode(decin, decout);

	return 0;
};
