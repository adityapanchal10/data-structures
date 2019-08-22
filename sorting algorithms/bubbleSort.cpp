#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}	
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
	bubbleSort(arr, size);
	cout << "Bubble Sorted array is: ";
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
