#include <bits/stdc++.h>
using namespace std;

// Define a class 'Node' to represent a node in the linked list
class Node{
public:
    int data;     // Data stored in the node
    Node *next;    // Pointer to the next node in the linked list

    // Constructor to initialize data and next pointer
    Node(int data)
        : data(data), next(nullptr) {}
};

// Define a class 'Stack' to implement a stack using linked list
class Stack{
public:
    Node *head = nullptr;    // Pointer to the top of the stack

    // Function to check if the stack is empty
    bool isEmpty();
    
    // Function to push a new element onto the stack
    void push(int data);
    
    // Function to pop the top element from the stack
    int pop();
    
    // Function to get the value of the top element without removing it
    int peek();
};

// Implementation of the 'isEmpty' function
bool Stack::isEmpty(){
    // Check if the head pointer is pointing to null (indicating an empty stack)
    return head == nullptr;
}

// Implementation of the 'push' function
void Stack::push(int data){
    // Create a new node with the given data
    Node *new_node = new Node(data);
    
    // Set the 'next' pointer of the new node to the current top of the stack
    new_node->next = head;
    
    // Update the head pointer to the new node, making it the new top of the stack
    head = new_node;
    
    // Print a message indicating the successful push operation
    cout << data << " pushed into the stack.\n" << endl;
}

// Implementation of the 'pop' function
int Stack::pop(){
    // Check if the stack is empty
    if (isEmpty()){
        // If the stack is empty, return a special value (INT_MIN) indicating an underflow
        return INT_MIN;
    }
    
    // Store the current top of the stack
    Node *current = head;
    
    // Update the head pointer to the next node, removing the current top of the stack
    head = head->next;
    
    // Retrieve the data from the removed node
    int data = current->data;
    
    // Deallocate the memory of the removed node
    delete current;
    
    // Return the data of the removed node
    return data;
}

// Implementation of the 'peek' function
int Stack::peek(){
    // Check if the stack is empty
    if (isEmpty()){
        // If the stack is empty, return a special value (INT_MIN) indicating an underflow
        return INT_MIN;
    }
    
    // Return the data of the top element without removing it
    return head->data;
}

// Main function to test the stack implementation
int main(){
    // Create an instance of the 'Stack' class
    class Stack st;

    // Push elements onto the stack (multiples of 10 from 10 to 100)
    for(int i = 1; i <= 10; i++){
        st.push(i * 10);
    }

    // Display the top element of the stack
    cout << "top element is: " << st.peek() << endl;

    // Pop elements from the stack (remove the top 5 elements)
    for(int i = 1; i <= 5; i++){
        st.pop();
    }

    // Display the top element of the stack after popping
    cout << "top element is: " << st.peek();

    // Display all remaining elements in the stack using a loop
    while(!st.isEmpty()){
        cout << st.peek() << " ";
        st.pop();
    }

    return 0;
}
