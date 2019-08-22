#include <iostream> 
#include <stack>
using namespace std; 

bool isOperand(char x){ 
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'); 
} 

int postfixToPrefix(string input){ 
	stack<string> stack; 
	string output;
	
	for (int i=0; i < input.length(); i++){ 
		if(isOperand(input[i])){ 
			string op(1, input[i]); 
			stack.push(op); 
		} 
		else{ 
			string op1 = stack.top(); 
			stack.pop(); 
			string op2 = stack.top(); 
			stack.pop(); 
			stack.push(input[i] + op2 + op1); 
		} 
	}
	output = stack.top(); 
	cout << "Prefix: " << output << endl;
} 

int main(){ 
	string input;
	cout << "Enter postfix expression: ";
	cin >> input;
	postfixToPrefix(input); 
}