#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack{
public:
    T *a;
    int size;
    int array_cap;
    Stack(){
        a = new T[1];
        size = 0;
        array_cap = 1;
    }
    void increase_size(){
          T * temp;
          temp = new T [array_cap * 2];
          for(int i = 0; i < array_cap; i++){
            temp[i] = a[i];
          }
          swap(a,temp);
          delete []temp;
          array_cap *= 2;  
    }
    void push(T data){
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
        size -= 1;
    }
    T top(){
        if(size == 0){
            cout << "Empty";
            assert(false);
        }
        return a[size-1];
    }
};

int main(){
    Stack<float> s;
    s.push(1.4);
    s.push(2.9);
    s.push(3.0);
    s.push(4.8);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    
}