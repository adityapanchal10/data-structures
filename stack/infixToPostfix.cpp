#include<iostream>
#include<string.h>
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

char peek(struct Stack *stack){
	return stack->array[stack->top];
}

char pop(struct Stack *stack){
	if(!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, char ip){
	stack->array[++stack->top] = ip;
}

int isOperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Precedence(char ch){
	if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
	else if(ch == '^')
		return 3;
	else
		return -1;
}

int infixToPostfix(string input){
	int i;
	int k = -1;
	string output;
	
	Stack *stack = createStack(input.length());
	for(i=0; i < input.length(); i++){
		if(isOperand(input[i]))
			output += input[i];
		else if(input[i] == '(')
			push(stack, input[i]);
		else if(input[i] == ')'){
			while(!isEmpty(stack) && peek(stack) != '(')
				output += pop(stack);
			if(peek(stack) == '(')
				pop(stack);
		}
		else{
			while(!isEmpty(stack) && Precedence(input[i]) <= Precedence(peek(stack)))
				output += pop(stack);
			push(stack, input[i]);
		}
	}
	while(!isEmpty(stack))
		output += pop(stack);
	cout << "Postfix: ";
	cout << output << endl;
}

int main(){
	string input;
	cout << "Enter infix expression: ";
	cin >> input;
	infixToPostfix(input);
}