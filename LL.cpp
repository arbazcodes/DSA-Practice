#include<iostream>
using namespace std;

struct Node{
	
	int data;
	Node *next = NULL;
	
};

int size = 0;
Node *head = NULL;

void AddtoHead(int i){
	
	Node *newNode = new Node;
	newNode->data = i;
	
	if(head == NULL){
		
		newNode->next = NULL;
		head = newNode;
		size++;
		
	}else{
		
		newNode->next = head;
		head =  newNode;
		size++;
	}
	
}

void AddtoTail(int i){
	
	Node *newNode = new Node;
	newNode->data = i;
//	newNode->next = NULL;
	
	if(head == NULL){
		
		head = newNode;
		size++;
		
	}else{
		
		Node *temp = head;
		
		while(temp->next != NULL){
			
			temp = temp->next;
			
		}
		
		temp->next = newNode;
		size++;
		
	}
	
}

void DeletefromHead(){
	
	Node *temp = head;
	head = head->next;
	delete temp;
	size--;
	
}

void DeletefromTail(){
	
	Node *curr = head;
	Node *prev = NULL;
		
		while(curr->next != NULL){
			
			prev = curr;
			curr = curr->next;
			
		}
		
		prev->next = NULL;
		delete curr;
		size--;
}

void DeleteSpecific(int key){
	
	Node *curr = head;
	Node *prev = NULL;
		
	while(curr != NULL && curr->data != key){
			
		prev = curr;
		curr = curr->next;
			
	}
	
	if(curr == NULL){
		
		cout<<"Data not found."<<endl;
		
	}else{
		
		prev->next = curr->next;
		delete curr;
		size--;
			
	}
	
}

void findmid(){
	
	int count = 0;
	Node *mid = head, *temp = head;
	
	while(temp != NULL){
	
	if(count % 2 == 1){
		
		mid = mid->next;	
		
	}
	
	count++;
	temp = temp->next;
	
	}
	
	cout<<mid->data;
}

void AddinBetween(int i, int pos){
	
	Node *curr = head;
	Node *prev = NULL;
	Node *newNode = new Node;
	newNode->data = i;
		
	int k = 1;
	
	if(pos > size+1){
		
		cout<<"Fuck you in the ass."<<endl;
		
	}else{
	
	while(k != pos){
		
		k++;	
		prev = curr;
		curr = curr->next;
			
	}
	
	prev->next = newNode;
	newNode->next = curr;
	
	}
	
}

void Display(){
	
	Node *temp = head;
	
	while(temp != NULL){
		
		cout<<temp->data;
		temp = temp->next;
	}
	
}



int main(){
	
	AddtoTail(1);
	AddtoTail(2);
	AddtoTail(3);
	AddtoTail(4);
	AddtoTail(5);
//	AddtoTail(6);
	
	findmid();
	
	
	return 0;
}
