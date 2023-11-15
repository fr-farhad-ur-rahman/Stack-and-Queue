#include <iostream>
using namespace std;

// Define a constant MAX with the value 1000
#define MAX 1000

// Define a class named Stack
class Stack {
    int top; // private member variable to keep track of the top of the stack

public:
    int array[MAX]; // public array to store stack elements

    // Constructor to initialize the top of the stack to -1
    Stack() {
        top = -1;
    }

    // Function to push an element onto the stack
    bool push(int x);

    // Function to pop an element from the stack
    int pop();

    // Function to get the top element of the stack without removing it
    int peek();

    // Function to check if the stack is empty
    bool isEmpty();
};

// Implementation of the push function
bool Stack::push(int x) {
    // Check if the stack is full
    if (top >= (MAX - 1)) {
        cout << "stack overflow." << endl;
        return false;
    } else {
        // Increment the top and add the element to the stack
        array[++top] = x;
        cout << x << " pushed onto the stack." << endl;
        return true;
    }
}

// Implementation of the pop function
int Stack::pop() {
    // Check if the stack is empty
    if (top < 0) {
        cout << "stack underflow." << endl;
        return 0;
    } else {
        // Get the top element, decrement the top, and return the element
        int x = array[top--];
        cout << x << " popped from the stack." << endl;
        return x;
    }
}

// Implementation of the peek function
int Stack::peek() {
    // Check if the stack is empty
    if (top < 0) {
        cout << "stack is empty." << endl;
        return 0;
    } else {
        // Return the top element without removing it
        return array[top];
    }
}

// Implementation of the isEmpty function
bool Stack::isEmpty() {
    return (top < 0);
}

// Main function
int main() {
    // Create an object of the Stack class
    class Stack st;

    // Push elements onto the stack in multiples of 10
    for (int i = 1; i <= 10; i++) {
        st.push(i * 10);
    }
    cout << endl;

    // Pop elements from the stack
    for (int i = 1; i <= 5; i++) {
        st.pop();
    }
    cout << endl;

    // Print the top element of the stack
    cout << "top is: " << st.peek() << endl;

    // Pop and print all elements in the stack
    while (!st.isEmpty()) {
        cout << st.peek() << " ";
        cout << endl;
        st.pop();
    }

    return 0;
}
