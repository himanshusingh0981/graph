#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    int *rank;
    int *parent;
    int V;
    DSU(int _v){
        this->V = _v;
        parent  = new int[_v];
        rank = new int[_v];
        for(int i=0;i<_v;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find_parent(int i){
        if(parent[i]==-1)return i;
        return parent[i] = find_parent(parent[i]);
    }

    void do_union(int i,int j){
        int s1 = find_parent(i);
        int s2 = find_parent(j);

        if(s1!=s2){
            if(rank[s1]>rank[s2]){
                parent[s2] = s1;
                rank[s1]+=rank[s2];
            }
            else{
                parent[s1] =s2;
                rank[s2]+=rank[s1];
            }
        }
    }
    void print(){
        for(int i=0;i<V;i++){
        cout<<parent[i]<<" "<<rank[i]<<" "<<endl;
        }
    }

};

class Graph{
    vector<vector<int>>edge_list;
    int v;
    public:
    Graph(int _v){
        this->v = _v;
    }
    void addEdge(int x,int y,int w){
        edge_list.push_back({w,x,y});
    }
    int kruskal(){

        sort(edge_list.begin(),edge_list.end());
        DSU s(v);
        int ans = 0;
        for(auto i: edge_list){
            int w = i[0];
            int x = i[1];
            int y = i[2];

            int s1 = s.find_parent(x);
            int s2 = s.find_parent(y);
            if(s1!=s2){
                s.do_union(x,y);
                ans+=w;
            }
        }

        return ans;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<endl<<g.kruskal();
}
