//Jordan Miller
//CSCI 4270
//Greedy Nnapsack

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Item {
	int value;
	int weight;
	int valueWeight;
};

bool valueFirst(Item v1, Item v2) {
	return v1.value > v2.value;
}

bool weightFirst(Item w1, Item w2) {
	return w1.weight < w2.weight;
}

bool valueToWeight(Item i1, Item i2) {
	return i1.valueWeight > i2.valueWeight;
}

std::ostream& operator <<(std::ostream& os, const Item& i) {
	os << "Weight is: " << i.weight << "Value is: " << i.value
		<< "\nRatio is : " << i.valueWeight << endl;
	return os;
}

int main() {
	cout << "This is the Greey Knapsack" << endl;
	cout << "Copy and past the file, then hit enter followed by control Z" << endl;
	
	Item item;
	vector<Item> list;
	int objectValue, objectWeight, count;
	char comma;
	double bagWeight, bagValue;
	const int maxWeight = 10000;
	
	while (cin >> objectWeight >> comma >> objectValue) {
		item.weight = objectWeight;
		item.value = objectValue;
		item.valueWeight = (double(item.value) / double(item.weight));
		list.push_back(item);	
	}
	
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "Sorting by Value" << endl;
	cout << endl;
	
	bagWeight = bagValue = count = 0;
	sort(list.begin(), list.end(), valueFirst);
	for (int i = 0; i < list.size(); i++) {
		if ((bagWeight + list[i].weight) <= maxWeight) {
			bagWeight += list[i].weight;
			bagValue += list[i].value;
			count += 1;
		}
	}
	cout << "There are " << count << " items in the bag" << endl;
	cout << "Value is " << bagValue << ", Weight is " << bagWeight << endl;

	cout << endl;
	cout << "----------------------------" << endl;
	cout << "Sorting by Weight" << endl;
	cout << endl;
	
	bagWeight = bagValue = count = 0;
	sort(list.begin(), list.end(), weightFirst);
	for (int i = 0; i < list.size(); i++){
		if ((bagWeight + list[i].weight) <= maxWeight) {
			bagWeight += list[i].weight;
			bagValue += list[i].value;
			count += 1;
		}
	}
	cout << "There are " << count << " items in the bag" << endl;
	cout << "Value is " << bagValue << ", Weight is " << bagWeight << endl;
	
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "Sorting by Ratio" << endl;
	cout << endl;
	
	bagWeight = bagValue = count = 0;
	sort(list.begin(), list.end(), valueToWeight);
	for (int i = 0; i < list.size(); i++) {
		if ((bagWeight + list[i].weight) <= maxWeight) {
			bagWeight += list[i].weight;
			bagValue += list[i].value;
			count += 1;
		} 
	}
	cout << "There are " << count << " items in the bag" << endl;
	cout << "Value is " << bagValue << ", Weight is " << bagWeight << endl;
	cout << endl;
	
	system("pause");	
}