#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>l;
    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfsHelper(int src, map<int,bool>&visited){
        cout<<src<<"-->";
        visited[src]= true;

        for(auto p :l[src]){
            if(!visited[p]){
                dfsHelper(p,visited);
            }
        }
    }
    void DFS(int src){
        
        map<int,bool>visited;
        for(auto p:l){
            visited[p.first] =false; 
        }
        dfsHelper(src,visited);    
    }
};
int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);
    g.DFS(0);
}