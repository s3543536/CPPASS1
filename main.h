#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include "list_wrapper.h"
#include "vector_wrapper.h"
#include "custom_tree_wrapper.h"
#include "custom_list_wrapper.h"

extern const char* DELIMS;
extern bool optimise_with_map;
extern bool shuffle_tree;

void display_help(boost::program_options::options_description);
void write_to_file(std::string file_name, std::map<std::string, std::string>);
