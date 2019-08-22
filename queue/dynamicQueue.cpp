#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
	Node *head = NULL;
	int front = -1;
	int rear = -1;
	
public:
	void insert(){
		Node *n = new Node();
		cout << "\nEnter value: ";
		cin >> n->data;
		n->next = NULL;
		if(front == -1 && rear == -1){
			head = n;
			rear++;
			front++;
		}	
		else{
			Node *temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = n;
			rear++;
			}
	}
	void remove(){
		if(rear == -1)
			cout << "\nQueue is empty, cannot delete.\n";
		else if(front == rear){
			front = -1;
			rear = -1;
			head = NULL;
		}
		else{
			int x = head->data;
			Node *temp = head;
			head = temp->next;
			free(temp);
			front++;
			cout << "\nValue removed: " << x << "\n";
		}
	}
	void display(){
		if(rear == -1)
			cout << "\nQueue is empty.\n";
		else{
			Node *temp;
			temp = head;
			cout << "\nQueue:";
			while(temp != NULL){
				cout << " " << temp->data;
				temp = temp->next;
			}
			cout << "\n";
		}
	}
};

int main(){
	Queue queue;
	int choice = 0;
			
	while(choice != 4){
		cout << "\n-------- Queue Operations -------";
		cout << "\n1. Insert.";
		cout << "\n2. Remove.";
		cout << "\n3. Display.";
		cout << "\n4. Exit.";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: queue.insert();
					break;
			case 2: queue.remove();
					break;
			case 3: queue.display();
					break;
			case 4: exit(0);
		}
	}
}