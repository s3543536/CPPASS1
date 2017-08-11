#include "main.h"

int main(int argc, char **argv) {

	//create options
	boost::program_options::options_description desc("Allowed Options");
	desc.add_options()
		("help", "produce help message")
		("compression", boost::program_options::value<int>()->default_value(10), "[int] set compression level");

	//store the command into a variable map
	boost::program_options::variables_map var_map;
	try {
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), var_map);
	} catch(boost::program_options::invalid_option_value e) {//catch various bad options
		std::cout << "invalid command argument\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::program_options::unknown_option e) {
		std::cout << "invalid command\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::program_options::invalid_command_line_syntax e) {
		std::cout << "invalid syntax\n";
		display_help(desc);
		return EXIT_FAILURE;
	}
	boost::program_options::notify(var_map);


	//commands
	if(var_map.count("help")) {//if not 0
		display_help(desc);
		return EXIT_SUCCESS;
	}

	if(var_map.count("compression")) {
		std::cout << "compression level command " << var_map["compression"].as<int>() << "\n";
	} else {
		std::cout << "compression level not set\n";
	}
}

void display_help(boost::program_options::options_description desc) {
	std::cout << desc << std::endl;
}
