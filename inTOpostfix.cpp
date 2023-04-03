#include<bits/stdc++.h>
using namespace std;

int pres(char ch){
    if(ch == '+' || ch == '-')
        return 0;
    else if(ch == '*' || ch == '/')
        return 1;
    
    return -1;
    
}
int main(){
    string s,ans;
    cin >> s;

    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char current = s[i];

        if(current >= 'a' && current <= 'z'){
            ans += current; 
        }
        else if(current == '('){
            st.push(current);
        }
        else if(current == ')'){
            while(st.size() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(st.size() && pres(st.top()) >= pres(current)){
                ans += st.top();
                st.pop();
            }
            st.push(current);
        }
    }
    while(st.size()){
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}