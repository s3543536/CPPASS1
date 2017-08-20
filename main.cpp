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


	//load_file_test(var_map["dictionary"].as<std::string>());
	//write_file_test(var_map["dictionary"].as<std::string>(), var_map["output"].as<std::string>());
	std::list<std::string> dict = load_dict(var_map["dictionary"].as<std::string>());

	for(auto it = dict.begin(); it != dict.end(); it++) {
		std::cout << "\t" << *it << "\n";
	}

	//boost::tokenizer<,,>();

}

std::list<std::string> load_dict(std::string fname) {
	std::list<std::string> dict;
	std::string line;

	std::ifstream myfile(fname.c_str());

	if(myfile.is_open()) {
		std::cout << "opening file\n";

		while(std::getline(myfile, line)) {
			dict.push_back(line);
		}

		std::cout << "closing file\n";
		myfile.close();

		return dict;
	} else {
		std::cout << "can't open file\n";
		return dict;
	}
}

void write_file_test(std::string iname, std::string oname) {
	std::string line;
	//std::ifstream myfile("./data/sml.txt");
	std::ifstream myfile;
	std::ofstream outfile;

	outfile.open(oname.c_str());
	myfile.open(iname.c_str());

	if(myfile.is_open() && outfile.is_open()) {
		std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			outfile << line << "\n";
		}
	} else {
		std::cout << "file not open\n";
	}
	if(myfile.is_open()) { myfile.close(); }
	if(outfile.is_open()) { outfile.close(); }
}

void load_file_test(std::string fname) {
	std::string line;
	//std::ifstream myfile("./data/sml.txt");
	std::ifstream myfile;
	myfile.open(fname);

	if(myfile.is_open()) {
		std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			std::cout << line << "\n";
		}
		myfile.close();
	} else {
		std::cout << "file not open\n";
	}
}

void display_help(boost::po::options_description desc) {
	std::cout << desc << std::endl;
}
