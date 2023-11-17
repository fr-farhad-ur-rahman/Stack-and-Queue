#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data)
        :data(data), next(nullptr){}
};

class Stack{
public:
    Node* head = nullptr;

    int sz = 0;
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};

bool Stack::isEmpty(){
    return head == nullptr;
}

void Stack::push(int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
    sz++;
}

int Stack::pop(){
    if(isEmpty()){
        return INT_MIN;
    }

    Node* current = head;
    int data = current -> data;
    head = head -> next;
    sz--;
    delete current;
    return data;
}

int Stack::peek(){
    if(isEmpty()){
        return INT_MIN;
    }
    return head -> data;
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
    st.push(25);

    cout << st.size() << endl;

    cout << st.pop() << endl;

    while(! st.isEmpty()){
        cout << st.peek() << endl;
        st.pop();
    }
    
    return 0;
}
