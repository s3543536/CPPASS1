#include <string>
#include <iostream>

using namespace std;

int main() {
	string name1 = "bat";
	string name2 = "fruit";

	name2 += name1; //or name2.append(name1);

	cout << name2 << endl;

	return 0;
}
