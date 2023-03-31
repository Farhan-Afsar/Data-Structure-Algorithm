#include<bits/stdc++.h>
using namespace std;

void print(list<int> l){
    // list<int> :: iterator a = l.begin();
    auto a = l.begin();

    while(a != l.end()){
        cout << *a << " ";
        a++;
    }
}
int main(){
    list<int> l;
    l.push_front(10);
    l.push_back(5);
    l.push_back(47);
    l.push_back(70);
    l.pop_front();
    auto it = l.begin();
    advance(it,1);
    l.insert(it,100);
    print(l);
    l.erase(it);
    cout << endl;
    print(l);
}