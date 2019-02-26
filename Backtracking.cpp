//Jordan Miller
//CSCI 4270
//Assignment 07, Candy Prizes

#include <iostream>
#include <vector>

using namespace std;

bool isPromising(int given, int total) {
	if (total - given > given) {
		return true;
	}	
	return false;
}

void passCandy(vector <int> &vec, int given, int total) {
	if (isPromising(given + 1, total)) {
		vec.push_back(given + 1);
		passCandy(vec, given + 1, total - (given + 1));
	} else {
		vec.push_back(total);
	}
}

int main() {
	int amount;
	cout << "How much candy do you have?" << endl;
	cin >> amount;
	
	vector<int> candy;
	passCandy(candy, 0, amount);
	
	for (auto i = candy.rbegin(); i != candy.rend(); i++ ) {
		cout << "The children get:  " << *i << " pieces of candy" << endl;
	}
	
	
	return 0;
	system("pause");
}