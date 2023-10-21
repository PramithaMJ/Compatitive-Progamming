#include<iostream>
using namespace std;

#define INF 999

// DIJKSTRA
int V,src, cost [100][100];
int dist[100];
bool visited[100] = {0};
int parent[100];


void init(){
    for (int i = 0; i < V; i++)
    {
        parent[i]=i;
        dist[i] = INF;
    }
    dist[src] = 0;
}

int getNearest(){
    int minvalue = 0;
    int minnode = 0;
    for (int i = 0; i < V; i++)
    {
        if(!visited[i] && dist[i]<minvalue){
            minvalue = dist[i];
            minnode = i;
        }
        return minnode;
    }
    
}

void dijkstra(){
    for (int i = 0; i < V; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;

        for (int adj = 0 ; adj<V ; adj++){
            if(cost[nearest][adj] != INF && dist[adj]>dist[nearest]+cost[nearest][adj]){
                dist[adj] =  dist[nearest]+cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
    
}

void display(){
    cout<<"Node:\t\t\tCost : \t\t\tPath";
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";

        cout << i<<" ";
        int parnode = parent[i];

        while (parnode!=src){
            cout<<"<-"<<parnode<<" ";
            parnode = parent[parnode];
        }
        cout<<endl;
    }
}

int main(){

    cin>> V;

    for(int i;i<V;i++){
        for (int j = 0; j < V; j++){
            cin>>cost[i][j];
        }
    }

    cin>>src;
    init();
    dijkstra();
    display();

    return 0;
}