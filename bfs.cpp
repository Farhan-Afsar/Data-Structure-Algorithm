#include<bits/stdc++.h>
using namespace std;


const int maxN = 1e5;
vector<int> adj_list[maxN];
int visited [maxN];

void bfs(int src){
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();

        cout << head << endl;

        for(int adj_node : adj_list[head]){
            if (visited[adj_node] == 0){
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}
int32_t main(){

    //visit all node in a graph
    //output the order that nodes are visited

    //Step
    //1. select a node
    //2.visit all adj node

    //BFS -> level order traversal 
    int n,e;
    cin >> n >> e;
    for(int i = 1; i <= e; i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // for(int i = 1; i <= n; i++){
    //     cout << i << " -> ";
    //     for(auto it : adj[i]){
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }
    int src = 2;
     bfs(src);
}