#include "edit_distance.h"

int edit_distance::calculate(std::string s1, std::string s2) {
		//(row * columns) + column
		std::vector<int> matrix;
		int c = s2.length();//columns
		unsigned int i, j;

		//std::cout << "'" << s1 << "' " << s1.length() << s1.length() << "\n";
		matrix.resize(s1.length() * s2.length());

		for(i = 0; i < s1.length(); i++) {
			matrix[(i * c)+0] = i;
		}

		for(j = 0; j < s1.length(); j++) {
			matrix[(0 * c)+j] = j;
		}

		for(i = 1; i < s1.length(); i++) {
			for(j = 1; j < s2.length(); j++) {
				//std::cout << i << "," << j << "\t\n";
				matrix[(i*c)+j] = std::min(
						matrix[((i-1)*c)+(j-1)] + !(s1[i] == s2[j]),
						std::min(
							matrix[((i-1)*c)+j]+1,
							matrix[(i*c)+(j-1)]+1));
			}
		}

		if(false) {
			std::cout << s1 << "\t" << s2 << "\n";
	
			std::cout << "\t0 1 2 3 4 5 6 7 8 9 0\n";
			std::cout << "\t";
			for(i = 0; i < s2.length(); i++) {
				std::cout << s2[i] << " ";
			}
			for(i = 0; i < s1.length(); i++) {
				std::cout << "\n";
				std::cout << i << " " << s1[i];
				std::cout << "\t";
				for(j = 0; j < s2.length(); j++) {
					if(i == 0) {
					}
					std::cout << matrix[(i*c)+j] << " ";
				}
			}
		}
		return matrix[((s1.length()-1)*c)+(s2.length()-1)];
}
