#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int current = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > current){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
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
	insertionSort(arr, n);
	cout << "Insertion Sorted array is: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}
