#include<iostream>
using namespace std;


void smallest_value(int *temp, int size){
	
	int smallest = *temp;
	
	for(int i = 0; i<size; i++){
		
		if(*(temp+i) < smallest){
			
			smallest = *(temp+i);
			
		}
			
	}
	
	cout<<endl<<endl<<"Smallest: "<<smallest<<endl;
		
}

void traversal_back(int *temp, int sizeofarray){
	
	cout<<endl<<"Initial order: "<<endl;
	
	for(int i = 0; i<sizeofarray; i++){
		
		cout<<"Value: "<<*(temp+i)<<"    Address: "<<temp+i<<endl;
			
	}
	
	
	cout<<endl<<"Reversed order: "<<endl;
	
	for(int i = sizeofarray-1; i>=0; i--){
		
		cout<<"Value: "<<*(temp+i)<<"    Address: "<<temp+i<<endl;
			
	}
	
}


int main(){
	
	const int size = 5;
	
	int *ptr;
	ptr = new int[size];
	
	
	cout<<"Enter 5 array elements: "<<endl;
	
	for(int i = 0; i<size; i++){
		
		cin>>*(ptr+i);
			
	}
	
	smallest_value(ptr,size);
	traversal_back(ptr,size);
	
	
	
	return 0;
	
}
