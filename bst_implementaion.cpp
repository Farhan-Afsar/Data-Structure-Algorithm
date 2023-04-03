#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
};

class BST{
    public:
    Node * root;

    BST(){
        root = NULL;
    }

    Node* create(int data){
        Node * newNode = new Node;
        newNode -> data = data;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    void insert(int data){
        Node * newNode = create(data);

        if(root == NULL){
            root = newNode;
            return;
        }

        Node * cur = root;
        Node * prv = NULL;

        while(cur != NULL){
            if(newNode -> data > cur -> data){
                prv = cur;
                cur = cur -> right;
            }
            else{
                prv = cur;
                cur = cur -> left;
            }
        }
        if(newNode -> data > prv -> data){
            prv -> right = newNode;
        }
        else{
            prv -> left = newNode;
        }
    }
    bool search(int data){
        Node * temp = root;

        while(temp != NULL){
            if(data > temp -> data){
                temp = temp -> right;
            }
            else if(data < temp -> data){
                temp = temp -> left;
            }
            else{
                return true;
            }
        }
        return false;
    }
    void Delete(int data){
        Node * cur = root;
        Node * prv = NULL;

        while(cur != NULL){
            if(data  > cur -> data){
                prv = cur;
                cur = cur -> right;
            }
            else if( data < cur -> data){
                prv = cur;
                cur = cur -> left;
            }
            else
                break;
        }
        if(cur == NULL){
            cout << "Not Present";
            return;
        }
        if(cur -> left == NULL && cur -> right == NULL){
            if(prv -> left != NULL && prv -> left -> data == cur -> data){
                prv -> left = NULL;
            }
            else 
                prv -> right = NULL;

            delete cur;
            return;
        }
        if(cur -> left == NULL && cur -> right != NULL){
            if(prv -> left != NULL && prv -> left -> data == cur -> data){
                prv -> left = cur -> right ;
            }
            else 
                prv -> right = cur -> right;

            delete cur;
            return;
        }
        if(cur -> left != NULL && cur -> right != NULL){
            if(prv -> left != NULL && prv -> left -> data == cur -> data){
                prv -> left = cur -> left ;
            }
            else 
                prv -> right = cur -> left;

            delete cur;
            return;
        }

        Node * temp = cur -> right;

        while(temp -> left != NULL){
            temp = temp -> left;
        }
        int save = temp -> data;
        Delete(save);
        cur -> data = save;

    }
};

int main(){
    
    
}