#include <iostream>
using namespace std;

int partition(int array[], int left, int right, int pivot);

void quickSort(int array[], int left, int right){
	if(left >= right)
		return;
	int pivot = array[(left+right)/2];
	int index = partition(array, left, right, pivot);
	quickSort(array, left, index-1);
	quickSort(array, index, right);
}

int partition(int array[], int left, int right, int pivot){
	while(left <= right){
		while(array[left] < pivot)
			left++;
		while(array[right] > pivot)
			right--;
		if(left <= right){
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}
	return left;
}

int main(){
	int n;
	int *arr;
	cout << "Enter number of elements: ";
	cin >> n;
	arr = new int[n];
	cout << "Enter elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];
	quickSort(arr, 0, n-1);
	cout << "Quick Sorted array is: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}
