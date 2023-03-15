#include <bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int id;

//    Student(){
//
//    }
    Student(string name, int id){
        this->name = name;
        this->id = id;
    }

    void print(){
        cout << name << " " << id << " "<< endl;

    }

};

bool comp(Student a , Student b){
    if (a.id < b.id)
        return true;
    else
        return false;
}

class Array{
private:
    int* arr;
    int capacity;
    int size;

    void increase_capacity(){
        capacity *= 2;
        int* temp = new int [capacity];
        for(int i = 0; i < size; i++ ){
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }

public:
    Array(){
        arr = new int[1];
        capacity = 1;
        size = 0;
    }
    void push(int x){
        if(capacity == size){
            increase_capacity();
        }
        arr[size] = x;
        size ++;
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
    }
};

void bubble_sort(int n,vector<int> &a){
        for(int i = 0; i < n; i++){
            bool sort = true;
            for(int j = 0; j < n-1-i; j++){
                if(a[j] > a[j+1]){
                    swap(a[j],a[j+1]);
                    sort = false;
                }
            }
            if(sort)
                break;
        }

        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
}
void insertion_sort(int n,vector<int> &a){
    for(int i = 1; i < n; i++){
        int indx = i;
        while(indx >= 1){
            if(a[indx-1] > a[indx]){
                swap(a[indx-1],a[indx]);
            }
            else
                break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

void sieve(int n){
    vector<int> prime;
    vector<bool> visited(n+1);

    for(int i = 2; i <= n; i++){
        if(!visited[i]) {
            prime.push_back(i);
            for (int j = 2; i * j <= n; j++) {
                visited[j * i] = true;
            }
        }
    }
    for(auto it : prime){
        cout << it << " ";
    }
}

int main() {

//    vector<Student> a;
//
//    for(int i = 0; i < 10; i++){
//        a[i] = a.emplace_back("A",20-i);
//    }
//
//    for(int i = 0; i < 10; i++){
//        a[i].print();
//    }
//
//    sort(a.begin(),a.end(),comp);
//
//    cout << "After sort: " << endl;
//
//    for(int i = 0; i < 10; i++){
//        a[i].print();
//    }

//Array a;
//for(int i = 0; i < 10 ; i++){
//    a.push(i);
//}
//a.print();

int n,m;
cin >> n >> m;
vector<int> a(n);
for(int i = 0; i < n;i++){
    cin >> a[i];
}
    bubble_sort(n,a);
    cout << "\n";
    insertion_sort(n,a);
    cout << "\n";
    sieve(m);
}
