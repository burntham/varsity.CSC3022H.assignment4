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
	string testinput = "in.txt";
	string testCeaserDecode = "CeaserOut.txt";
	string testoutput = "CeaserOut.txt";

	ifstream fin(testinput);
	crypt<Ceaser,NoGrouping,NoPacking> c;

	ofstream fout(testoutput);
	//test///
	c.setKey("2");
	c.encode(fin, fout );
	
	ifstream decin(testCeaserDecode);

	c.decode(decin, cout);

	return 0;
};
