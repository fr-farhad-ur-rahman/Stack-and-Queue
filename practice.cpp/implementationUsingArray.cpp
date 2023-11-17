#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
    int top = -1;

public: 
    Stack(){
        top = -1;
    }
    int stck[MAX];
    int sz = 0;

    bool push(int data);
    void pop();
    int peek();
    bool isEmpty();
    int size();
};

bool Stack::push(int data){
    if(top == MAX - 1){
        cout << "Stack overflow." << endl;
        return false;
    }
    stck[++top] = data;
    sz++;
    cout << data << " pushed in the stack." << endl;
    return true;
}

void Stack::pop(){
    if(top < 0){
        cout << "stack underflow" << endl;
        return;
    }
    stck[top--];
    sz--;
}

int Stack::peek(){
    if(top < 0){
        cout << "stack underflow" << endl;
    }
    int data = stck[top];
    return data;
}

bool Stack::isEmpty(){
    return (top < 0);
}

int Stack::size(){
    return sz;
}

int main(){
    class Stack st;

    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);

    cout << st.size() << endl;

    st.pop();
    cout << st.size() << endl;

    cout << "stack data are: " << endl;
    while(! st.isEmpty()){
        cout << st.peek() << endl;
        st.pop();

    }
    return 0;
}
