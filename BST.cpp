#include<iostream>
using namespace std;

class BST{
	
	private: 
		
		struct Node{
			
			int data;
			Node *right, *left;
			
		};
	
		Node *root;
		
		void DisplayInorder(Node *temp){
			
			if(temp == NULL)
				return;
				
			DisplayInorder(temp->left);
			cout<<temp->data<<" ";
			DisplayInorder(temp->right);
			
			
		}
		
		void deleteNode(Node *&r, int num){
			
			if(num < r->data){
				
				deleteNode(r->left, num);
				
			}else if(num > r->data){
				
				deleteNode(r->right, num);
				
			}else{
				
				makeDeletion(r,num);
				
			}
			
		}
		
		void makeDeletion(Node *&r, int num){
			
			Node *temp;
			
			if(r == NULL){
				
				cout<<"Can't delete empty node."<<endl;
				
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
				
				while(temp->left)
					temp = temp->left;
					
				temp->left = r->left;
				temp = r;
				r = r->right;
				delete temp;
				
				
			}
			
			
		}
		
	public:
		
		void InsertNode(int num){
			
			Node *newNode = new Node;
			newNode->data = num;
			newNode->left = newNode->right = NULL;
			
			Node *temp = root;
			
			if(root == NULL){
				
				root = newNode;
				
			}else{
				
				while(temp != NULL){
					
					if(num < temp->data){
						
						if(temp->left != NULL){
							
							temp = temp->left;	
							
						}else{
							
							temp->left = newNode;
							break;
							
						}
						
					
						
					}else if(num > temp->data){
						
						if(temp->right != NULL){
							
							temp = temp->right;	
							
						}else{
							
							temp->right = newNode;
							break;
							
						}
						
					}else{
						
						cout<<"Duplicate value."<<endl;
						break;
						
					}
						
				}
				
			}
			
		}
		
		void Inorder(){
			
			DisplayInorder(root);
			
		}
		
		void removeNode(int num){
			
			deleteNode(root, num);
			
		}
};



int main(){
	BST t;
	t.InsertNode(5);
	t.InsertNode(8);
	t.InsertNode(3);
	t.InsertNode(12);
	t.InsertNode(9);
	t.Inorder();
	t.removeNode(5);
	t.Inorder();
	
	return 0;
}
