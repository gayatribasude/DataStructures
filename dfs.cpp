#include<iostream>
#include<vector>
using namespace std;

class Graph{
	public:
		int v,e;
		vector<int> *adj;
	Graph(int v,int e){
		this->v=v;
		this->e=e;
		adj=new vector<int>[v];
	}
	void addEdge(int vertex1,int vertex2){
		adj[vertex1].push_back(vertex2);
		adj[vertex2].push_back(vertex1);
	}
	void createAdj(){
		int vertex1,vertex2;
		for(int i=0;i<e;i++){
			cin>>vertex1>>vertex2;
			addEdge(vertex1,vertex2);
		}
	}
	
	void DFS(int source,vector<bool> &visited){
		cout<<source<<" ";
		visited[source]=true;
		for(auto i:adj[source]){
			if(visited[i]==false){
				DFS(i,visited);
			}
		}
	}
};
int main(){
	int e,v,source;
	cout<<"Enter e and v:";
	cin>>e>>v;
	Graph g(v,e);
	vector<bool> visited(v,false);
	g.createAdj();
	cin>>source;
	g.DFS(source,visited);
}