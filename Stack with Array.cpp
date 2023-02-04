#include<iostream>
using namespace std;

class Stack{
	
	private:
		int data, top, size;
		int *array;
		
	public:
		
		Stack(int s){
			
			array = new int[s];
			top = -1;
			size = s;
	
		}
		
		bool isFull(){
			
			if(top == size-1){
				
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
		
		void push(int value){
			
			if(isFull()){
				
				cout<<"Stack is full."<<endl;
				
			}else{
				
				top++;
				array[top] = value;
				
			}
			
			
		}
		
		void pop(){
			int value = 0;
			
			if(isEmpty()){
				
				cout<<"Stack is empty."<<endl;
				
			}else{
				
				value = array[top];
				top--;
				
			}
			
			cout<<"Value: "<<value<<endl;
		}
	
};


int main(){
	
	Stack s(4);
	
	s.push(5);
	s.push(3);
	s.push(6);
	s.push(9);
	s.push(2);
	
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	
	
	return 0;
}
