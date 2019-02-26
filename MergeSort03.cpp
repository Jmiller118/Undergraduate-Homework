//Jordan Miller
//CSCI 4270

#include <iostream>

using namespace std;

int modifiedMerge(int arr[], int first, int last) {
	int mid = (first + last) / 2;
	int i = first;
	int j = mid + 1;
	int k = 0;
	
	int* list;
	
	list = new int[last - first + 1];
	int num;
	int inversion = 0;
	
	while (i <= mid && j <= last) {
		if (arr[i] <= arr[j]) {
			list[num++] = arr[i++];
		} else {
			list[num++] = arr[j++];
		}
	}
	
	while (i <= mid) {
		list[num++] = arr[i++];
	}
	
	while (j <= last) {
		list[num++] = arr[j]++;
	}
	
	for (i = 0; i < last - first + 1; i++) {
		arr[i+first] = list[i];
	}
	return inversion;
}

int count(int arr[], int x, int y) {
	int a, b, c, mid;
	if (x >= y) 
		return 0;
	
	mid = (x + y) / 2;
	
	a = count(arr, x, mid);
	b = count(arr, mid + 1, y);
	c = count(arr, x, y);
	
	return a + b + c;
}

int main() {
	int arr[] = {12, 11, 14, 5 ,6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int inversion = count(arr, 0, arr_size -1);
	
	cout << "orginal is " << endl;
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << endl;
	}
	
	return 0;

}