#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    Node *head = NULL;
    
public:
    void insert(){
        Node *n;
        int value; 
        n = new Node();
        n->next = NULL;
        cout << "Enter element: ";
        cin >> value;
        n->data = value;
        if(head == NULL)
            head = n;
        else{
            Node *ptr;
            ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
        }
    }
    void display(){
        Node *temp;
        temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void insertBegin(){
	    Node *n;
	    int value;
	    n = new Node();
	    cout << "Enter value: ";
	    cin >> value;
	    n->data=value;
	    if(head==NULL){
		    n->next=NULL;
		    head=n;	
		    cout << "\nValue is inserted in beginning." << endl;
	    }
	    else{
		    n->next=head;
		    head=n;
		    cout << "\nValue is inserted in beginning." << endl;
	    }
        display();
    }
    void insertAtPosition(){
        Node *newnode,*temp,*ptr;
	    int value,position;
	    newnode = new Node();
	    
		cout << "\nEnter value: ";
		cin >> value;
		newnode->data=value;
		cout << "\nEnter position: ";
		cin >> position;
		temp=head;
		for(int i=0;i<position-1;i++){
			ptr=temp;
			if(ptr==NULL){
				cout << "\nValue can't be inserted.";
				return;		
			}	
			temp=temp->next;
		}
		newnode->next=temp;
		ptr->next=newnode;
		cout << "\nValue inserted at: " << position << endl;
        display();
    }
    void insertBeforeKey(){
	    Node *newnode,*temp;;
	    int value,key;
        newnode = new Node();

		cout << "\nEnter value: ";
		cin >> value;
		newnode->data=value;
		cout << "\nEnter Key before which you want to insert: ";
		cin >> key;
		if(head->data==key){
			newnode->next=head;
			head=newnode;
		}
		else{
			temp=head;
			while(temp->next->data!=key)
				temp=temp->next;
			newnode->next=temp->next;
			temp->next=newnode;
		}
		cout << "\nValue is inserted before key value." << endl;
        display();
    }
    void insertLast(){
	    Node *newnode,*temp;
	    int value;
	    newnode = new Node();
	    
		cout << "\nEnter value: ";
		cin >> value;
		newnode->data=value;
		if(head==NULL){
			newnode->next=NULL;
			head=newnode;
			cout<<"\nValue is inserted at last." << endl;
		}
		else{
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			newnode->next=NULL;
			temp->next=newnode;
			cout<<"\nValue is inserted at last." << endl;
		}
        display();
    }
    void deleteBegin(){
	    Node *temp;
	    if(head==NULL){
		    cout << "\nList empty." << endl;
		    return;
	    }
	    else{
		    temp=head;
		    head=temp->next;
		    free(temp);
		    cout << "\nNode deleted from beginning" << endl;
        }
        display();
    }
    void deleteAtPosition(){
	    Node *temp,*ptr;
	    int position;
	    if(head==NULL){
		    cout << "\nList empty." << endl;
		    return;
	    }
	    else{
		    temp=head;
		    cout << "\nEnter position: ";
		    cin >> position;
		
		    for(int i=0;i<position-1;i++){
			    ptr=temp;
			    temp=temp->next;
			    if(ptr==NULL){
				    cout<<"\nCAN'T DELETE." << endl;
				    return;
			    }
		    }
		    ptr->next=temp->next;
		    free(temp);
		    cout<<"\nNode deleted at position " << position << endl;
	    }
        display();
    }
    void deleteAtKey(){
        Node *temp;
	    int key;
	    cout << "\nEnter key: ";
	    cin >> key;
		temp = head;	
		while(temp->next->data!=key)
			temp=temp->next;
		temp->next=temp->next->next;
		cout << "\nNode deleted at key value." << endl;
        display();
	}
    void deleteLast(){
	    Node *temp,*ptr;
	    if(head==NULL){
		    cout << "\nList Empty." << endl;
		    return;
	    }
	    else if(head->next==NULL){
		    head==NULL;
		    free(head);
		    cout << "\nNode deleted." << endl;
		    return;
	    }
	    else{
		    temp=head;
		    while(temp->next!=NULL){
			    ptr=temp;
			    temp=temp->next;
		    }
		    ptr->next=NULL;
		    free(temp);
		    cout << "\nNode deleted from last." << endl;
	    }
        display();
    }
    void search(){
        Node *temp;
	    int value,flag=0;
	    if(head==NULL)
		    cout << "\nList is empty." << endl;
	    else{
		    temp=head;
		    cout << "\nEnter value: ";
		    cin >> value;
		    for(int i=0;temp!=NULL;i++){
			    if(temp->data==value){
				    cout << "\nValue is found at position " << i+1 << endl;
				    flag=0;
				    return;
			    }
			    else
				    flag=1;
			    temp=temp->next;
		    }
		    if(flag==1)
			    cout << "\nValue not found." << endl;
	    }
        display();   
    }
};

int main(){
    int n;
    LinkedList list;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0; i<n; i++)
        list.insert();
    list.display();

    int choice=0;
	while(choice!=11){
		cout << "\n\n------------------MENU-----------------";
		cout << "\n1) INSERT AT BEGIN\n2) INSERT AT SPECIFIED POSITION\n3) INSERT BEFORE KEY VALUE\n4) INSERT AT LAST\n5) DELETE AT BEGIN\n6) DELETE AT SPECIFIED POSITION\n7) DELETE AT KEY VALUE\n8) DELETE AT LAST\n9) SEARCH VALUE IN LINKED LIST\n10) DISPLAY\n11) EXIT\n";
		cout << "ENTER YOUR CHOICE: ";
		cin >> choice;
		switch(choice){
			case 1:
				list.insertBegin();
				break;
			case 2:
				list.insertAtPosition();
				break;
			case 3:
				list.insertBeforeKey();
				break;
			case 4:
				list.insertLast();
				break;
			case 5:
				list.deleteBegin();
				break;
			case 6:
				list.deleteAtPosition();
				break;
			case 7:
				list.deleteAtKey();
				break;
			case 8:
				list.deleteLast();
				break;
			case 9:
				list.search();
				break;
			case 10:
				list.display();
				break;
			case 11:
				exit(1);
				break;
			default:
				cout<<"\nEnter valid choice.";
				break;
		}
	}
}