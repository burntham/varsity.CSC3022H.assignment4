#include <iostream>
#include "crypt.h"
#include "cyphers.h"

using namespace brndan022;
int main(int argc, char * argv[])
{
	crypt<Ceaser,Grouping,Packing> c;//("5423");
	//test///
	c.setKey("123");
	return 0;
};
