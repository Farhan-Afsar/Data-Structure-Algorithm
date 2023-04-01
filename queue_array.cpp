#include<bits/stdc++.h>
using namespace std;

const int MAX = 500;

class Queue{
    public:
    int a[MAX];
    int l,r;

    Queue(){
        l = 0;
        r = -1;
    }
    void enqueue(int data){
        if(r+1 > MAX){
            cout << "Full";
            return;
        }
        r++;
        a[r] = data;
    }
    void dequeue(){
        if(l > r){
            cout << "Empty";
            return;
        }
        l++; 
    }
    int front(){
        if(l > r){
            cout << "Empty";
            return -1;
        }
        return a[l];
    }
    int getSize(){
        return r-l+1;
    }

};

int main(){
    Queue a;

    a.enqueue(5);
    a.enqueue(10);
    a.enqueue(15);

    cout << a.getSize() << endl; 
    a.dequeue();
    cout << a.front();
    
}