#include "main.h"
#include <string>
#include <iostream>

#define po program_options
//using po=program_options;

int main(int argc, char **argv) {

	//create options
	boost::po::options_description desc("Allowed Options");
	desc.add_options()
		("help,h", "produce help message")
		("compression,c", boost::po::value<int>()->default_value(10), "[int] set compression level");



	//store the command into a variable map
	boost::po::variables_map var_map;
	try {
		boost::po::store(boost::po::parse_command_line(argc, argv, desc), var_map);
	} catch(boost::po::invalid_option_value e) {//catch various bad options
		std::cout << "invalid command argument\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::po::unknown_option e) {
		std::cout << "invalid command\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::po::invalid_command_line_syntax e) {
		std::cout << "invalid syntax\n";
		display_help(desc);
		return EXIT_FAILURE;
	}
	boost::po::notify(var_map);


	//commands
	if(var_map.count("help") || var_map.count("h")) {//if not 0
		display_help(desc);
		return EXIT_SUCCESS;
	}

	if(var_map.count("dict")) {
		std::cout << "opening file at '" << var_map["dict"].as<std::string>() << "'\n";
		return EXIT_SUCCESS;
	}

	if(var_map.count("compression")) {
		std::cout << "compression level command " << var_map["compression"].as<int>() << "\n";
	} else {
		std::cout << "compression level not set\n";
	}
}

void display_help(boost::po::options_description desc) {
	std::cout << desc << std::endl;
}
