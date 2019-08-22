#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue{
	int front, rear;
	int size;
	int *array;
};

struct Queue *createQueue(int n){
	struct Queue *queue = new Queue();
	queue->front = -1;
	queue->rear = -1;
	queue->size = n;
	queue->array = new int[n];
	return queue;
}
int isEmpty(struct Queue *queue){
	return queue->rear == -1 && queue->front == -1;
}
void remove(struct Queue *queue){
	int op;
	if(queue->front == queue->rear){
		queue->front = -1;
		queue->rear = -1;
	}
	else if(!isEmpty(queue) && queue->front != queue->rear){
		op = queue->array[queue->front++];
		cout << "Value removed: " << op;
	}
	else
		cout << "Queue empty, cannot pop";
}
void insert(struct Queue* queue){
	if(queue->rear == queue->size-1)
		cout << "Queue is full.";
	else if(queue->front == -1 && queue->rear == -1){
		int ip;
		cout << "Enter value: ";
		cin >> ip;
		queue->array[++queue->rear] = ip;
		queue->front++;	
	}
	else{
		int ip;
		cout << "Enter value: ";
		cin >> ip;
		queue->array[++queue->rear] = ip;
	}
}
void display(struct Queue *queue){
	int temp = queue->front;
	cout << "Queue: ";
	while(queue->front != queue->rear+1)
		cout << queue->array[queue->front++] << " ";
	queue->front = temp;
}

int main(){
	int size;
	int choice = 0;
	cout << "Enter size of queue: ";
	cin >> size;
	Queue *queue = createQueue(size);
	while(choice != 4){
		cout << "\n-------Queue Operations-------";
		cout << "\n1. Insert";
		cout << "\n2. Remove";
		cout << "\n3. Display";
		cout << "\n4. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: insert(queue);
					break;
					
			case 2: remove(queue);
					break;
					
			case 3: display(queue);
					break;
					
			case 4: exit(1);
		}
	}
}