#include <iostream>
#include <stdlib.h>
using namespace std;

class CircularQueue{
	int rear, front;
	int size;
	int *array;
	
public:
	CircularQueue(){
		rear = -1;
		front = -1;
		cout << "Enter size: ";
		cin >> size;
		array = new int[size];
	}
	void insert(){
		int value;
		cout << "\nEnter value: ";
		cin >> value;
		if((front == 0 && rear == size-1) || (rear == front-1))
			cout << "\nQueue is full.\n";
		else if(front == -1){
			front = 0;
			rear = 0;
			array[rear] = value;
		}
		else if(rear == size-1 && front != 0){
			rear = 0;
			array[rear] = value;
		}
		else{
			rear++;
			array[rear] = value;
		}
	}
	void remove(){
		if(front == -1)
			cout << "\nQueue empty, cannot remove.\n";
		int data = array[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}
		else if(front == size-1)
			front = 0;
		else
			front++;
		cout << "\nElement removed: " << data << "\n";
	}
	void display(){
		if(front == -1)
			cout << "\nQueue is empty.\n";
		cout << "\nCircular Queue: ";
		if(rear >= front){
			for(int i=0; i<=rear; i++)
				cout << array[i] << " ";
		}
		else{
			for(int i=front; i<size; i++)
				cout << array[i] << " ";
			for(int i=0; i<=rear; i++)
				cout << array[i] << " ";
		}
		cout << "\n";
	}
};

int main(){
	CircularQueue cqueue;
	int choice = 0;
	while(choice != 4){
		cout << "\n-------Circular Queue Operations-------";
		cout << "\n1. Insert";
		cout << "\n2. Remove";
		cout << "\n3. Display";
		cout << "\n4. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: cqueue.insert();
					break;
			case 2: cqueue.remove();
					break;
			case 3: cqueue.display();
					break;
			case 4: exit(0);
		}
	}
}