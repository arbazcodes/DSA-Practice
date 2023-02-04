#include<iostream>
using namespace std;



int main(){
	
	int array[6];
	int *ptr = array;
	
	cout<<"Enter 6 array elements: "<<endl;
	
	for(int i = 0; i<6; i++){
		
		cin>>*(ptr+i);
			
	}	
	
	cout<<endl<<"Array: "<<endl;
	
	for(int i = 0; i<6; i++){
		
		cout<<*(ptr+i)<<endl;
			
	}
	
	int max = *ptr;
	
	for(int i = 0; i<6; i++){
	
		if(*(ptr+i) > max){
			
			max = *(ptr+i);
			
		}
			
	}
	
	cout<<endl<<"Max: "<<max<<endl;
	
	
	return 0;
}
