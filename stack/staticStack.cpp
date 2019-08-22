#include <iostream>
#include <stdlib.h>
using namespace std;

struct Stack{
	int top;
	int size;
	int *array;
};

struct Stack *createStack(int n){
	struct Stack *stack = new Stack();
	stack->top = -1;
	stack->size = n;
	stack->array = new int[n];
	return stack;
}
int isEmpty(struct Stack *stack){
	return stack->top == -1;
}
int peek(struct Stack *stack){
	return stack->array[stack->top];
}
void pop(struct Stack *stack){
	int op;
	if(!isEmpty(stack)){
		op = stack->array[stack->top--];
		cout << "Value popped: " << op;
	}
	else
		cout << "Stack empty, cannot pop";
}
void push(struct Stack* stack){
	if(stack->top == stack->size-1)
		cout << "Stack is full.";
	else{
		int ip;
		cout << "Enter value: ";
		cin >> ip;
		stack->array[++stack->top] = ip;
	}
}
void display(struct Stack *stack){
	int temp = stack->top;
	cout << "Stack: "
	while(!isEmpty(stack))
		cout << stack->array[stack->top--] << " ";
	stack->top = temp;
}

int main(){
	int size;
	int choice = 0;
	cout << "Enter size of stack: ";
	cin >> size;
	Stack *stack = createStack(size);
	while(choice != 4){
		cout << "\n-------Stack Operations-------";
		cout << "\n1. Push";
		cout << "\n2. Pop";
		cout << "\n3. Display";
		cout << "\n4. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: push(stack);
					break;
					
			case 2: pop(stack);
					break;
					
			case 3: display(stack);
					break;
					
			case 4: exit(1);
		}
	}
}