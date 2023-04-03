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
    
};

vector<int> heap_sort(vector<int> a){
        MaxHeap h;
        h.build_from_array(a);
        vector<int> ans;
        for(int i = 0; i < a.size(); i++)
            ans.push_back(h.ExtractMax());

        reverse(ans.begin(),ans.end());
        return ans;
    }

int main(){
        MaxHeap a;
        a.insert(4);
        a.insert(7);
        a.insert(9);
        a.insert(1);
        a.insert(10);

        a.print();
        cout << endl;
        a.Delete(0);
        a.print();

        vector<int> a1 = {2,3,6,8,1,3,7};
        vector<int> b = heap_sort(a1);
        cout << endl;
        for(auto it: b)
            cout << it <<" ";
}