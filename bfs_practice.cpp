#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int maxN= 1e5;
bool visited[maxN];
vector<int> adj_list[maxN];

void bfs(int src){
        queue<int> a;
        visited[src] = true;
        a.push(src);

        while(!a.empty()){
            int head = a.front();
            a.pop();
            cout << head << endl;

            for(int i : adj_list[head]){
                if(visited[i] == false){
                    visited[i] = true;
                    a.push(i);
                }
            }
        }
}
int32_t main(){
    Faster;
    int n,e;
    cin >> n >> e;

    for(int i = 1; i <=e; i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 5;
    bfs(1);
}