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
        cout << endl;
    }
    void sort(){
    	Node *temp1, *temp2;
    	int temp;
    	temp1 = head;
    	while(temp1 != NULL){
    		temp2 = temp1->next;
    		while(temp2 != NULL){
    			if(temp2->data < temp1->data){
    				temp = temp2->data;
    				temp2->data = temp1->data;
    				temp1->data = temp;
    			}
    			temp2 = temp2->next;
    		}
    		temp1 = temp1->next;
    	}
    }
};

int main(){
    int n;
    LinkedList list;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0; i<n; i++)
        list.insert();
    cout << "\n\nLinked list is: ";
    list.display();
    list.sort();
    cout << "\nSorted list is: ";
    list.display();
}