//Jordan Miller
//CSCI 4270
//Assignment 09, Radix Sort

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void RadixSort(vector<int> &v, int base, int n) {
	int div = 1;
	
	bool keepLooping = true;
	
	vector<int> buffer(n);
	
	while (keepLooping == true) {
		vector<int> count(base);
		for (int i = 0; i < base; i++) {
			count[i] = 0;
		}
		
		for (int i = 0; i <= n-1; i++) {
			count[int(floor(v[i] / div)) % base]++;
		}
		
		if (count[0] == n) {
			keepLooping = false;
		}
	
		for (int j = 1; j <= base - 1 ; j++) {
			count[j] = count[j] + count[j-1];
		}
		
		for (int i = n-1; i >= 0; i--) {
			buffer[--count[int(floor(v[i] / div )) % base]] = v[i];
			//count[floor((v[i] / div)) % base]--;
		}

		for (int i = 0; i <= n-1; i++) {
			v[i] = buffer[i];
		}
		
		div = div * base;
	}
}

int main() {
	vector<int> list;
	int n, num;
	
	cout << "Weclome to Radix Sort" << endl;
	cout << "Enter intergers to sort: " << endl;
	while (cin >> num) {
		list.push_back(num);	
	}
	
	n = list.size();
	
	RadixSort(list, 10, n);
	
	cout << "The sorted list is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << list[i] << endl;
	}
	
	return 0;
}