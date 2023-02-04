#include <iostream>
#include <string>

using namespace std;


struct Node

{

	int ID;

	string Name;

	Node *next;

};


Node *head = NULL;


void AddNode(string name, int id)

{

	Node *newNode = new Node();

	Node *temp = head;

	

	newNode->Name = name;

	newNode->ID = id;

	

	if(head == NULL)

	{

		newNode->next = NULL;

		head = newNode;

	}

	else

	{

		while(temp->next != NULL)

		{

			temp=temp->next;

		}

		temp->next = newNode;

	}

}


void Display()

{

	Node *temp = head;
	
	while(temp != NULL){
		
		cout<<"Name: "<<temp->Name<<endl;
		cout<<"ID: "<<temp->ID<<endl<<endl;
		
		temp = temp->next;
		
	}

}

void SortbyID()

{

	
       Node *sorted = NULL;
        Node* current = head;
        
        while (current != NULL) {
            
            Node* next = current->next;
           	Node *newnode = current;
           	
            if (sorted == NULL || sorted->ID >= newnode->ID) {
            	
            newnode->next = sorted;
            sorted = newnode;
            
        	}else {
        	
            Node* current = sorted;
            
            while (current->next != NULL && current->next->ID < newnode->ID){
            	
                current = current->next;
            }
            
            newnode->next = current->next;
            current->next = newnode;
        }
           
            current = next;
        }
        
        head = sorted;

}

void SortbyName()

{

	 Node *sorted = NULL;
        Node* current = head;
        
        while (current != NULL) {
            
            Node* next = current->next;
           	Node *newnode = current;
           	
            if (sorted == NULL || sorted->Name.length() >= newnode->Name.length()) {
            	
            newnode->next = sorted;
            sorted = newnode;
            
        	}
        else {
            Node* current = sorted;
            
            while (current->next != NULL && current->next->Name.length() < newnode->Name.length()){
            	
                current = current->next;
            }
            
            newnode->next = current->next;
            current->next = newnode;
        }
           
            current = next;
        }
        
        head = sorted;

}





int main()

{

	int choice;

	do

	{

		cout<<"1. Add Node."<<endl<<"2. Sort By ID."<<endl<<"3. Sort By Name."<<endl<<"4. Display."<<endl<<"5. Exit."<<endl;

		cout<<endl<<"Enter choice: ";

		cin>>choice;

		system("cls");

		switch(choice)

		{

			case 1:

			{
				
				string n;
				int i;
				
				cout<<"Enter ID: ";
				cin>>i;
				cout<<"Enter Name: ";
				cin>>n;
				
				cout<<endl;
				
				AddNode(n,i);
				
				break;
			}

			case 2:

			{

				SortbyID();
				Display();

				break;

			}

			case 3:

			{	

				SortbyName();
				Display();

				break;

			}

			case 4:

			{

				Display();

				break;

			}

			case 5:

			{

				cout<<"Good bye."<<endl;

				break;

			}

			default:

			{

				cout<<"Enter a valid choice."<<endl<<endl;

			}

		}

	}while(choice != 5);

	return 0;

}
