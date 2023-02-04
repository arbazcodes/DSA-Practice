#include<iostream>
#include<windows.h>
using namespace std;

struct Node{
	
	int reg;
	string name;
	Node *next, *previous;
	
};

Node *head = NULL;
Node *tail = NULL;

void AddToHead(int r, string s){
	
	Node *newNode = new Node;
	newNode->reg = r;
	newNode->name = s;
	newNode->previous = NULL;

	if(head == NULL){
		
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
		
	}else{
		
		newNode->next = head;
		head = newNode;
		
	}
	
	
}

void AddToTail(int r, string s){
	
	Node *newNode = new Node;
	newNode->reg = r;
	newNode->name = s;
	newNode->next = NULL;

	if(head == NULL){
		
		newNode->previous = NULL;
		head = newNode;
		tail = newNode;
		
	}else{
		
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
		
	}
		
}

void AddToMiddle(string key1, string key2){
	
	int r;
	string s;
	Node *newNode = new Node;
	Node *curr = head;
	Node *prev = curr;
	
	if(head == NULL && tail == NULL){
		
		cout<<"List is empty."<<endl;
		
	}else if (head == tail){
		
		cout<<"There's only one student in the list."<<endl;
		
	}else{
		
		cout<<"Enter reg number: ";
		cin>>r;
					
		cout<<"Enter name: ";
		cin>>s;
		
		newNode->reg = r;
		newNode->name = s;
		
		while(curr != NULL && prev->name != key1 && curr->name != key2){
			
			prev =  curr;
			curr = curr->next;
				
		}
		
		if(curr == NULL){
			
			cout<<"Position not found in the list."<<endl;
			
		}else{
			
			newNode->next = curr;
			newNode->previous = prev;
			
			curr->previous = newNode;
			prev->next = newNode;
			
		}	
	}
	
}

void showAll(){
	
	Node *temp = head;
	
	if(temp == NULL){
		
		cout<<"List is empty."<<endl;
		
	}else{
	
	while(temp != NULL){
		
		cout<<"Reg Number: "<<temp->reg<<endl;
		cout<<"Name: "<<temp->name<<endl<<endl;
		
		temp=temp->next;
		
	}
	
	}
	
}

void RemoveSpecific(string key){
	
	Node *curr = head;
	Node *prev;
	
	while(curr != NULL && curr->name != key){
		
		prev = curr;
		curr = curr->next;
		
		
	}
	
	if(curr == NULL){
		
		cout<<"Student not found in the list."<<endl;
		
	}else{
		
		
		
		if(curr->next != NULL && curr->previous != NULL){
			
			prev->next = curr->next;
			prev = curr;
			curr = curr->next;
			
			curr->previous = prev->previous;
			
			delete prev;
			
		}else if(curr->next == NULL){
	
			prev->next = NULL;
			tail = prev;
			delete curr;
			
		}else if(curr->previous == NULL){
			
			prev = curr;
			curr = curr->next;
			head = curr;
			
			curr->previous = NULL;
			
			
			delete prev;
			
		}else if(curr->next == NULL && curr->previous == NULL){
			
			delete curr;
			
			head = NULL;
			tail = NULL;
			
		}
	}
	
}

void RemoveAll(){
	
	Node *curr = head;
	Node *prev;
	
	while(curr != NULL){
		
		prev = curr;
		curr = curr->next;
		delete prev;
		
	}
	
	head = NULL;
	tail = NULL;
	
	
}

int main(){
	
	int choice;
	
	do{
		
		
		cout<<endl<<"0) Exit."<<endl<<"1) Add node at head."<<endl<<"2) Add node to tail."<<endl<<"3) Add node in the middle."<<endl<<"4) Show all students."<<endl<<"5) Remove a specific student. "<<endl<<"6) Remove all."<<endl;
		cout<<endl<<"Enter choice: ";
		cin>>choice;
		
		system("cls");
		
		
		
		switch(choice){
			
			case 0:
				{
					cout<<"Have a nice day!"<<endl;
					break;
				}
			
			case 1:
				{	
					int r;
					string s;
					
					cout<<"Enter reg number: ";
					cin>>r;
					
					cout<<"Enter name: ";
					cin>>s;
					
					AddToHead(r,s);
					
					break;
				}
				
			case 2:
				{	
					int r;
					string s;
					
					cout<<"Enter reg number: ";
					cin>>r;
					
					cout<<"Enter name: ";
					cin>>s;
					
					AddToTail(r,s);
					
					break;
				}
				
			case 3:
				{	
					string k1, k2;
					
					
					
					cout<<"Enter names of the students between which you want to add: "<<endl;
					cin>>k1>>k2;
					
					AddToMiddle(k1, k2);
					
					break;
				}
				
			case 4:
				{
					
					showAll();
					break;
				}
			
			case 5: 
				{
					string k;
					cout<<"Enter the name of the student you want to remove: ";
					cin>>k;
					RemoveSpecific(k);
					break;	
					
				}
				
			case 6: 
				{
				
					RemoveAll();
					break;
					
				}
			
			default:
				cout<<"Enter a valid choice."<<endl;
				break;	
				
		}
		
	}while(choice != 0);
	
	
	return 0;
}
