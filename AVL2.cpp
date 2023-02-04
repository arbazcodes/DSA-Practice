#include<iostream>
using namespace std;

class AVL{
	
	private: 
		
		struct Node{
			
			int data;
			Node *right, *left;
			int node_height;
		};
	
		Node *root;
		
		
		
		void DisplayInorder(Node *temp){
			
			if(temp == NULL)
				return;
				
			DisplayInorder(temp->left);
			cout<<temp->data<<" ";
			DisplayInorder(temp->right);
			
			
		}
		
		int max(int a, int b){
			
			if(a>b)
				return a;
			else
				return b;
			
		}
		
		int height(Node *r){
			
			if(r == NULL)
				return 0;
			else
				return r->node_height;
			
		}
		
		int BF(Node *r){
			
			if(r == NULL){
				
				return 0;
				
			}else{
				
				return (height(r->left) - height(r->right));
				
			}
			
		}
		
		Node *leftRotate(Node *y){
			
			Node *x = y->right;
			Node *T2 = x->left;
			
			x->left = y;
			y->right = T2;
			
			x->node_height = max(height(x->left), height(x->right)) + 1;
 			y->node_height = max(height(y->left), height(y->right)) + 1;
			
			return x;
			
		}
		
		Node *rightRotate(Node *x){
			
			Node *y = x->left;
			Node *T2 = y->right;
			
			y->right = x;
			x->left = T2;
			
			x->node_height = max(height(x->left), height(x->right)) + 1;
 			y->node_height = max(height(y->left), height(y->right)) + 1;
			
			return y;
		}
		
		Node *deleteNode(Node *r, int num){
			
			if(num < r->data){
				
				r->left = deleteNode(r->left, num);
			}else if(num > r->data){
				
				r->right = deleteNode(r->right, num);
				
			}else{
				
				Node *temp;
				
				if(r == NULL){
					
					cout<<"Can't delete empty node;";
					return r;
					
				}else if(r->left == NULL){
					
					temp = r;
					r = r->right;
					delete temp;
					
					
				}else if(r->right == NULL){
					
					temp = r;
					r = r->left;
					delete temp;
					
					
				}else{
					
					temp = r->right;
					
					while(temp->left){
						
						temp = temp->left;
						
					}
					
					temp->left = r->left;
					temp = r;
					r = r->right;
					delete temp;	
				}
				
				int bf = BF(r);
				
			if(bf > 1 && r->data > r->left->data){
				
				return rightRotate(r);
				
			}else if(bf < -1 && r->data < r->right->data){
				
				return leftRotate(r);
				
			}else if(bf > 1 && r->data < r->left->data){
				
				r->left = leftRotate(r->left);
				return rightRotate(r);
				
			}else if(bf <-1 && r->data > r->right->data){
				
				r->right = rightRotate(r->right);
				return leftRotate(r);
				
			}
			
			return r;
				
			}
	
		}
		
		Node *insert(Node *r, Node *newNode){
			
			if(r == NULL){
				
				r = newNode;
				return r;
				
			}else if(newNode->data < r->data){
				
				r->left = insert(r->left, newNode);
				
			}else if(newNode->data > r->data){
				
				r->right = insert(r->right, newNode);
				
			}else{
				
				cout<<"Duplicate not allowed."<<endl;
				return r;
			}
			
			int bf = BF(r);
			
			if(bf > 1 && newNode->data < r->left->data){
				
				return rightRotate(r);
				
			}else if(bf < -1 && newNode->data > r->right->data){
				
				return leftRotate(r);
				
			}else if(bf > 1 && newNode->data > r->left->data){
				
				r->left = leftRotate(r->left);
				return rightRotate(r);
				
			}else if(bf <-1 && newNode->data < r->right->data){
				
				r->right = rightRotate(r->right);
				return leftRotate(r);
				
			}
			
			return r;
			
		}
		
	public: 
	
	void Inorder(){
			
			DisplayInorder(root);
			
		}
	
	void AddNode(int num){
		
		Node *newNode = new Node;
		newNode->data = num;
		newNode->left = newNode->right = NULL;
		newNode->node_height = 1;
		root = insert(root, newNode);
		
	}
	
	void removeNode(int num){
			
			deleteNode(root, num);
			
	}
};

int main(){
	
	AVL t;
	t.AddNode(30);
	t.AddNode(60);
	t.AddNode(20);
	t.AddNode(10);
	t.AddNode(40);
	t.AddNode(5);
	t.AddNode(15);
	t.AddNode(25);
	t.AddNode(65);
	t.AddNode(-60);
	
	t.Inorder();
	cout<<endl;
	
	t.removeNode(30);
	
	t.Inorder();
	
}
