#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited [N];
vector<int> adj_list[N];

void dfs(int node){
        cout << node << endl;
        visited[node] = 1;

        for(int adj_node : adj_list[node]){
            if (visited[adj_node] == 0){
                dfs(adj_node);
            }
        }
}
int32_t main(){
  
    //DFS -> Depth first search

    int n,e;
    cin >> n >> e;

    for(int i = 0 ; i < e; i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    int src = 0;
    dfs(src);

}