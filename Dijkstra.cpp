#include<bits/stdc++.h>
using namespace std;
int const INF = 1e9;
void dijkstra(int source, int n, vector<pair<int,int>>adj[]){
    vector<int>dist(n+1,INF);
    dist[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int dis_so_far = top.first;
        int node = top.second;
        if(dis_so_far>dist[node]){
            continue;
        }
        for(auto it:adj[node]){
            int next = it.first;
            int weight = it.second;
            if(dis_so_far+weight<dist[next]){
                dist[next]= dis_so_far+weight;
                pq.push({dist[next],next});
            }
        }

    }
    cout<<"Shortest distance from source: "<<"\n";
    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            cout<<"Node: "<<i<<" is unreachable\n";
        }else{
            cout<<"Node: "<<i<<" distance "<<dist[i]<<" ";
        }
    }
    cout<<endl;


}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source;
    cin>>source;
    dijkstra(source,n,adj);
    
}
/*
input:
5 6
1 2 2
1 3 4
2 4 7
2 5 1
3 5 3
5 4 2
1

output:
1
Shortest distance from source:
Node: 1 distance 0 Node: 2 distance 2 Node: 3 distance 4 Node: 4 distance 5 Node: 5 distance 3
*/