#include<iostream>
using namespace std;

struct Node{
	
	int data;
	Node *next;
	
};

Node *head = NULL;

void AddtoTail(int value){
	
	Node *newNode = new Node;
	newNode->data = value;
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


void FindSpecificNode(int key){
	
	Node *temp = head;
	
	while(temp != NULL && temp->data != key){
		
		temp = temp->next;
		
	}
	
	if(temp == NULL){
		
		cout<<"The node is not in the list."<<endl;
		
	}else{
		
		
		cout<<"Found Value: "<<temp->data<<endl;
		
	}
	
	
}


void DeleteNode(int key){
	
	Node *current = head;
	Node *previous;
	
	
	
	if(current == NULL){
		
		cout<<"The node is not in the list."<<endl;
		
	}else{
		
		while(current->next != NULL && current->data != key){
		
		previous = current;
		current = current->next;
		
	}
		previous->next = current->next;
		delete current;
		
	}
	
	
}

void display(){
	
	Node *temp = head;
	
	while(temp != NULL){
		
		cout<<temp->data<<endl;
		temp = temp->next;
		
	}
	
	
	
}

int main(){
	
	AddtoTail(10);
	AddtoTail(20);
	AddtoTail(30);
	AddtoTail(40);
	AddtoTail(50);
	AddtoTail(60);
	display();
	
	FindSpecificNode(30);
	DeleteNode(20);
	display();
	
	
	return 0;
}
