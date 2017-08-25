#ifndef SETWRAP
#define SETWRAP

#include "edit_distance.h"
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include <algorithm>

extern const char* DELIMS;
extern bool optimise_with_map;

class set_wrapper {
public:
	std::set<std::string> load_dict(std::string file_name);
	std::set<std::pair<std::string, int>> load_text(std::string file_name);
	std::map<std::string, int> count_words(
			std::set<std::string> dict, 
			std::set<std::pair<std::string, int>> text);
	std::map<std::string, std::string> check_words(
			std::set<std::string> dict, 
			std::map<std::string, int> w_counts);
private:
	std::string closest_match(
			std::set<std::string> dict, 
			std::string word);
};

#endif
