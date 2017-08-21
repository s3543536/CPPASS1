#ifndef CUSTLISTWRAP
#define CUSTLISTWRAP

#include "custom_list.h"
#include "edit_distance.h"
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include <algorithm>

extern const char* DELIMS;
extern bool optimise_with_map;

class custom_list_wrapper {
public:
	linked_list load_dict(std::string file_name);
	linked_list load_text(std::string file_name);
	std::map<std::string, int> count_words(linked_list const& dict, linked_list const& text);
	std::map<std::string, std::string> check_words(linked_list const& dict, std::map<std::string, int> w_counts);
//private:
	std::string closest_match(linked_list const& dict, std::string word);
};

#endif
