#include <iostream> 
#include <stack>
using namespace std; 

bool isOperand(char x){ 
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'); 
} 

int prefixToInfix(string input){ 
	stack<string> stack; 
	string output;
	
	for (int i=input.length()-1; i >= 0; i--){ 
		if(isOperand(input[i])){ 
			string op(1, input[i]); 
			stack.push(op); 
		} 
		else{ 
			string op1 = stack.top(); 
			stack.pop(); 
			string op2 = stack.top(); 
			stack.pop(); 
			stack.push('(' + op1 + input[i] + op2 + ')'); 
		} 
	}
	output = stack.top(); 
	cout << "Infix: " << output << endl;
} 

int main(){ 
	string input;
	cout << "Enter prefix expression: ";
	cin >> input;
	prefixToInfix(input); 
}