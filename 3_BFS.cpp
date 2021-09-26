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
    void bfs_traversal(int src){
        queue<int> q;
        map<int,int>visited;

        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int nbr = q.front();
            cout<<q.front()<<"->";
            q.pop();

            for(int x : l[nbr]){
                if(!visited[x]){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
    }
};
int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs_traversal(0);

}