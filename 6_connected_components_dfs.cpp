#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;

    public:
    void addedge(int x, int y){
        l[x].push_back(y);
    }
    void dfs_helper(int src,map<int,bool>&visited,list<int>&ordering){
        visited[src]=true;
        for(auto it:l[src]){
            if(!visited[it]){
                dfs_helper(it,visited,ordering);
            }
        }
        ordering.push_front(src);
        return ;        
    }
    void dfs(int src){
        map<int,bool>visited;
        list<int> ordering;
        for(auto p:l){
            visited[p.first] = false;
        }
        for(auto it:l){
            if(!visited[it.first]){
                dfs_helper(it.first,visited,ordering);
            }
        }
        for(int i:ordering){
            cout<<i<<" ";
        }
    }
};
int main(){
    Graph g;
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(4,2);
    g.addedge(1,4);
    g.dfs(0);
    return 0;
}