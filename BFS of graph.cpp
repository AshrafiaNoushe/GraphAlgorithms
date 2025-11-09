#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<bool>visited(V,0);
        vector<int>ans;
        q.push(0);
        visited[0]=1;
        int node;
        while(!q.empty()){
            node = q.front();
            ans.push_back(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    visited[adj[node][i]]=1;
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;

        
    }
};
int main()
{
int V=5;
vector<int> adj[V] = {
        {2, 3, 1},
        {0},
        {0, 4},
        {0},
        {2}
    };
Solution obj;
vector<int> ans = obj.bfs(V,adj);
for(auto i:ans){
    cout<<i<<" ";
}
return 0;
}