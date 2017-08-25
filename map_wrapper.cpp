#include "map_wrapper.h"

std::string map_wrapper::closest_match(std::map<std::string, int> dict, std::string word) {
	//edit_distance::calculate(str1, str2);
	int min = (int)dict.size();
	std::string shortest = word;

	for(auto it = dict.begin(); it != dict.end(); it++) {
		//std::cout << "calculating the distance between: " << word << ", " << *it << "\n";
		int asdf = std::min(min, edit_distance::calculate(word, it->first));
		if(asdf < min) {
			min = asdf;
			shortest = (it->first);
		}
	}
	return shortest;
}

std::map<std::string, std::string> map_wrapper::check_words(std::map<std::string, int> dict, std::map<std::string, int> w_counts) {
	std::map<std::string, std::string> map;
	//vector dict
	//map w_counts

	for(auto it = w_counts.begin(); it != w_counts.end(); it++) {
		if(it->second < 0) {
			//not in the dictionary
			map[it->first] = this->closest_match(dict, it->first);
		} else {
			//in the dictionary
			//std::cout << it->second << "\t";
			map[it->first] = std::to_string(it->second);
		}
	}
	return map;
}

std::map<std::string, int> map_wrapper::count_words(std::map<std::string, int> dict, std::map<std::string, int> text) {
	std::map<std::string, int> map;
	//std::cout << "empty map test: " << out["test"] << "\n";
	for(auto text_it = text.begin(); text_it != text.end(); text_it++) {
		
		if(dict[text_it->first] != 0) {
			//its in the dictionary, make it positive
			map[text_it->first] = text_it->second;
		} else {
			//its not in the dictionary, make it negative
			map[text_it->first] = -1 * text_it->second;
		}
	}
	return map;
}

std::map<std::string, int> map_wrapper::load_text(std::string file_name) {
	std::map<std::string, int> text;
	std::string line;

	std::ifstream myfile(file_name);
	if(myfile.is_open()) {

		//std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			//tokenize each line and add into text
			boost::char_separator<char> delims(DELIMS);
			boost::tokenizer<boost::char_separator<char>> toks(line, delims);

			for(auto it = toks.begin(); it != toks.end(); it++) {
				//add each token into the vector
				text[boost::algorithm::to_lower_copy(*it)]++;
			}
		}

		//std::cout << "closing file\n";
		myfile.close();
	}
	return text;
}

std::map<std::string, int> map_wrapper::load_dict(std::string file_name) {
	std::map<std::string, int> dict;
	std::string line;

	std::ifstream myfile(file_name);
	if(myfile.is_open()) {

		//std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			dict[line]++;
		}

		//std::cout << "closing file\n";
		myfile.close();
	}
	return dict;
}
