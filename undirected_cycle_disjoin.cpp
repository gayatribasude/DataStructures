#include<iostream>
#include<vector>
using namespace std;
class Graph{
	private:
		int e,v;
		vector<int> parent;
	public:
		Graph(int v,int e){
			this->v=v;
			this->e=e;
			parent.resize(v,-1);
		}
		int findParent(int vertex){
			if(parent[vertex]<=-1){
				return vertex;
			}
			return findParent(parent[vertex]);
		}

		void union_(int p1,int p2){
			//this means that 
			//p1's parent has less nodes attaches to it than p2's parent
			//therefore attack p1's node to parent p2
			if(parent[p1]>parent[p2]){
				parent[p2]+=parent[p1];
				parent[p1]=p2;
			}
			else{
				parent[p1]+=parent[p2];
				parent[p2]=p1;
			}
		}

};


int main(){
	int v,e;
	cin>>v>>e;
	Graph g(v,e);
	int u1,u2,p1,p2;
	bool ans=false;
	for(int i=0;i<e;i++){
		cin>>u1>>u2;
		if(ans==true) continue;
		p1=g.findParent(u1);
		p2=g.findParent(u2);
		if(p1==p2){
			ans=true;
			cout<<ans<<endl;
		}
		g.union_(p1,p2);
	}


	cout<<ans<<endl;

}
