//Cannot figure out how to do it with queues. Did it by Stack instead.

#include<iostream>
using namespace std;

class Stack{
	
	private:
		int top, stack_size;
		char *array;
		
		
	public:
		
		Stack(int s){
			
			top = -1;
			array = new char[s];
			stack_size = s;
			
			
		}
		
		void Push(char x){
			
			if(isFull()){
				
				cout<<"Stack is full."<<endl;
				
			}else{
				
				top++;
				array[top] = x;
					
			}
			
			
		}
		
		char Pop(){
			
			if(isEmpty()){
				
				cout<<"Stack is empty."<<endl;
				
			}else{
				
				int x = array[top];
				top--;
				return x;
					
			}
			
		}
	
		bool Compare(char a, char b){
			
			if( a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']'){
				
				return true;
				
			}else{
				
				return false;
				
			}
			
		}
		
		bool isFull(){
			
			if(top == stack_size-1){
				
				return true;
				
			}else{
				
				return false;
				
			}
			
		}
	
		bool isEmpty(){
			
			if(top == -1){
				
				return true;
				
			}else{
				
				return false;
				
			}
			
		}
		
		char ShowTop(){
			
			return array[top];
			
		}
};





int main(){
	
	int size;
	
	cout<<"Enter the size of the expression: ";
	cin>>size;
	
	Stack s(size);
	char str[size+1];
	
	cout<<"Enter expression: ";
	cin>>str;
	
	cout<<endl;
	
	for(int i = 0; i<size; i++){
		
		cout<<str[i];
		
	}
	cout<<endl<<endl;
	 
	
	for(int i = 0; i<6; i++){
	
		if(str[i] == '{' || str[i] == '(' || str[i] == '['){
		
			s.Push(str[i]);
		
		}else if(!s.Compare(s.ShowTop(), str[i])){
			
			cout<<"Expression does not have balanced brackets."<<endl;
			break;
		}
		else{
			
			s.Pop();		
		}
	
	}
	
	if(s.isEmpty()){
		
		cout<<"Expression has balanced brackets."<<endl;
		
	}
	
	
	
	return 0;
}
