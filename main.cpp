#include "main.h"

int main(int argc, char **argv) {

	//create options
	boost::program_options::options_description desc("Allowed Options");
	desc.add_options()
		("help", "produce help message")
		("compression", boost::program_options::value<int>(), "set compression level");

	//store the command into a variable map
	boost::program_options::variables_map var_map;
	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), var_map);
	boost::program_options::notify(var_map);

	if(var_map.count("help")) {
		std::cout << desc << "\n";
		return 1;
	}

	if(var_map.count("compression")) {
		std::cout << "compression level command " << var_map["compression"].as<int>() << "\n";
	} else {
		std::cout << "compression level not set\n";
	}
}
