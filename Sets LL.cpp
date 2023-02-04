#include<iostream>
using namespace std;

class Set{
	
	private:
		struct element{
			
			int data;
			element *next;
			
		};
		
		element *head;
		
	public:
		
		Set(){
			
			head = NULL;
			
		}
		
		void Insert(int key){
			
			element *curr = head;
			element *newElement = new element;
			newElement->data = key;
			
			
			if(head == NULL){
				
				newElement->next = NULL;	
				head = newElement;
				
			}else if(key < head->data){
				
				
				newElement->next = head;
				head = newElement;
				
			}else{
				
				while(curr->next != NULL && curr->next->data < key){
					
					curr = curr->next;
					
				}
				
				if(curr->next == NULL){
					
					curr->next = newElement;
					newElement->next = NULL;
					
				}else{
					
					newElement->next = curr->next;
					curr->next = newElement;
					
				}
				
		}
	}
	
	element *gethead(){
		
		return head;
		
	}
	
		void Intersection(Set x, Set y){
			
			element *temp1 = x.head;
			
			while(temp1 != NULL){
				
				element *temp2 = y.head;
				
				while(temp2 != NULL){
					
					if(temp1->data == temp2->data){
						
						Insert(temp1->data);
						
					}	
					
					temp2 = temp2->next;
				}
				
				temp1 = temp1->next;
			}
			
			
			
		}
		
		void Union(Set x, Set y){
			
			element *temp1 = x.head;
			element *temp2 = y.head;
			
			while(temp1 != NULL && temp2 != NULL){
				
				if(temp1->data < temp2->data){
					
					while(temp1 != NULL && temp1->data < temp2->data){
						
						Insert(temp1->data);
						temp1 = temp1->next;
					}
					
					Insert(temp2->data);
					if(temp1 != NULL)
					temp1= temp1->next;
					if(temp2 != NULL)
					temp2 = temp2->next;
					
				}else if(temp2->data < temp1->data){
					
					
					while(temp2 != NULL && temp2->data < temp1->data){
						
						Insert(temp2->data);
						temp2 = temp2->next;
					}
					
					Insert(temp1->data);
					if(temp1 != NULL)
					temp1= temp1->next;
					if(temp2 != NULL)
					temp2 = temp2->next;	
					
				}else if(temp1->data == temp2->data){
					
					Insert(temp1->data);
					if(temp1 != NULL)
					temp1= temp1->next;
					if(temp2 != NULL)
					temp2 = temp2->next;
					
				}
				
				
			}
			
			if(temp2 != NULL){
				
				while(temp1 != NULL){
					
					Insert(temp1->data);
					temp1 = temp1->next;
					
				}
				
			}else if(temp1 != NULL){
				
				while(temp2 != NULL){
					
					Insert(temp2->data);
					temp2 = temp2->next;
					
				}
				
			}
			
		}
		
		void Display(){
			
			element *temp = head;
			
			while(temp != NULL){
				
				cout<<temp->data<<"  ";
				temp = temp->next;
			}
			
		}

		
};

int main(){
	
	Set a,b,c,d;
	
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
	
	c.Intersection(a,b);
	
	c.Display();
	cout<<endl<<endl;
	
	d.Union(a,b);
	
	d.Display();
	cout<<endl<<endl;
	
	return 0;
}
