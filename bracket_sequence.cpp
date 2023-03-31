#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;

    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char current = s[i];
        if(current == '(' || current == '{' || current == '['){
            st.push(current);
        }
        else{
            if(st.empty()){
                cout << "Invalid";
                return 0;
            }
            if(current == ')' && st.top() == '('){
                st.pop();
            }
            else if(current == '}' && st.top() == '{'){
                st.pop();
            }
            else if(current == ']' && st.top() == '['){
                st.pop();
            }
            else{
                cout << "Invalid";
                return 0;
            }
        }
    }
    if(st.empty()){
        cout << "Valid";
    }
    else{
        cout << "Invalid";
    }
    
}