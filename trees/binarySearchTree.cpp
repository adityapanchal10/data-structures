#include <iostream>
#include <stdlib.h>
using namespace std;

int height;

struct node{
	int data;
	struct node *left;
	struct node *right;
};
	
node* insert(struct node* root, struct node* bnode){
	if(root == NULL){	
		root = bnode;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	if(bnode->data < root->data){
		root->left = insert(root->left, bnode);
	}		
	else{
		root->right = insert(root->right, bnode);
	}
	return root;
}

void deleteNode(struct node* root, int k){
	struct node *p, *follow, *t, *f ;
    p = root ;
    follow = NULL ;
    while(p != NULL){
        if(p->data == k)
            break;
        follow = p;
        if(k < p->data)
            p = p->left;
        else
            p = p->right;
    }
    if(p == NULL)
        cout << "Required node not found. \n";
    else{
        /* Actual Deletion */
        /* Deleting a leaf node or a node with empty left subtree */
        if(p->left == NULL)
            if(p != root)
                if(follow->left == p)
                    follow->left = p->right;
                else
                    follow->right = p->right;
            else
                root = p->right;
        /* Deleting node with empty right subtree */
        else if(p->right == NULL)
            if(p != root)
                if(follow->left == p)
                    follow->left = p->left;
                else
                    follow->right = p->left;
            else
                root = p->left;
        /* Deleting a node with non-empty left and right subtrees */
        else{
            /* finding the inorder successor of p, that is, finding the smallest node in right sub tree of node to be deleted */
            t = p->right ;
            f = p ;
            while(t->left != NULL){
                f = t ;
                t = t->left ;
            }
            /* At this stage t is the inorder successor of p and f is the father of t */
            /* put t's data in place of p */
            p->data = t->data;
            if(f != p)
                f->left = t->right;
            else
                f->right = t->right;
            p = t; /* Useful for free(p) */
        }
        free(p) ;
	}
}

int Height(struct node *node){
	if(node == NULL)
		return 0;
	else{
		int l = 0, r = 0;
		l = Height(node->left);
		r = Height(node->right);
		if(l > r)
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
	node *bnode;
	int choice = -1;
	while(choice != 7){
		cout << "\n\nBinary Search Tree Operations." << endl;
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Display tree" << endl;
		cout << "4. Preorder traversal" << endl;
		cout << "5. Inorder traversal" << endl;
		cout << "6. Postorder traversal" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: bnode = new node;
					cout << "Enter value: ";
					cin >> bnode->data;
					root = insert(root, bnode);
					break;
			case 2: int x;
					cout << "Enter value to be deleted: ";
					cin >> x;			
					deleteNode(root, x);
					break;
			case 3: height = Height(root);
					display(root);
					break;
			case 4: cout << "\nPreorder: ";
					preorder(root);
					break;
			case 5: cout << "\nInorder: ";
					inorder(root);
					break;
			case 6: cout << "\nPostorder: ";
					postorder(root);
					break;
			case 7: exit(0);
		}
	}
}	

