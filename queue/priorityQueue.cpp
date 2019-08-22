#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	int priority;
	Node *next;
};

class PriorityQueue{
	Node *head = NULL;
	int front = -1;
	int rear = -1;
	
public:
	void insert(){
		Node *n = new Node();
		cout << "\nEnter value: ";
		cin >> n->data;
		cout << "Enter priority: ";
		cin >> n->priority;
		n->next = NULL;
		if(front == -1 && rear == -1){
			head = n;
			rear++;
			front++;
		}
		else if(head->priority > n->priority){
			Node *temp = head;
			n->next = head;
			head = n;
		}	
		else{
			Node *temp = head;
			while(temp->next != NULL && temp->next->priority <= n->priority)
				temp = temp->next;
			n->next = temp->next;
			temp->next = n;
			rear++;
		}
	}
	void remove(){
		if(rear == -1)
			cout << "\nQueue is empty, cannot remove.\n";
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
			cout << "\nHigh priority element " << x << " removed.\n";
		}
	}
	void display(){
		if(rear == -1)
			cout << "\nQueue is empty.\n";
		else{
			Node *temp;
			temp = head;
			cout << "\nPriority Queue:";
			while(temp != NULL){
				cout << " " << temp->data;
				temp = temp->next;
			}
			cout << "\n";
		}
	}
};

int main(){
	PriorityQueue pqueue;
	int choice = 0;
			
	while(choice != 4){
		cout << "\n-------- Priority Queue Operations -------";
		cout << "\n1. Insert.";
		cout << "\n2. Remove.";
		cout << "\n3. Display.";
		cout << "\n4. Exit.";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: pqueue.insert();
					break;
			case 2: pqueue.remove();
					break;
			case 3: pqueue.display();
					break;
			case 4: exit(0);
		}
	}
}