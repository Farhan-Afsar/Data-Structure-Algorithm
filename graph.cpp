#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int32_t main(){
    Faster;
    int node = 4;

    int matrix[node][node] = {};

    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    vector<int> adj_list[node];

    adj_list[0] = {1};
    adj_list[1] = {0,2,3};
    adj_list[2] = {1,3};
    adj_list[3] = {1,2};

    for(int i = 0; i < node; i++){
        cout << i << " -> ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}