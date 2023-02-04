#include<iostream>
using namespace std;

class Stack{
	
	private:
		char data;
		Stack *next;
		Stack *top;
		
	public:
		
		Stack(){
			
			top = NULL;
	
		}
		
	void push(char value){
		
		Stack *newNode = new Stack;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
		
	}
	
	char pop(){
		
		if(top == NULL){
			
			cout<<"Stack is empty."<<endl;
			
		}else{
			Stack *temp = top;
			int result = top->data;
			top = top->next;
			delete temp;
			return result;
		}	
	}
	
	char show_top(){
		
		return top->data;
		
	}	
	
};

int precedence(char a){
	
	if(a == '^'){
		
		return 3;
		
	}else if(a == '*' || a == '/'){
		
		return 2;
		
	}else if(a == '+' || a == '-'){
		
		return 0;
		
	}
	
}

string infix_to_postfix(){
	
	Stack s;
	
	int size;
	cout<<"Enter the length of expression (including parantheses): ";
	cin>>size;
	char *array = new char[size+1];
	cout<<endl<<"Enter expression: ";
	cin>>array;
	
	string postfix = "";
	
	for(int i = 0; i<size; i++){
		
		if(array[i] != '^' || array[i] != '+' || array[i] != '-' || array[i] != '*' || array[i] != '/' || array[i] != '(' || array[i] != ')'){
			
			postfix += array[i];	
			
		}else if(array[i] == '('){
			
			s.push(array[i]);
			
		}else if(array[i] == ')'){
			
			char temp = s.pop();
			
			while(temp != '('){
				
				postfix += array[i];
				temp = s.pop();	
			}
			
		}else if(array[i]){
			
			
			
			
		}
		
		
	}
	
	
}
int main(){
	
	
	
	
	return 0;
}
