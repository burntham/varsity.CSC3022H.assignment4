Daniel Burnham-King
c++ Assignment 4
Templates, ciphers, STL and Traits

Compilation:
	navigate to the folder in which the below mentioned .cpp files are stored (assuming that by you reading this, the tarball is already extracted). Typing 'make' will compile the program.

	Make encode and Make decode will also both compile the program (more later).

	Note : tested with g++ -std=11

Execution: 
	As mentioned before, this assignment can be run by typing 'make encode' or 'make decode' in terminal.

	The make file can be used to specify input/output files, grouping, cipher and key and the file name easily (refer to comments in makefile)

	if this is not wanted, then after compilation type './ciph.out' in terminal with the commands specified in the assignment brief. (-x key -i in,txt etc)

NOTE:
	The makefile has been constructed to make the readers life easier.

FileList:

Driver.cpp:
	Contains main and templated functions which aid in the calling of the correct cipher combination

CipherPolicies.h:
	Templated Policies used for Grouping, Encoding and Decoding.
	note: This is where Packing would have been placed

CipherTraits.h:
	This holds the KeyTrait templated class - this is used as a trait of the ciphers to simplify key input. (refer to templated functions in driver.cpp)

crypt.h:
	Crypt class, used to create a crypt object that stores the key (keytype found using KeyTrait in CipherTrait.h). Aswell as making use of Cipher polices for encoding.

CipherTypes.h:
	Contains Type classes used for templating

Makfile:
	This awesome piece of awesomness can (I hope) be used for more than just compiling - check it out :)

Readme.txt:
	I don't think a description is required, here's a video of an old lady using a VR headset http://www.youtube.com/watch?v=pAC5SeNH8jw

in.txt, out.txt:
	Used for input and output.

NOTE:
	Packing has not been implemented - everything else seems to work though

TLDR?:
	No packing.
	Use Makefile.
	lower case is always converted to upper (for everything)
	None alphanumeric are mapped to '?'.
	Give ALL the marks. :D
