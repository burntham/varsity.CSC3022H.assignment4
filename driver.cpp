#include <iostream>
#include "crypt.h"
#include "cyphers.h"
#include <fstream>
#include <ostream>

using namespace brndan022;
using namespace std;
int main(int argc, char * argv[])
{
	//test///
	string encodeinput = "in.txt";

	string decodeinput = "CeaserOut.txt";

	ifstream ein(encodeinput);

	//Ceaser Crypt test
	crypt<Ceaser,NoGrouping,NoPacking> c;

	ofstream eout(decodeinput);
	//test/// - still to be implemented
	c.setKey("2");

	c.encode( ein, eout);
	
	ifstream decin(decodeinput);
	ofstream decout(encodeinput);

	c.decode(decin, decout);

	return 0;
};
