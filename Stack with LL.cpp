#include<iostream>
using namespace std;

class Stack{
	
	private:
		int data;
		Stack *next;
		Stack *top;
		
	public:
		
		Stack(){
			
			top = NULL;
	
		}
		
	void push(int value){
		
		Stack *newNode = new Stack;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
		
	}
	
	void pop(){
		
		if(top == NULL){
			
			cout<<"Stack is empty."<<endl;
			
		}else{
			
			Stack *temp = top;
			cout<<top->data<<endl;
			top = top->next;
			delete temp;
		}
		
		
	}	
	
};

int main(){

Stack s;

s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);


s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();

	
	
	return 0;
}
