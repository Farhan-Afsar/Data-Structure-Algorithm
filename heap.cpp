#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class MinHeap{
    public:
        vector<int> nodes;
        
        MinHeap(){

        }
        void up_heapify(){
            int curr_indx = nodes.size()-1;
            int comp_indx = (curr_indx - 1)/2;

            while(curr_indx >= 0 and comp_indx >= 0 and nodes[curr_indx] < nodes[comp_indx]){
                swap(nodes[curr_indx], nodes[comp_indx]);
                curr_indx = comp_indx;
                comp_indx = (curr_indx - 1)/2;
            }
        }
        void insert(int val){
            nodes.push_back(val);
            up_heapify();
        }
        void display(){
            for(auto it : nodes){
                cout << it << " ";
            }
        }
};
int32_t main(){
    Faster;
    MinHeap mh;
    mh.insert(7); 
    mh.insert(5);
    mh.insert(9);
    mh.insert(10);
    mh.insert(4);
    mh.insert(3);
    mh.insert(2);
    mh.insert(1);

    mh.display();


}