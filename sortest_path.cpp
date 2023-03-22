#include<bits/stdc++.h>
using namespace std;

const int a = 1e5;
int visited[a];
vector<int> adj_list[a];
int level[a];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    level[src] = 0;

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int i : adj_list[head]){
            if(visited[i] == 0){
                visited[i] = 1;
                level[i]= level[head] + 1;
                q.push(i);
            }
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    bfs(src);

    for(int i = 0; i < n; i++){
        cout << i << " Level -> " << level[i] << endl;
    }
    
}