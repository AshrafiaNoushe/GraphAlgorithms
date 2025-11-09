#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
bool vis[mx];
vector<int>adjM[mx];
void dfs(int u){
	cout<<"\n";
    vis[u]=1;
    cout<<u <<" addjacent nodes: "<<"\n";
    for(auto it:adjM[u]){
    	cout<<it<<" ";
        if(vis[it]==0){
            dfs(it);
        }
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjM[u].push_back(v);
        adjM[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}