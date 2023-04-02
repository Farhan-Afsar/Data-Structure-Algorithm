#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    queue<string> a;
    a.push("1");

    for(int i = 1; i <= n; i++){
        cout<< "Binary Representation of " << i << ": " << a.front() << endl;  
        string temp = a.front();
        a.pop();
        a.push(temp + "0");
        a.push(temp + "1");
    }
}