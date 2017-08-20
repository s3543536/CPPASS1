#include "main.h"

#define po program_options
//using po=program_options;

int main(int argc, char **argv) {

	//create options
	boost::po::options_description desc("Allowed Options");
	desc.add_options()
		("help,h", "produce help message")
		("specify_data_structure,s", boost::po::value<std::string>()->default_value("list"), "specify data structure, can be one of:\nlist, vector, set, custom_list or custom_tree")
		("dictionary,d", boost::po::value<std::string>()->default_value("./data/dict.dat"), "specify dictionary file")
		("text,t", boost::po::value<std::string>()->default_value("./data/sml.txt"), "specify text file")
		("output,o", boost::po::value<std::string>()->default_value("./output.txt"), "specify output file");
		//("compression,c", boost::po::value<int>()->default_value(10), "[int] set compression level");



	//store the command into a variable map and catch bad syntax
	boost::po::variables_map var_map;
	try {
		boost::po::store(boost::po::parse_command_line(argc, argv, desc), var_map);
	} catch(boost::po::invalid_option_value e) {
		std::cout << "invalid command argument (wrong type?)\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::po::unknown_option e) {
		std::cout << "invalid command (unknown option?)\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::po::invalid_command_line_syntax e) {
		std::cout << "invalid syntax (argument missing?)\n";
		display_help(desc);
		return EXIT_FAILURE;
	} catch(boost::po::multiple_occurrences e) {
		//multiple options
		std::cout << "invalid syntax (duplicate option?)\n";
	}
	boost::po::notify(var_map);

	//commands
	if(var_map.count("help") || var_map.size() == 0) {//if not 0
		display_help(desc);
		return EXIT_SUCCESS;
	}

	if(!var_map.count("specify_data_structure")
		   	|| !var_map.count("dictionary")
			|| !var_map.count("text")
			|| !var_map.count("output")) {
		//not enough options
		display_help(desc);
		return EXIT_SUCCESS;
	}

	std::string data_str = var_map["specify_data_structure"].as<std::string>();
	if(data_str == "list") {
		std::cout << "list data structure\n";
	} else if(data_str == "vector") {
		std::cout << "vector data structure\n";
	} else if(data_str == "set") {
		std::cout << "set data structure\n";
	} else if(data_str == "custom_list") {
		std::cout << "custom_list data structure\n";
	} else if(data_str == "custom_tree"){
		std::cout << "custom_tree data structure\n";
	} else {
		display_help(desc);
		return EXIT_SUCCESS;
	}

	list_wrapper wrap;

	std::list<std::string> dict = wrap.load_dict(var_map["dictionary"].as<std::string>());
	std::list<std::string> text = wrap.load_text(var_map["text"].as<std::string>());

	std::cout << "starting dictionary search\n";
	std::map<std::string, int> countmap = wrap.count_words(dict, text);
	std::cout << "ending dictionary search\n";

	std::cout << "starting count\n";
	std::map<std::string, std::string> wordmap = wrap.check_words(dict, countmap);
	std::cout << "ending count\n";

	/*
	for(auto it = outmap.begin(); it != outmap.end(); it++) {
		std::cout << "asdf\t";
		std::cout << it->first << ": " << it->second << "\n";
	}*/

/*
	for(auto it = dict.begin(); it != dict.end(); it++) {
		std::cout << "\t" << *it << "\n";
	}
*/
/*
	for(auto it = text.begin(); it != text.end(); it++) {
		std::cout << "\t" << *it << "\n";
	}
*/
	return EXIT_SUCCESS;
}

void write_to_file(std::string filename, std::map<std::string, std::string> lines) {
	std::cout << "TODO\n";
}

void display_help(boost::po::options_description desc) {
	std::cout << desc << std::endl;
}
