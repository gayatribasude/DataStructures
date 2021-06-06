#include<iostream>
#include<vector>
using namespace std;
class Graph{
	private:
		int e,v;
		vector<int> *adj;
	public:
		Graph(int v,int e){
			this->v=v;
			this->e=e;
			adj=new vector<int>[v];
		}

		void addEdge(int source,int destination){
			adj[source].push_back(destination);
			adj[destination].push_back(source);
		}
		void acceptAdj(){
			for(int i=0;i<e;i++){
				int source,destination;
				cin>>source>>destination;
				addEdge(source,destination);
			}
		}
		bool detectCycle(int source,int parent,vector<bool> &visited){
			visited[source]=true;
			for(auto i:adj[source]){
				if(visited[i]==false){
					if(detectCycle(i,source,visited)==true){
						return true;
					}
				}
				else if(visited[i]==true && i!=parent){
					return true;
				}
			}
			return false;
		}

};


int main(){
	int v,e;
	cin>>v>>e;
	Graph g(v,e);
	g.acceptAdj();
	vector<bool> visited(v,false);
	bool ans=false;

	for(int i=0;i<v;i++){
		if(visited[i]==false){
			if(g.detectCycle(i,-1,visited)){
				ans=true;
				break;
			}
		}
	}
	cout<<ans<<endl;

}