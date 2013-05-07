/*
 * cmdline_parser.h
 *
 *  Created on: 22 Feb 2012
 *      Author: simon
 */

#ifndef CMDLINE_PARSER_H_
#define CMDLINE_PARSER_H_

#include <iostream>
#include <list>
#include <string>

#include <boost/program_options.hpp>

//---------------------------------------------------------------------------//
class cmdline_parser
{
public:
    //-----------------------------------------------------------------------//
	// Constructor
	cmdline_parser(void);

	// Member function that parses command line options
	bool process_cmdline(int argc, char * argv[]);
	// Return the input PGM filename
	std::string get_input_filename(void) const;
	// Return the lightening output PGM filename
	std::string get_lighten_filename(void) const;

	//M Return the darkening output PGM filename
	std::string get_output_filename(void) const;
	bool get_encoding(void) const;
	bool get_decoding(void) const;
	char get_cypher(void) const;
	int get_ckey(void) const;
	std::string get_vkey(void) const;
	int32_t get_xkey(void) const;
	bool should_group(void) const;
	bool should_pack(void) const;
	void print_errors(std::ostream & out) const;
	bool should_print_help(void) const;
	// Output help to the specified output stream
	void print_help(std::ostream & out) const;

private:
    //-----------------------------------------------------------------------//
	// Member variables
	boost::program_options::variables_map vm;
	boost::program_options::options_description od;
	std::list<std::string> errors;

    //-----------------------------------------------------------------------//
	// Static string variables
	static const std::string INPUTFILE;
	static const std::string DARKENFILE;
	static const std::string DARKENAMOUNT;
	static const std::string LIGHTENFILE;
	static const std::string LIGHTENAMOUNT;
	static const std::string INVERTFILE;

	//My static string variables.
	static const std::string OUTPUTFILE;
	static const std::string XKEY;
	static const std::string VKEY;
	static const std::string CKEY;
	static const std::string GROUPING;
	static const std::string PACKING;
	static const std::string ENCODING;
	static const std::string DECODING;

};

#endif /* CMDLINE_PARSER_H_ */
