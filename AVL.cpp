#include<iostream>
using namespace std;

class BST{
	
	private: 
		
		struct Node{
			
			int data;
			Node *right, *left;
			int node_height;
		};
	
		Node *root;
		
		int height(Node *r){
			
			int lheight, rheight;
			
			if(r == NULL){
				
				return -1;
				
			}else{
				
				lheight = height(r->left);
				rheight = height(r->right);
				
				if(lheight > rheight)
					return lheight+1;
				else
					return rheight+1;
				
			}
			
		}
		
		int BF(Node *n){
			
			if(n==NULL){
				
				return -1;
				
			}else{
				
				return (height(n->left) - height(n->right));
				
			}
			
		}
		
		Node* insert(Node *r, Node *n){
			
			
			
			
			int bf = BF(temp);
				
			if(bf )
			
		}
		
		
		
		public:
		
		BST(){
			
			root = NULL;
			
		}
		
		void Insert(int num){
			
			Node *newNode = new Node;
			newNode->data = num;
			newNode->left = newNode->right = NULL;
			
			addNode(root, newNode);
					
			}
			
		}
};

int main(){
	
	
	return 0;
}
