#include <iostream>
#include <stdlib.h>
using namespace std;

int height;

struct node{
	int data;
	struct node *left;
	struct node *right;
};
	
struct node* create(){
	int data;	
	cout << "Enter data(-1 for NULL): ";
	cin >> data;
	if(data == -1)
		return NULL;
	else{
		node *bnode = new node();
		bnode->data = data;
		height++;
		cout << "\nFor left child of " << bnode->data << ": " << endl;
		bnode->left = create();
		cout << "\nFor right child of " << bnode->data << ": " << endl;
		bnode->right = create();
		return bnode;
	}
}

int Height(struct node *node){
	if(node == NULL)
		return 0;
	else{
		int l=0, r=0;
		l = Height(node->left);
		r = Height(node->right);
		if(l>r)
			return l+1;
		else
			return r+1;
	}
}

void print(struct node* root, int i){
		if(root == NULL)
			return;
		if(i == 0)
			cout << root->data << " ";
		else if(i > 0){
			print(root->left, i-1);
			print(root->right, i-1);
		}
	}

void display(struct node* root){
	cout << "\nHeight: " << height-1 << endl;
	if(root != NULL){
		int space = height;
		for(int i=0; i<=height; i++){
			for(int j=0; j<space-1; j++)
				cout << " ";
			print(root, i);
			cout << "\n";
			space--;
		}
	}
}

void preorder(struct node* root){	
	if(root != NULL){
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postorder(struct node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

int main(){
	node *root = NULL;
	int choice = -1;
	while(choice != 6){
		cout << "\n\nBinary Tree Operations." << endl;
		cout << "1. Create" << endl;
		cout << "2. Display tree" << endl;
		cout << "3. Preorder traversal" << endl;
		cout << "4. Inorder traversal" << endl;
		cout << "5. Postorder traversal" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: root = create();
					break;
			case 2: height = Height(root);
					display(root);
					break;
			case 3: cout << "\nPreorder: ";
					preorder(root);
					break;
			case 4: cout << "\nInorder: ";
					inorder(root);
					break;
			case 5: cout << "\nPostorder: ";
					postorder(root);
					break;
			case 6: exit(0);
		}
	}
}	

