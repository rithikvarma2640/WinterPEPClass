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
    Node* head;
    int counter;

    // constructor
    public:
    StackUsingLinkedList(){
        head = NULL;
        counter = 0;
    }

    // push function
    void push(int element){
        // create the new Node with the element as data
        Node* newNode = new Node(element);
        newNode -> next = head;
        head = newNode;
        counter++;
    }

    // pop function
    int pop(){
        if(head == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int value = head -> data;
        Node* temp = head;
        head = temp -> next;
        delete temp;
        return value;
    }

    // top
    int top(){
        if(head == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }else{
            return head -> data;
        }
    }

    int size(){
        return counter;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    StackUsingLinkedList st;
    int top = st.top();
    int popped = st.pop();
    cout << "Pop: " << popped << endl;
    cout << "top: " << top << endl;

    for(int i = 0; i < 5; ++i){
        int data;
        cout << "Enter stack element: " << endl;
        cin >> data;
        st.push(data);
    }

    while(!st.isEmpty()){
        cout << st.top() << endl;
        cout << "Popped: " << st.pop() << endl;
    }

}
