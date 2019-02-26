#include<iostream>

int merge(int arr[], int temp[], int left, int mid, int right) {
	int i = left;
	int j = mid;
	int k = left;
	int inversionCount = 0;
	while((i <= mid-1) &&(j <= right)) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inversionCount = inversionCount + (mid-i);
		}
	}
	while(i <= mid-1) {
		temp[k++] = arr[i++];
	}
	while(j <= right) {
		temp[k++] = arr[j++];
	}
	for(i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
	return inversionCount;
}

int mergeSortRec(int arr[], int temp[], int left, int right) {
	int mid = 0;
	int inversionCount = 0;
	if(right > left) {
		mid = (right + left) / 2;
		
		inversionCount = mergeSortRec(arr, temp, left, mid);
		inversionCount += mergeSortRec(arr, temp, mid+1, right);
		inversionCount += merge(arr, temp, left, mid+1, right);
	}
	return inversionCount;
}

int mergeSort(int arr[], int arrSize) {
	int *temp = new int[arrSize];
	return mergeSortRec(arr, temp, 0, arrSize-1);
}

int main() {
	int arr[] = {5, 4, 3, 2, 1};
	std::cout << "Number of inversions: " << mergeSort(arr, 5) << "\n";
	return 0;
}