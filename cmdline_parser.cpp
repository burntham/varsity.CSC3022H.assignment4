/*
 * cmdline_parser.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: simon
 */

#include "cmdline_parser.h"

//-------------------------------------------------------------------------//
// Constructor, initialise the variables_map object with default
// constructor, options_descriptor with the name "Options"
//-------------------------------------------------------------------------//
cmdline_parser::cmdline_parser(void) : vm(), od("Options")
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Add two cmdline options
	// --help or -?
	// --input-file or -i
	od.add_options()
		("help,?", "produce help message")
		((GROUPING +",g").c_str(),"enable grouping")
		((PACKING +",p").c_str(), "enable packing")
		((ENCODING +",e").c_str(), "Perform a decode")
		((DECODING +",d").c_str(), "Perform an encode")
		((INPUTFILE+",i").c_str(), po::value<std::string>(),
			"input file ")
		((OUTPUTFILE+",o").c_str(), po::value<std::string>(),
			"output file name")
		((CKEY+",c").c_str(), po::value<int>(),
			"Ceaser Key")
		((VKEY+",v").c_str(), po::value<std::string>(), "Vignere Key")
		((XKEY+",x").c_str(), po::value<int32_t>(), "XOR Key");
};

//-------------------------------------------------------------------------//
// Process the cmdline
//-------------------------------------------------------------------------//
bool cmdline_parser::process_cmdline(int argc, char * argv[])
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Clear the variable map
	vm.clear();

	// Parse the cmdline arguments defined by argc and argv,
	// looking for the options defined in the od variable,
	// and store them in the vm variable.
	po::store(po::parse_command_line(argc, argv, od), vm);
	po::notify(vm);

	//ensure only one encrypt/decrypt type is specified
	int encCount = vm.count(XKEY)+vm.count(CKEY)+vm.count(VKEY);

	bool success = true;

	if(vm.count(OUTPUTFILE) == 0)
	{
		success = false;
		errors.push_back(
			OUTPUTFILE + " not specified.");
	}

	if(vm.count(INPUTFILE) == 0)
	{
		success = false;
		errors.push_back(
			INPUTFILE + " not specified.");
	}

	if(encCount!=1){
		success = false;
		errors.push_back ("Too many/Few Encryption methods.");
	}

	return success;
}

//-----------------------------------------------------------------------//
// Return the input filename
//-------------------------------------------------------------------------//
std::string cmdline_parser::get_input_filename(void) const
{
	// Return whatever value is stored as a string
	return vm[INPUTFILE].as<std::string>();
}

//-----------------------------------------------------------------------//
// Return Encoding?
//-------------------------------------------------------------------------//
bool cmdline_parser::get_encoding(void) const
{
	// Return Whether encoding has been selected
	 return vm.count(ENCODING) > 0;
}

//-----------------------------------------------------------------------//
// Return Decoding?
//-------------------------------------------------------------------------//
bool cmdline_parser::get_decoding(void) const
{
	// Return Whether encoding has been selected
	 return vm.count(DECODING) > 0;
}

//-----------------------------------------------------------------------//
// Return Cypher Type?
//-------------------------------------------------------------------------//
char cmdline_parser::get_cypher(void) const {
	return (vm.count(CKEY)==1)? 'c': (vm.count(VKEY)==1)? 'v' : 'x';
}

int cmdline_parser::get_ckey(void) const{
	return vm[CKEY].as<int>();
}
std::string cmdline_parser::get_vkey(void) const{
	return vm[VKEY].as<std::string>();
}
int32_t cmdline_parser::get_xkey(void) const{
	return vm[XKEY].as<int32_t>();
}

bool cmdline_parser::should_group(void) const
{
	return vm.count(GROUPING) >0;
};

bool cmdline_parser::should_pack(void) const
{
	return vm.count(PACKING) >0;
};

//-----------------------------------------------------------------------//
// Return output filename
//-------------------------------------------------------------------------//
std::string cmdline_parser::get_output_filename(void) const
{
	// Return whatever value is stored as a string
	return vm[OUTPUTFILE].as<std::string>();
}
//-----------------------------------------------------------------------//
// Should we print cmdline help?
//-------------------------------------------------------------------------//
bool cmdline_parser::should_print_help(void) const
{
	// Are there instances of the help option stored in the variable map
	return vm.count("help") > 0;
}


//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_help(std::ostream & out) const
{
	out << od;
}

//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_errors(std::ostream & out) const
{
	std::cerr << "Error processing command line arguments:" << std::endl;
	std::copy(errors.begin(), errors.end(),
		std::ostream_iterator<std::string>(out, "\n"));
}

// Definition of static strings in the class
const std::string cmdline_parser::INPUTFILE = "input-file";
const std::string cmdline_parser::OUTPUTFILE = "Output-File";

//Definition of static strings in class

	//My static string variables.
	
    const std::string cmdline_parser::XKEY = "XOR-Key";
	const std::string cmdline_parser::VKEY = "Vignere-Key";
	const std::string cmdline_parser::CKEY = "Ceaser-Key";
	const std::string cmdline_parser::GROUPING = "Grouping";
	const std::string cmdline_parser::PACKING = "Packing";
	const std::string cmdline_parser::ENCODING="Encoding";
	const std::string cmdline_parser::DECODING = "Decoding";