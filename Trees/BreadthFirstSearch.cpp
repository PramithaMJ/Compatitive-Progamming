#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void bfs(vector<int> g[],int dist[],int start,int n){
    bool visited[n];
    memset(visited,false,n*sizeof(visited[0]));

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        start = q.front();
        q.pop();
        for (auto i : g[start]){
            if(!visited[i]){
                visited[i]=true;
                dist[i]=dist[start]+6;
                q.push(i);
    }
}

int main(){
    int Test;
    cin>>Test;
    while (Test--)
    {
        int n,m;
        cin>>n>>m; // number of nodes and edges in the graph

        vector<int> g[n];

        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }

        int start;
        cin>>start;

        int dist[n];
        memset(dist,-1,n*sizeof(dist[0]));

        bfs(g,dist,start-1,n);

        for (int i = 0; i < n; i++)
        {
            if (i!=start-1)
            {
                cout<<dist[i]<<" ";
            }
        }
        cout<<endl;        
    }
    return 0;
}