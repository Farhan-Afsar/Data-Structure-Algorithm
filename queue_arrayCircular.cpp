#include<bits/stdc++.h>
using namespace std;

const int MAX = 500;

class Queue{
    public:
    int a[MAX];
    int l,r,size;

    Queue(){
        l = 0;
        r = -1;
        size = 0;
    }
    void enqueue(int data){
       if(size == MAX){
        cout << "Full";
        return;
       }
        r++;
        if(r == MAX ){
            r = 0;
        }
        a[r] = data;
        size++;
    }
    void dequeue(){
        if(size == 0){
            cout << "Empty";
            return;
        }
        l++; 
        if(l == MAX){
            l = 0;
        }  
        size--;
    }
    int front(){
        if(size == 0){
            cout << "Empty";
            return -1;
        }
        return a[l];
    }
    int getSize(){
        return size;
    }

};

int main(){
    Queue a;

    a.enqueue(5);
    a.enqueue(10);
    a.enqueue(15);

    cout << a.getSize() << endl; 
    a.dequeue();
    cout << a.front() << endl;
    a.dequeue();
    cout << a.front() << endl;
    a.dequeue();
    cout << a.front() << endl;
    cout << a.getSize() << endl;
    
}