#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include "list_wrapper.h"

void display_help(boost::program_options::options_description);
void write_to_file(std::string file_name, std::map<std::string, std::string>);
