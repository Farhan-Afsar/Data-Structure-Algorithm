#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * next; 
    
    Node(int data){
        this -> data = data;
        this-> next = NULL;
    }
};

class linked_list{
    public:
    Node * head;
    int size;

    linked_list(){
        head = NULL;
        size = 0;
    }

    void insetHead(int data){
        size++;
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }

    void traverse(){
        Node * temp = head;

        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    int searchDistinctValue(int data){
        Node * temp = head;
        int index = 0;

        while(temp != NULL){
            if(temp -> data == data){
                    return index;
            }
            temp = temp -> next;
            index++;
        }
        return -1;
    }
    int getSize(){
    //     int size = 0;
    //     Node * temp = head;
    //     while(temp != NULL){      //O(n)
    //         size++;
    //         temp = temp -> next;
    //     }
    //     return size;
    // }
    return size;
    }
    void insertIndex(int data,int index){
        if(index < 0 || index > size){
            return;
        }
        size++;
        Node * newNode = new Node(data);
        if(index == 0){
            insetHead(data);
            return;
        }
        Node * temp = head;
        int cur_indx = 0;

        while(cur_indx != index - 1 ){
            temp = temp -> next;
            cur_indx++;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    void deleteHead(){
        if(head == NULL)
            return;
        size--;
        Node * temp = head;
        head = temp -> next;

        delete temp;
    }
    void deleteAnyIndex(int index){
        if(index < 0 || index > size - 1){
            return;
        }
        size--;
        if(index == 0){
            deleteHead();
            return;
        }
        Node * temp = head;
        int cur_indx = 0;

        while(cur_indx != index - 1 ){
            temp = temp -> next;
            cur_indx++;
        }
        Node * newNode = temp -> next;
        temp -> next = newNode -> next;

        delete newNode;
    }
    void insertAfterValue(int data,int value){
        Node * newNode = new Node(data);
        Node * temp = head;

        while(temp != NULL){
            if(temp ->data == value)
                break;
            temp = temp->next;
        }
        if(temp == NULL){
            cout <<"Doesn't exist";
            return;
        }
        size++;
        newNode ->next = temp -> next;
        temp -> next = newNode;
    }
    void Reverse(Node * head){
        if(head == NULL){
            return;
        }
        Reverse(head -> next);
        cout << head -> data << " ";
    }
    void reverse(){
        Reverse(head);
        cout << endl;
    }
};
int main(){
    linked_list l;

    l.insetHead(10);
    l.insetHead(20);
    l.insetHead(30);
    l.insetHead(40);
    l.insetHead(59);
    
    // cout << l.getSize();
    l.insertIndex(100,1);
    l.deleteHead();
    l.traverse();
    cout << endl;
    l.deleteAnyIndex(2);
    l.traverse();
    l.insertAfterValue(100,10);
    cout << endl;
    l.traverse();
    cout << endl;
    l.reverse();
    l.traverse();
}