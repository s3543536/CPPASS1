#include <iostream>
#include <vector>

// means you can type:
// cout
// instead of:
// std::cout
using namespace std;

int main(int argc, char **argv) {
	int num;
	int sum = 0;
	vector<int> int_input;

	cout << "type some numbers:\n";
	while(cin >> num) {
		int_input.push_back(num);
	}

	for(int i = 0; i < (int)int_input.size(); i++) {
		sum += int_input[i];
	}

	cout << "\ntheir sum is: " << sum << endl;
	return 0;
}
