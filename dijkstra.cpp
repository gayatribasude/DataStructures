#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Graph{
	public:
		int v,e;
		int **adj;
		Graph(int v,int e){
			this->v=v;
			this->e=e;
			adj=new int*[v];
			for(int i=0;i<v;i++){
				adj[i]=new int[v];
				for(int j=0;j<v;j++){
					adj[i][j]=-1;
				}
			}
		}
		void addEdge(int source,int destination,int weight){
			adj[source][destination]=weight;
			adj[destination][source]=weight;
		}
		void printAdj(){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void acceptEdge(){
			for(int i=0;i<e;i++){
				int s,d,w;
				cin>>s>>d>>w;
				addEdge(s,d,w);
			}
		}
		vector<int> shortestDistance(int source){
			//distance,vertex
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
			vector<bool> visited(v,false);
			vector<int> ans(v,INT_MAX);
			ans[source]=0;
			int i,distance,vertex;
			pq.push(make_pair(0,source));
			while(pq.size()){
				distance=pq.top().first;
				vertex=pq.top().second;
				pq.pop();
				if(visited[vertex]==true) continue;
				visited[vertex]=true;
				for(i=0;i<v;i++){
					if(adj[vertex][i]!=-1 && visited[i]==false){
						if(ans[i]>adj[vertex][i]+distance){
							ans[i]=adj[vertex][i]+distance;
							pq.push(make_pair(ans[i],i));
						}
					}
				}
			}

			for(int i=0;i<v;i++){
		cout<<ans[i]<<" ";
	}
			return ans;
		}
};


int main(){
	int e,v,w,source;
	cout<<"Enter e and v:";
	cin>>e>>v;
	Graph g(v,e);
	cout<<"Enter u1 to u2 and weight";
	g.acceptEdge();
	cout<<"Enter source:";
	cin>>source;
	g.printAdj();
	vector<int> ans=g.shortestDistance(source);
	cout<<endl;

}