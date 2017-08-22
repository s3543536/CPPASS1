#include "custom_tree_wrapper.h"

//const char* DELIMS = " 1234567890!@#$%^&*()_+=[{}]\\|;:'\"<>,./?\t";
//bool optimise_with_map = true;


std::string custom_list_wrapper::closest_match(binary_search_tree const& dict, std::string word) {
	//edit_distance::calculate(str1, str2);
	int min = INT_MAX;
	std::string shortest = word;

	for(auto it = dict.head.get(); it != nullptr; it = it->get_next()) {
		//std::cout << "calculating the distance between: " << word << ", " << *it << "\n";
		int asdf = std::min(min, edit_distance::calculate(word, it->get_data()));
		if(asdf < min) {
			min = asdf;
			shortest = it->get_data();
		}
	}
	return shortest;
}

std::map<std::string, std::string> custom_list_wrapper::check_words(binary_search_tree const& dict, std::map<std::string, int> w_counts) {
	std::map<std::string, std::string> map;
	//list dict
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

std::map<std::string, int> custom_list_wrapper::count_words(binary_search_tree const& dict, binary_search_tree const& text) {
	std::map<std::string, int> map;
	//std::cout << "empty map test: " << out["test"] << "\n";
	for(auto text_it = text.head.get(); text_it != nullptr; text_it = text_it->get_next()) {
		//check: *text_it
		bool match = false;
		
		if(optimise_with_map && map[text_it->get_data()] != 0) {
			if(map[text_it->get_data()] > 0) {
				//its in dict
				map[text_it->get_data()]++;
			} else {
				//its not in dict
				map[text_it->get_data()]--;
			}
		}
		if(!optimise_with_map || map[text_it->get_data()] == 0) {
			for(auto dict_it = dict.head.get(); dict_it != nullptr; dict_it = dict_it->get_next()) {
				if((*dict_it).get_data() == (*text_it).get_data()) {
					//match!
					match = true;
					//add to map value
					map[(*text_it).get_data()]++;
					break;
				}
			}
			if(!match) {
				//add to map with -1
				map[(*text_it).get_data()]--;
			}
		}
	}
	return map;
}

binary_search_tree custom_list_wrapper::load_text(std::string file_name) {
	binary_search_tree text;
	std::string line;

	std::ifstream myfile(file_name);
	if(myfile.is_open()) {

		//std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			//tokenize each line and add into text
			boost::char_separator<char> delims(DELIMS);
			boost::tokenizer<boost::char_separator<char>> toks(line, delims);

			for(auto it = toks.begin(); it != toks.end(); it++) {
				//add each token into the list
				text.add(boost::algorithm::to_lower_copy(*it));
			}
		}

		//std::cout << "closing file\n";
		myfile.close();
	}
	return text;
}

binary_search_tree custom_list_wrapper::load_dict(std::string file_name) {
	binary_search_tree dict;
	std::string line;

	std::ifstream myfile(file_name);
	if(myfile.is_open()) {

		//std::cout << "opening file\n";
		while(std::getline(myfile, line)) {
			dict.add(line);
		}

		//std::cout << "closing file\n";
		myfile.close();
	}
	return dict;
}
