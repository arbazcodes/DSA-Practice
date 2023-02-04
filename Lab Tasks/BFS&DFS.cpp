#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class Graph{
	
	private:
		struct AdjListNode{
			
			int data;
			AdjListNode *next;
			
		};
		
		struct AdjList{
			
			AdjListNode *head;
			
		};
		
		AdjList *array;
		int size;
		
	public:
		
		Graph(int s){
			
			size = s+1;
			array = new AdjList[size];
			
			for(int i = 1; i < size; i++){
				
				array[i].head = NULL;
				
			}
			
		}
		
		void Add_Edge(int src, int dest){
			
			AdjListNode *newNode = new AdjListNode;
			
			newNode->data = dest;
			newNode->next = array[src].head;
			array[src].head = newNode;
			
			newNode = new AdjListNode;
			newNode->data = src;
			newNode->next = array[dest].head;
			array[dest].head = newNode;
			
		}
		
		void Print_Graph(){
	
			for(int i = 1; i < size; i++){
	
				AdjListNode *temp = array[i].head;
		
				cout<<(i)<<": ";
		
				while(temp != NULL){
			
					cout<<temp->data;
			
					if(temp->next != NULL){
				
						cout<<", ";
				
					}
					
					temp = temp->next;	
				}
		
				cout<<endl;
	
			}
	
		}
		
		void BFS(int start_vertex){
			
			bool visited_vertices[size];
			
			for(int i = 1; i < size; i++){
				
				visited_vertices[i] = false;
				
			}
			
			queue<int> q;
			q.push(start_vertex);
			visited_vertices[start_vertex] = true;
			
			AdjListNode *temp = array[start_vertex].head;		
		
			while(!q.empty()){
		
				cout<<q.front()<<"  ";
		
				while(temp != NULL){
			
					if(visited_vertices[temp->data] == false){
				
						q.push(temp->data);
						visited_vertices[temp->data] = true;
				
					}
					
					temp = temp->next;
			
				}
				
				q.pop();
				temp = array[q.front()].head;
			}	
			
		}
		
		
		void DFS(int start_vertex){
			
  			bool visited_vertices[size];
			
			for(int i = 1; i < size; i++){
				
				visited_vertices[i] = false;
				
			}
			
			stack<int> s;
			s.push(start_vertex);
			visited_vertices[start_vertex] = true;
			
			AdjListNode *temp = array[start_vertex].head;		
		
			while(!s.empty()){
		
				cout<<s.top()<<"  ";
				s.pop();
				
				while(temp != NULL){
			
					if(visited_vertices[temp->data] == false){
				
						s.push(temp->data);
						visited_vertices[temp->data] = true;
				
					}
					
					temp = temp->next;
			
				}
				
				temp = array[s.top()].head;
			}	
		}
				
		
	
	
};

int main(){
	
	
	Graph graph(5);
	
	graph.Add_Edge(1, 2);
	graph.Add_Edge(1, 3);
	graph.Add_Edge(1, 4);
	graph.Add_Edge(2, 3);
	graph.Add_Edge(2, 5);
	
	
	graph.Print_Graph();
	
	cout<<endl<<"BFS starting at vertex 1: "<<endl;
  	graph.BFS(1);
  	
  	cout<<endl<<"BFS starting at vertex 1: "<<endl;
  	graph.DFS(1);
	
	return 0;
}
