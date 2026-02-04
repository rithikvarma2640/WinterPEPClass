#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int* data; // pointer to an int array on heap
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    // size function
    int size(){
        return nextIndex;
    }
    int top(){
        // if stack is empty
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return INT_MIN; // indicates no top exist
        }
        return data[nextIndex - 1];
    }
    bool isEmpty(){
        // if(nextIndex == 0) return true;
        // else return false;
        return nextIndex == 0;
    }

    void push(int element){
        if(nextIndex == capacity){
            int* newData = new int[2 *capacity];
            // copy older array into this new array
            for(int i = 0; i < capacity; ++i){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
            cout << "Stack full!" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    //pop
    int pop(){
        // top element should be removed and nextIndex decrements by 1
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }
};

int main(){
    StackUsingArray st;
    st.push(10);
    st.push(20);
    st.push(30);
    int topElem = st.top();
    cout << "top: " << topElem << endl;

    // printing the stack elements until stack 
    // becomes empty
    while(!st.isEmpty()){
        int val = st.top();
        int deleteElem = st.pop();
        cout << val << endl;
    }
    int size = st.size();
    cout << "size: " << size << endl;

    // isEmpty()
    if(st.isEmpty()){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}