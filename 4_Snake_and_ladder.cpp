#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    int snake_ladder(int src,int des){
        queue<int> q;
        map<int,int>distance;

        //This we are doing to keep track of the path 
        //create a hashmap
        map<int,int> parent;
        parent[src]=src;


        for(auto dist:l){
            distance[dist.first] = INT_MAX;
        }
        q.push(src);
        distance[src] = 0;

        while(!q.empty()){
            int nbrs = q.front();
            q.pop();
            for(auto nbr:l[nbrs]){
                if(distance[nbr]==INT_MAX){
                    q.push(nbr);
                     distance[nbr] = distance[nbrs]+1;

                     parent[nbr] = nbrs;
                }
            }

        }

        //Printing the path 
        int temp = des;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<temp<<endl;

        return distance[des];
    }
};
int main(){
    Graph g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j = dice+i;
            j+=board[j];
            if(j<=36){
                g.addEdge(i,j);
            }
        }
    }

    //agr hm 36 p he to iska mtlb ye h ye hm 36 p to he hi
    g.addEdge(36,36);
    cout<<g.snake_ladder(0,36);
}