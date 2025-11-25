#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int mx = 1e5+123;
bool vis[mx];
vector<int>adjM[mx];
void bfs(int start){
    queue<int>q;
    cout<<start<<"child nodes: "<<"\n";
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it:adjM[u]){
        	if(!vis[it]){
        		cout<<it<<" ";
        		vis[it]=1;
        		q.push(it);
        	}
        }
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adjM[u].push_back(v);
        adjM[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
}