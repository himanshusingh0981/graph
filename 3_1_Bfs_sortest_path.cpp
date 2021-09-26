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
        map<int,int>distance;

        for(auto dis:l){
            distance[dis.first] = INT_MAX;
        }
        q.push(src);
        distance[src] = 0;
        while(!q.empty())
        {
            int nbr = q.front();
            q.pop();

            for(int x : l[nbr]){
                if(distance[x]==INT_MAX){
                    q.push(x);
                    distance[x]=distance[nbr]+1;
                }
            }
        }
        for(auto x: l){
            cout<<"Source to->"<<x.first<<": "<<distance[x.first]<<endl;
        }
    }
};
int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,4);
    g.bfs_traversal(0);

}