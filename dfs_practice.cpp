#include<bits/stdc++.h>
using namespace std;


const int maxN = 10e5;
vector<int> adj_list[maxN];
bool visited[maxN] ;

void dfs(int node){
    visited[node] = true;
    cout << node << " ";

    for(auto i : adj_list[node]){
        if(!visited[i])
                dfs(i);
    }
}

int32_t main(){
    
    int n,e;
    cin >> n >> e;

    for(int i = 1; i <= e; i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 1;
    dfs(src);
}