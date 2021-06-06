#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class GraphToSpanning{
public:
	int e,v;
	//int **adj;
	int adj[100][100];
	int cost;
	vector<int> parent;
	
	vector<bool> visited;

	GraphToSpanning(int v,int e){
		this->e=e;
		this->v=v;
		cost=0;
		parent.resize(v,-1);
		visited.resize(v,false);
		//adj=new int*[v];
		for(int i=0;i<v;i++){
			//adj[i]=new int[v];
			for(int j=0;j<v;j++){
				adj[i][j]=-1;
			}
		}

	}

	void createAdj(){
		for(int i=0;i<e;i++){
			int u1,u2,w;
			cin>>u1>>u2>>w;
			adj[u1][u2]=w;
			adj[u2][u1]=w;

		}
	}
	void printAdj(){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}

	void start(int source){
		//pair-> weight,vertex
		priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		pq.push(make_pair(0,source));
		int popped_weight,popped_vertex;
		while(pq.size()){
			popped_weight=pq.top().first;
			popped_vertex=pq.top().second;
			pq.pop();
			if(visited[popped_vertex]==true) continue;
			visited[popped_vertex]=true;
			cost+=popped_weight;
			cout<<popped_vertex<<" "<<popped_weight<<endl;
			for(int i=0;i<v;i++){
				if(visited[i]==false && adj[popped_vertex][i]!=-1){
					parent[i]=popped_vertex;
					pq.push(make_pair(adj[popped_vertex][i],i));
				}
			}
		}
		cout<<"Cost is:"<<cost<<endl;
	}

	
};



int main(){
	int v,e,source;
	cin>>v>>e;
	GraphToSpanning g(v,e);
	g.createAdj();
	g.printAdj();
	cin>>source;
	g.start(source);
}