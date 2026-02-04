#include <iostream>
#include <stack>
using namespace std;

class MinStack{
    stack<int> st;
    stack<int> minSt;

    public:
    MinStack(){
        // cout << "Default Constructor"
    }
   
    // push function
    void push(int element){
        st.push(element);

        // push to the min stack if minStack is empty or top of the minStack is < val
        if(minSt.size() == 0 || element <= minSt.top()){
            minSt.push(element);
        }else{
            return;
        }
    }

    void pop(){
        if(st.empty()) return;

        int popped_elem = st.top(); // you remove it from the top
        st.pop();
        if(!minSt.empty() && popped_elem == minSt.top()){
            minSt.pop();
        }
    }

    int top(){
        if(st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return st.top();
    }

    int getMin(){
        if(minSt.empty()) return -1;
        return minSt.top();
    }

    bool isEmpty(){
        return st.empty();
    }
};

int main(){
    MinStack minSt;
    for(int i = 0; i < 5; ++i){
        int data;
        cout << "Enter data in stack: " << endl;
        cin >> data;
        minSt.push(data);
    }

    while(!minSt.isEmpty()){
        cout << "min: " << minSt.getMin() << endl;
        minSt.pop();
    }

    // cout << minSt.getMin() << endl;
    // minSt.pop();
    // cout << minSt.getMin() << endl;
    // minSt.pop();
    // cout << minSt.getMin() << endl;
    // minSt.pop();
    // cout << minSt.getMin() << endl;

}