#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <string>
#include <list>
#include <iostream>
#include <fstream>

void load_file_test(std::string);
void write_file_test(std::string, std::string);
void display_help(boost::program_options::options_description);
std::list<std::string> load_dict(std::string);
