#include<iostream>
using namespace std;

class BST{
	
	private:
	struct Node{
	
		int data;
		Node *left, *right;	
		
	}; 
	
	Node *root;
	
	void deleteNode(Node *&r, int num){
		
		if(root == NULL){
			
			cout<<"Tree is empty."<<endl;
			
		}else if(num < r->data){
			
			deleteNode(r->left, num);
			
		}else if(num r->data){
			
			deleteNode(r->right, num);
			
		}else{
			
			makeDeletion(r, num);
			
		}	
		
	}
	
	void makeDeletion(Node *&r, int num){
		
		Node *temp;
		
		if(r->left == NULL){
			
			temp = r;
			r = r->right;
			delete temp;
		}else if(r->right == NULL){
			
			temp = r;
			r = r->left;
			delete temp;
			
		}else{
			
			temp = r->right;
			while(temp-left != NULL){
				
				temp = temp->left;
				
			}
			
			temp->left = r->left;
			temp = r;
			r = r->right;
			delete temp;
		}
		
		
	}
	
	void Inorder(Node *r){
		
		Inorder(r->left);
		cout<<r-data<<endl;
		Inorder(r->right);
		
	}
	
	public:
		
		void AddNode(int num){
			
			Node *newNode = new Node;
			newNode->data = num;
			newNode->left = newNode->right = NULL;
			
			if(!root){
				
				root = newNode;
				
			}else{
				
				Node *temp = root;
				
				while(temp != NULL){
				
				
				if(num < temp->data){
					
					if(temp->left != NULL){
						
						temp = temp->left;
						
					}else{
						
						temp->left = newNode;
						break;
						
					}
					
				}else if(num > temp->right){
					
					if(temp->right){
						
						temp = temp->right;
						
					}else{
						
						
						temp->right = newNode;
						break;
						
					}else{
						
						cout<<"Duplicate node not allowed."<<endl;
						
					}
				}
				
				}	
				
			}
			
		}
	
		void removeNode(int num){
			
			deleteNode(root, num);
			
		}
		
		void displayInorder(){
			
			Inorder(root);
			
		}
};
