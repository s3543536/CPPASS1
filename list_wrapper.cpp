#include "list_wrapper.h"

const char* DELIMS = " 1234567890!@#$%^&*()_+=[{}]\\|;:'\"<>,./?-";
bool optimise_with_map = true;


std::string list_wrapper::closest_match(std::list<std::string> dict, std::string word) {
	return "TODO";
}

std::map<std::string, std::string> list_wrapper::check_words(std::list<std::string> dict, std::map<std::string, int> w_counts) {
	std::map<std::string, std::string> map;
	//list dict
	//map w_counts

	for(auto it = w_counts.begin(); it != w_counts.end(); it++) {
		if(it->second < 0) {
			//not in the dictionary
			map[it->first] = it->first + " not found. closest match:\t" + this->closest_match(dict, it->first);
		} else {
			//in the dictionary
			map[it->first] = "" + it->second;
		}
	}
	return map;
}

std::map<std::string, int> list_wrapper::count_words(std::list<std::string> dict, std::list<std::string> text) {
	std::map<std::string, int> map;
	//std::cout << "empty map test: " << out["test"] << "\n";
	for(auto text_it = text.begin(); text_it != text.end(); text_it++) {
		//check: *text_it
		bool match = false;
		
		if(optimise_with_map && map[*text_it] != 0) {
			if(map[*text_it] > 0) {
				//its in dict
				map[*text_it]++;
			} else {
				//its not in dict
				map[*text_it]--;
			}
		}
		if(!optimise_with_map || map[*text_it] == 0) {
			for(auto dict_it = dict.begin(); dict_it != dict.end(); dict_it++) {
				if(*dict_it == *text_it) {
					//match!
					match = true;
					//add to map value
					map[*text_it]++;
					break;
				}
			}
			if(!match) {
				//add to map with -1
				map[*text_it]--;
			}
		}
	}
	return map;
}

std::list<std::string> list_wrapper::load_text(std::string file_name) {
	std::list<std::string> text;
	std::string line;

	std::ifstream myfile(file_name);
	if(myfile.is_open()) {

		std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			//tokenize each line and add into text
			boost::char_separator<char> delims(DELIMS);
			boost::tokenizer<boost::char_separator<char>> toks(line, delims);

			for(auto it = toks.begin(); it != toks.end(); it++) {
				//add each token into the list
				text.push_back(*it);
			}
		}

		std::cout << "closing file\n";
		myfile.close();
	} else {
		std::cout << "can't open file\n";
	}
	return text;
}

std::list<std::string> list_wrapper::load_dict(std::string file_name) {
	std::list<std::string> dict;
	std::string line;

	std::ifstream myfile(file_name);
	if(myfile.is_open()) {

		std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			dict.push_back(line);
		}

		std::cout << "closing file\n";
		myfile.close();
	} else {
		std::cout << "can't open file\n";
	}
	return dict;
}
