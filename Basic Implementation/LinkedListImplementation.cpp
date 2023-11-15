#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data)
        : data(data), next(nullptr) {}
};

class Stack{
public:
    Node *head = nullptr;

    bool isEmpty();
    void push(int data);
    int pop();
    int peek();
};

bool Stack::isEmpty(){
    return head == nullptr;
}

void Stack::push(int data){
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
    cout << data << " pushed into the stack.\n"
         << endl;
}

int Stack::pop(){
    if (isEmpty()){
        return INT_MIN;
    }
    Node *current = head;
    head = head->next;
    int data = current->data;
    delete current;
    return data;
}

int Stack::peek(){
    if (isEmpty())
    {
        return INT_MIN;
    }
    return head->data;
}

int main(){
    class Stack st;

    for(int i = 1; i <= 10; i++){
        st.push(i * 10);
    }

    cout << "top element is: " << st.peek() << endl;

    for(int i = 1; i <= 5; i++){
        st.pop();
    }

    cout << "top element is: " << st.peek() << "\n\n";

    cout << "stack elements are: " << "\n";
    while(! st.isEmpty()){
        cout << st.peek() << " ";
        st.pop();
    }
    return 0;
}
