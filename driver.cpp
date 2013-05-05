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
	string testoutput = "out.txt";

	ifstream fin(testinput);
	ofstream fout(testoutput);
	
	crypt<Ceaser,Grouping,Packing> c;
	//test///
	c.setKey("2");
	c.encode(fin, cout);

	return 0;
};
