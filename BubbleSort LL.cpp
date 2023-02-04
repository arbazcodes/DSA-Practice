// C++ program for insertion sort 
#include <bits/stdc++.h>
using namespace std;

struct Node{
	
	int data;
	Node *next;
	
};

Node *head = NULL;

void Add(int v){
	
	Node *newNode = new Node;
	newNode->data = v;
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
			
			cout<<temp->data<<"   ";
			temp = temp->next;
			
		}
	
	
}
void BubbleSort() 
{ 

	Node *p, *q, *end;

    
    for(end = NULL; end != head; end = p){
    	
    	
    	for(p = head; p->next != end; p=p->next){
    		
    		q = p->next;
    		
    		if(p->data > q->data){
    			
    			int temp;
    			temp = p->data;
    			p->data = q->data;
    			q->data = temp;
    			
			}
    		
    		
		}
    	
    	
	}
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 

/* Driver code */
int main() 
{ 
    Add(9);
    Add(2);
    Add(5);
    Add(6);
    Add(7);
    
    Display();
    
    BubbleSort();
    cout<<endl;
    
    Display();

    return 0; 
}
