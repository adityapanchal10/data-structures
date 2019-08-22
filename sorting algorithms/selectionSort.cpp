#include <iostream>
using namespace std;

void selectionSort(int *a, int n){
	int min;
	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(a[j] < a[min])
				min = j;	
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int main(){
	int size;
	int *arr;
	cout << "Enter size of array: ";
	cin >> size;
	arr = new int[size];
	cout << "Enter array elements: ";
	for(int i=0; i<size; i++)
		cin >> arr[i];
	selectionSort(arr, size);
	cout << "Selection Sorted array is: ";
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
