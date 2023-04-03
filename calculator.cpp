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
    string str,ans;
    cin >> str;

    stack<char> st;

    for(int i = 0; i < str.size(); i++){
        char current = str[i];

        if(current >= '0' && current <= '9'){
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
    stack<int > s;

    for(int i = 0; i < ans.size(); i++){
        if(ans[i] >= '0' && ans[i] <= '9'){
            s.push(ans[i] - '0');
        }
        else{
            int oprnd2 = s.top();
            s.pop();
            int oprnd1 = s.top();
            s.pop();

            if(ans[i] == '+'){
                s.push(oprnd1 + oprnd2);
            }
            else if(ans[i] == '-'){
                s.push(oprnd1 - oprnd2);
            }
            else if(ans[i] == '*'){
                s.push(oprnd1 * oprnd2);
            }
            else if(ans[i] == '/'){
                s.push(oprnd1 / oprnd2);
            }
        }
    }
    cout << s.top() << endl;
}