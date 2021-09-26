#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    unordered_map<string,list<pair<string,int>>> l;

    public:
    void addEdge(string x, string y,bool bid,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bid==true){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printEdge(){
        for(auto cit:l){
            string city = cit.first;
            list<pair<string,int>>nbr = cit.second;
            cout<<"City "<<city<<"->";
            for(auto nbr_city:nbr){
                string city = nbr_city.first;
                int distance = nbr_city.second;
                cout<<"("<<city<<","<<distance<<")";
            }
            cout<<endl;

        }
    }
};
int main(){
   
    
    graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printEdge();
    return 0;
}