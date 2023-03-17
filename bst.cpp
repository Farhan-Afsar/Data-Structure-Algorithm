#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
    public:
        int data;
        Node * left;
        Node * right;

        Node(int data){
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

class BST{
    public:
        Node * root;

        BST(){
            root = NULL;
        }

        void insert(int data){
            Node * newNode = new Node(data);
            if(root == NULL){
                root = newNode;
                return;
            }
            Node * temp  = root;
            Node * prev = NULL;

            while(temp != NULL){
                prev = temp;

                if(data > temp -> data){
                    temp = temp -> right;
                }
                else{
                    temp = temp -> left;
                }
            }
            if(data > prev -> data){
                prev -> right = newNode;
            }
            else{
                prev -> left = newNode;
            }
        }
};
int32_t main(){
    Faster;
    BST a;
    a.insert(5);
    a.insert(10);
    a.insert(12);
    a.insert(2);

    cout << a.root->right->right->data;   
}