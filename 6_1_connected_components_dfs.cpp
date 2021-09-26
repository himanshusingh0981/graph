#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
	map<int,list<int>>l;
	public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfs_helper(int src,map<int,bool>&visited){
		visited[src] = true;
		for(auto x:l[src]){
			if(!visited[x]){
				dfs_helper(x,visited);
			}
		}
	}
	int DFS(int src,int n){
		map<int,bool>visited;
	    for(int i=1;i<=n;i++){
			visited[i] = false;
		}
		int count=0;
		for(int i=1;i<=n;i++){
			
			if(!visited[i]){
				count++;
				dfs_helper(i,visited);
			}
		}
		return count;
	}
};
int main(){
	int n,e;
	Graph g;
	cin>>n>>e;
	while(e--){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	cout<<g.DFS(1,n)<<endl;
	return 0;
}