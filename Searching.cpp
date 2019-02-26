//Jordan Miller
//CSCI 4270
//Searching Algorithms

//instead of returning found or not found, return the number of comparisions
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

//Sequental search
int linearSearch(vector<int> &vec, int value) {
	int comparisons = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == value) {
			comparisons++;
			break;
		}
		comparisons++;
	}
	return comparisons;
}

//binary search
int binarySearch(vector<int> &vec, int x) {
	int h = vec.size() - 1;
	int l = 0;
	int comparisions = 0;
	int mid = l + (h - l) / 2;
	
	while (l <= h) {
		if (vec[mid] == x) {
			comparisions++;
			break;
		}
		else if (vec[mid] > x) {
			comparisions++;
			h = mid - 1;
		} else {
			l = mid + 1;
			comparisions++;
		}
		mid = l + (h - l) / 2;
	}
	return comparisions;
}

//interpolation search
int interpolationSearch(vector<int> &vec, int x) {
	int low = 0;
	int i = 0;
	int high = vec.size() - 1;
	int mid;
	double denominator;
	int comparisons = 0;
	
	if (vec[low] <= x  && x <= vec[high]) {
		while (low <= high) { 
			denominator = vec[high] - vec[low];
			if (denominator == 0) {
				mid = low;
			} else {
				mid = low + ((x - vec[low]) / denominator ) * (high - low);
			} 
			comparisons++;
			if ( x == vec[mid]) {
				break;
			} else if (x < vec[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
	}
	return comparisons;
}

//robust search
int robustSearch(vector<int> &vec, int x) {
	int low = 0;
	int l = 0;
	int high = vec.size() - 1;
	int mid;
	double denominator;
	int comparisons = 0;
	int gap;
	
	
	if (vec[low] <= x && x <= vec[high]) {
		while (low <= high) {
			denominator = vec[high] - vec[low];
			gap = sqrt(high - low );
			if (denominator == 0) {
				mid = low;
			} else {
				mid = low + ((x - vec[low]) / denominator ) * (high - low);
				mid = min(high - gap, max(mid, low + gap));
			} 
			comparisons++;
			if ( x == vec[mid]) {
				break;
			} else if (x < vec[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			} 
		}
	}	
	return comparisons;
}

int main() {
	int number, size;
	vector<int> list;
	
	cout << "Welcome to the Searching Algorithm!" << endl;
	cout << "Enter the numbers to be searched . . ." << endl;
	while (cin >> number) {
		list.push_back(number);
	}
	
	size = list.size();
	
	//seq serach
	double average = 0;
	for (int i = 0; i < size; i++) {
		average += linearSearch(list, list[i]);
	}
	average = average / size;
	cout << "Average for Sequental Search is: " << average << endl;
	
	//bin search
	average = 0;
	for (int i = 0; i < size; i++) {
		average += binarySearch(list, list[i]);
	}
	average = average / size;
	cout << "Average for Binary Search is: " << average << endl;
	
	//interp search
	average = 0;
	for (int i = 0; i < size; i++) {
		average += interpolationSearch(list, list[i]);
	}
	average = average / size;
	cout << "Average for Interpolation Search is: " << average << endl;
	
	//robust search
	average = 0;
	for (int i = 0; i < size; i++) {
		average += robustSearch(list, list[i]);
	}
	average = average / size;
	cout << "Average for Robust Search is: " << average << endl;
}