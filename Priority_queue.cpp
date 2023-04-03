#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    vector<int> nodes;

    MaxHeap(){

    }
    void up_heapify(int indx){
        while(indx > 0 && nodes[indx] > nodes[(indx - 1)/2]){
            swap(nodes[indx], nodes[(indx - 1)/2]);
            indx = (indx - 1)/2;
        }
    }
    void insert(int data){
        nodes.push_back(data);
        up_heapify(nodes.size()-1);
    }
    void print(){
        for(auto it : nodes)
            cout << it << " ";
    }
    void down_heapify(int indx){
        while(1){
            int largest = indx;
            int l = 2 * indx +1;
            int r = 2 * indx + 2;

            if(l < nodes.size() && nodes[largest] < nodes[l])
                largest = l;
            if(r < nodes.size() && nodes[largest] < nodes[r])
                largest = r;
            if(largest == indx)
                break;
            swap(nodes[indx], nodes[largest]);
            indx = largest;
        }
    }

    void Delete(int indx){
        if(indx >= nodes.size())
            return;
        swap(nodes[indx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(indx);
    }
    int  getMax(){
        if(nodes.empty())
            return -1;
        return nodes[0];
    }
    void build_from_array(vector <int > &a){
        nodes = a;
        int n = nodes.size();
        int leaf = n/2 - 1;

        for(int i = leaf ; i >= 0; i--){
            down_heapify(i);
        }
    }
    int ExtractMax(){
        int res = nodes[0];
        Delete(0);
        return res;
    }
    int size(){
        return nodes.size();
    }
    
};

class PriorityQueue{
    public:
    MaxHeap h;
    PriorityQueue(){

    }
    void push(int x){
        h.insert(x);
    }
    void pop(){
        h.Delete(0);
    }
    int top(){
        return h.getMax();
    }
    int size(){
        return h.size();
    }
};


int main(){
       PriorityQueue p;
       p.push(5);
       p.push(1);
       p.push(9);
       p.push(0);
       p.push(7);

       while(p.size() != 0){
        cout << p.top() << " ";
        p.pop();
       }
}