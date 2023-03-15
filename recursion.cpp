#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int sum(int n){
    if (n == 1)
        return 1;

    return sum(n-1)+n;
}

bool is_palindrome(string str){
    int n = str.size();
    int l = 0, r = n-1;

    while(l < r){
        if (str[l] != str[r])
            return false;
        
        l++;
        r--;
    }
    return true;
}
int32_t main(){
    Faster;
    int n;
    cin >> n;

    string s = "madam";
    cout << sum(n) << endl;
    cout << is_palindrome(s) << endl;
}