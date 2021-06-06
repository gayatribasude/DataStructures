#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int vertex1,int vertex2){
	adj[vertex1].push_back(vertex2);
	adj[vertex2].push_back(vertex1);
}

void BFS(vector<int> adj[],int source,vector<bool> &visited){
	queue<int> q;
	q.push(source);
	visited[source]=true;
	int popped;
	while(q.size()){
		popped=q.front();
		cout<<popped<<" ";
		q.pop();
		for(auto v:adj[popped]){
			if(visited[v]==false){
				visited[v]=true;
				q.push(v);
			}
		}
	}
}


int main(){
	int e,v,vertex1,vertex2;
	cout<<"Enter e and v:";
	cin>>e>>v;

	vector<int> adj[v];
	vector<bool> visited(v,false);

	cout<<"Enter edge as u1 and u2"<<endl;
	

	for(int i=0;i<e;i++){
		cin>>vertex1>>vertex2;
		addEdge(adj,vertex1,vertex2);
	}
	cout<<"Enter source vertex";
	cin>>vertex1;
	cout<<"BFS Traversal:"<<endl;
	BFS(adj,vertex1,visited);
}