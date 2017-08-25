//by Angel English s3543536
#include "custom_tree_wrapper.h"

std::string custom_tree_wrapper::closest_match(binary_search_tree const& dict, std::string word) {
	//edit_distance::calculate(str1, str2);
	int min = INT_MAX;
	std::string shortest = word;

	for(auto it = dict.begin(); *it != nullptr; it++) {
		//std::cout << "calculating the distance between: " << word << ", " << *it << "\n";
		int asdf = std::min(min, edit_distance::calculate(word, it->get_data()));
		if(asdf < min) {
			min = asdf;
			shortest = it->get_data();
		}
	}
	return shortest;
}

std::map<std::string, std::string> custom_tree_wrapper::check_words(binary_search_tree const& dict, std::map<std::string, int> w_counts) {
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

std::map<std::string, int> custom_tree_wrapper::count_words(binary_search_tree const& dict, binary_search_tree const& text) {
	std::map<std::string, int> map;
	//std::cout << "text size: " << text.size() << "\n";
	//std::cout << "dict size: " << dict.size() << "\n";
	int count = 0;
	//std::cout << "empty map test: " << out["test"] << "\n";
	for(auto text_it = text.begin(); *text_it != nullptr; text_it++) {
		//check: *text_it
		count++;

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

			if(dict.search(text_it->get_data())) {
				//match!
				//add to map value
				map[text_it->get_data()]++;
			} else {
				//add to map with -1
				map[text_it->get_data()]--;
			}
		}
	}
	//std::cout << "count: " << count << "\n";
	return map;
}

binary_search_tree custom_tree_wrapper::load_text(std::string file_name) {
	binary_search_tree text;
	//int count = 0;

	if(shuffle_tree) {
		vector_wrapper wrap;
		std::random_device rd;
		std::mt19937 gen(rd());

		//load into a vector
		std::vector<std::string> vect = wrap.load_text(file_name);

		//shuffle
		std::shuffle(vect.begin(), vect.end(), gen);

		//load into binary search tree
		for(auto it = vect.begin(); it != vect.end(); it++) {
			//std::cout << count++ << "\n";
			text.add(boost::algorithm::to_lower_copy(*it));
		}
	} else {
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
					//std::cout << count++ << "\n";
					text.add(boost::algorithm::to_lower_copy(*it));
				}
			}

			//std::cout << "closing file\n";
			myfile.close();
		}
	}
	return text;
}

binary_search_tree custom_tree_wrapper::load_dict(std::string file_name) {
	binary_search_tree dict;
	//int count = 0;

	if(shuffle_tree) {
		vector_wrapper wrap;
		std::random_device rd;
		std::mt19937 gen(rd());

		//load into a vector
		std::vector<std::string> vect = wrap.load_dict(file_name);

		//shuffle
		std::shuffle(vect.begin(), vect.end(), gen);

		//load into binary search tree
		for(auto it = vect.begin(); it != vect.end(); it++) {
			//std::cout << count++ << "\n";
			dict.add(boost::algorithm::to_lower_copy(*it));
		}
	} else {
		std::string line;

		std::ifstream myfile(file_name);
		if(myfile.is_open()) {

			//std::cout << "opening file\n";
			while(std::getline(myfile, line)) {
				//std::cout << count++ << "\n";
				dict.add(line);
			}

			//std::cout << "closing file\n";
			myfile.close();
		}
	}
	return dict;
}
