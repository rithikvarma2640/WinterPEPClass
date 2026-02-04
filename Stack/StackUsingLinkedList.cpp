#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        next = NULL;
    }

};

class StackUsingLinkedList{
    Node* head; // head = top
    int counter;

    public:
    // default constructor
    StackUsingLinkedList(){
        head = NULL;
        counter = 0;
    }

    //push function
    void push(int element){
        Node* newNode = new Node(element);
       // head -> next = newNode; // X
       newNode -> next = head;
       head = newNode;
       counter++;
    }

    // pop - returns the value
    int pop(){
        if(head == NULL){
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        // take the val
        int val = head -> data;
        Node* temp = head;
        head = head -> next;
        delete temp;
        counter--;
        return val;
    }

    int top(){
        // check if stack is empty
        // if you have empty Linked List
        if(head == NULL){
            cout << "Stack is empty\n"; 
            return -1;
        }
        return head -> data;
    }
    int size(){
        return counter;
    }
    bool isEmpty(){
        // if(head == NULL){
        //     return true;
        // }else{
        //     return false;
        // }
        return head == NULL;
    }


};
int main(){
    StackUsingLinkedList st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int top = st.top();
    cout << "top: " << top << endl;

    // print the stack
    cout << "Printing stack elements: " << endl;
    while(!st.isEmpty()){
        int top = st.top();
        int popped = st.pop();
        cout << top << endl;
    }
}