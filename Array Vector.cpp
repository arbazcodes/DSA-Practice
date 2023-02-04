#include<iostream>
using namespace std;

class Vector{
	
	private:
		int arr[50];
	public:
		
		Vector(){
		
			for(int i = 0; i<50; i++){
				
				arr[i] = 0;
				
			}
		
		}
		
		bool Member(int key){
			
			if(key > 0 && key <= 50){
			
				if(arr[key-1] == 1){
				
					return true;
				
				}else{
				
					return false;
				
				}
			}else{
				
				return -1;
				
			}
			
		}
	
		void Insert(int key){
			
			if(key > 0 && key <= 50){
			
				arr[key-1] = 1;
				
			}else{
				
				cout<<"Out of bounds."<<endl;
				
			}
			
			
		}
		
		void Delete(int key){
			
			if(key > 0 && key <= 50){
			
				arr[key-1] = 0;
				
			}else{
				
				cout<<"Out of bounds."<<endl;
				
			}
			
		}
		
		void Union(Vector x, Vector y){
			
			for(int i = 0; i<50; i++){
				
				if(y.arr[i] == 1 || x.arr[i] == 1){
					
					this->arr[i] = 1;
					
				}else{
				
					this->arr[i] = 0;
				
				}
				
		}
	}
		
		void Display(){
			
			for(int i = 0; i<50; i++){
					
					if(arr[i] == 1){
						
						cout<<i+1<<" ";
						
					}
					
				}
			
		}
		
		void Intersection(Vector x, Vector y){
			
			for(int i = 0; i<50; i++){
				
				if(x.arr[i] == 1 && y.arr[i] == 1){
					
					this->arr[i] = 1;
					
				}else{
				
					this->arr[i] = 0;
				
				}
				
				
			}
				
		}
	
	
	void Difference(Vector x, Vector y){
			
			for(int i = 0; i<50; i++){
				
				if(x.arr[i] == 1 && y.arr[i] != 1){
					
					this->arr[i] = 1;
					
				}else{
				
					this->arr[i] = 0;
				
				}
				
				
			}
				
		}
};



int main(){
	
	Vector a, b, c;
	
	a.Insert(1);
	a.Insert(5);
	a.Insert(6);
	a.Insert(2);
	a.Insert(8);
	a.Insert(15);
	a.Insert(49);
	a.Insert(37);
	
	a.Display();
	cout<<endl<<endl;
	
	
	b.Insert(6);
	b.Insert(12);
	b.Insert(32);
	b.Insert(41);
	b.Insert(25);
	b.Insert(15);
	b.Insert(46);
	
	b.Display();
	cout<<endl<<endl;
	
	b.Delete(46);
	b.Display();
	cout<<endl<<endl;
	
	c.Union(a,b);
	
	c.Display();
	cout<<endl<<endl;
	
	c.Intersection(a,b);
	
	c.Display();
	cout<<endl<<endl;
	
	c.Difference(a,b);
	
	c.Display();
	cout<<endl<<endl;
	
	
	return 0;
	
}
