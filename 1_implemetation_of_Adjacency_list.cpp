#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;
class graph{
    int V;
    list<int> *l;
    public:
    graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printEdge(){
        for(int i=0;i<V;i++){
            cout<<"Verticex"<<i<<":->";
            for(int x:l[i]){
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.printEdge();
    return 0;
}