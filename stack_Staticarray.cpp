#include<bits/stdc++.h>
using namespace std;
const int MAX = 500;

class Stack{
public:
    int a[MAX];
    int size;

    Stack(){
        size = 0;
    }
    void push(int data){
        if(size + 1 > MAX){
            cout << "Stack is full";
            return;
        }
        size++;
        a[size - 1] = data;
    }
    void pop(){
        if(size == 0){
            cout << "Empty";
            return;
        }
        a[size-1] = 0;
        size -= 1;
    }
    int top(){
        if(size == 0){
            cout << "Empty";
            return -1;
        }
        return a[size-1];
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;


    
}