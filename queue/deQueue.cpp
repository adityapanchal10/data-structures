#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class DeQueue{
	Node *head = NULL;
	int front = -1;
	int rear = -1;
	
public:
	void insertEnd(){
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
	void insertFront(){
	    Node *n = new Node();
	    cout << "\nEnter value: ";
	    cin >> n->data;
	    n->next = NULL;
	    if(front == -1 && rear == -1){
		    head = n;	
		    front++;
		    rear++;
	    }
	    else{
		    n->next = head;
		    head = n;
		    rear++;
	    }
    }
	void removeFront(){
		if(rear == -1)
			cout << "\nQueue is empty, cannot delete.\n";
		else if(front == rear){
			int x = head->data;
			front = -1;
			rear = -1;
			head = NULL;
			cout << "\nValue removed: " << x << "\n";
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
	void removeEnd(){
		if(front == rear){
			front = -1;
			rear = -1;
			head = NULL;	
		}
		else if(rear == -1)
			cout << "\nQueue is empty, cannot delete.\n";
		else{
			Node *temp = head;
			Node *ptr;
			while(temp->next != NULL){
				ptr = temp;
				temp = temp->next;
			}
			int x = temp->data;
			ptr->next=NULL;
		    free(temp);
		    cout << "\nValue removed: " << x << "\n";
		    rear--;
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
	int choice1 = 0;
	int choice2 = 0;
			
	while(choice1 != 3){
		DeQueue dqueue;
		cout << "\n-------- Select DeQueue -------";
		cout << "\n1. Insertion fixed, Deletion at both ends.";
		cout << "\n2. Deletion fixed, Insertion at both ends.";
		cout << "\n3. Exit.";
		cout << "\nEnter your choice: ";
		cin >> choice1;
		choice2 = 0;
		if(choice1 == 1){
			int ch;
			cout << "\nChoose Insertion.";
			cout << "\n1. Insertion at front.";
			cout << "\n2. Insertion at end.";
			cout << "\nEnter your choice: ";
			cin >> ch;
			while(choice2 != 5){	
				cout << "\n-------- DeQueue Operations -------";
				cout << "\n1. Insert.";
				cout << "\n2. Delete at End.";
				cout << "\n3. Delete at Front.";
				cout << "\n4. Display.";
				cout << "\n5. Exit to previous menu.";
				cout << "\nEnter your choice: ";
				cin >> choice2;
				switch(choice2){
					case 1: if(ch == 1)
								dqueue.insertFront();
							else
								dqueue.insertEnd();	
							break;
					case 2: dqueue.removeEnd();
							break;
					case 3: dqueue.removeFront();
							break;
					case 4: dqueue.display();
							break;
					case 5: break;
				}
			}
		}
		else if(choice1 == 2){
			int ch;
			cout << "\nChoose Deletion.";
			cout << "\n1. Deletion at front.";
			cout << "\n2. Deletion at end.";
			cout << "\nEnter your choice: ";
			cin >> ch;
			while(choice2 != 5){	
				cout << "\n-------- DeQueue Operations -------";
				cout << "\n1. Insert at Front.";
				cout << "\n2. Insert at End.";
				cout << "\n3. Delete.";
				cout << "\n4. Display.";
				cout << "\n5. Exit to previous menu.";
				cout << "\nEnter your choice: ";
				cin >> choice2;
				switch(choice2){
					case 1: dqueue.insertFront();
							break;
					case 2: dqueue.insertEnd();
							break;
					case 3: if(ch == 1)
								dqueue.removeFront();
							else
								dqueue.removeEnd();	
							break;
					case 4: dqueue.display();
							break;
					case 5: break;
							
				}
			}
		}
		else if(choice1 == 3)
			exit(0);
	}
}
