#include<bits/stdc++.h>
using namespace std;


class Queue{
    public:
    int *a;
    int l,r,size,capacity;

    Queue(){
        a = new int [1];
        capacity = 1;
        l = 0;
        r = -1;
        size = 0;
    }
    void remove_circular(){
        if(l > r){
            int *temp = new int[capacity];
            int indx = 0;
            for(int i = l; i < capacity; i++){
                temp[indx] = a[i];
                indx++;
            }
            for(int i = 0; i <= r; i++){
                temp[indx] = a[i];
                indx++;
            }
            swap(temp,a);
            l = 0;
            r = capacity -1;
            delete [] temp;
        }
        
    }
    void increase_size(){
        remove_circular();
        int * temp = new int[capacity*2];
        for(int i = 0; i < capacity; i++){
            temp[i] = a[i];
        }
        swap(a,temp);
        capacity *= 2;
        delete [] temp;

    }
    void enqueue(int data){
       if(size == capacity){
        increase_size();
       }
        r++;
        if(r == capacity ){
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
        if(l == capacity){
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