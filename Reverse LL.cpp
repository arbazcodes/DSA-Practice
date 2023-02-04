#include<iostream>
using namespace std;

struct Node{
	
	int val;
	Node *next;

};


Node *head = NULL;

void Add(int v){
	
	Node *newNode = new Node;
	newNode->val = v;
	newNode->next = NULL;
	
	if(head == NULL){
		
		head = newNode;
		
	}else{
		
		Node *temp = head;
		
		while(temp->next != NULL){
			
			temp = temp->next;
			
		}
		
		temp->next = newNode;
	}
	
	
}


void Display(){
	
	Node *temp = head;
		
		while(temp != NULL){
			
			cout<<temp->val<<"   ";
			temp = temp->next;
			
		}
	
	
}

void reverse(){
	
	Node *prev = NULL, *curr = head, *next = curr->next;
	
	while(next != NULL){
		
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		
	}
	
	head = prev;
	
}

int main(){
	
	Add(1);
	Add(2);
	Add(3);
	Add(4);
	Add(5);
	
	Display();
	
	reverse();
	
	cout<<endl;
	
	Display();
	
	return 0;
}
