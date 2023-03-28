#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int *a;
    int size;
    int array_cap;
    Stack(){
        a = new int[1];
        size = 0;
        array_cap = 1;
    }
    void increase_size(){
          int * temp;
          temp = new int [array_cap * 2];
          for(int i = 0; i < array_cap; i++){
            temp[i] = a[i];
          }
          swap(a,temp);
          delete []temp;
          array_cap *= 2;  
    }
    void push(int data){
        if(size + 1 > array_cap){
            increase_size();
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