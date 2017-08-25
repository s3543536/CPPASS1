//by Angel English s3543536
#ifndef CUSTTREEWRAP
#define CUSTTREEWRAP

#include "vector_wrapper.h"
#include "custom_tree.h"
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
#include <random>
#include <iterator>

extern const char* DELIMS;
extern bool optimise_with_map;
extern bool shuffle_tree;

class custom_tree_wrapper {
public:
	binary_search_tree load_dict(std::string file_name);
	binary_search_tree load_text(std::string file_name);
	std::map<std::string, int> count_words(binary_search_tree const& dict, binary_search_tree const& text);
	std::map<std::string, std::string> check_words(binary_search_tree const& dict, std::map<std::string, int> w_counts);
//private:
	std::string closest_match(binary_search_tree const& dict, std::string word);
};


#endif
