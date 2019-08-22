#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class Stack{
	Node *head = NULL;
	int top = -1;
	
public:
	void push(){
		Node *n = new Node();
		n->next = NULL;
		cout << "\nEnter value: ";
		cin >> n->data;
		if(top == -1){
			head = n;
			top++;
		}
		else{
			n->next = head;
			head = n;
			top++;
		}
	}
	void pop(){
		if(top == -1)
			cout << "Stack is empty, cannot pop.\n";
		else{
			int x = head->data;
			Node *temp = head;
			head = temp->next;
			free(temp);
			top--;
			cout << "\nValue popped: " << x << "\n";
		}
	}
	void display(){
		if(top == -1)
			cout << "Stack is empty.\n";
		else{
			Node *temp;
			temp = head;
			cout << "\nStack:";
			while(temp != NULL){
				cout << " " << temp->data;
				temp = temp->next;
			}
			cout << "\n";
		}
	}
};


int main(){
	Stack stack;
	int choice = 0;
	
	while(choice != 4){
		cout << "\n-------- Stack Operations -------";
		cout << "\n1. Push.";
		cout << "\n2. Pop.";
		cout << "\n3. Display.";
		cout << "\n4. Exit.";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: stack.push();
					break;
			case 2: stack.pop();
					break;
			case 3: stack.display();
					break;
			case 4: exit(1);
		}
	}
}