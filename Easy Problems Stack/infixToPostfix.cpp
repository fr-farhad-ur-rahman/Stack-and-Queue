#include <iostream>
#include <climits>
using namespace std;

// Node class for a linked list node
template <typename T>
class Node {
public:
    T data;       // Data of the node
    Node* next;   // Pointer to the next node

    // Constructor to initialize the node with data and set next to nullptr
    Node(T data)
        : data(data), next(nullptr) {}
};

// Stack class using a linked list
template <typename T>
class Stack {
    Node<T>* head;  // Pointer to the top of the stack
    int sz;        // Size of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
        : head(nullptr), sz(0) {}

    // Function declarations
    void push(T data);  // Push data onto the stack
    T pop();            // Pop and return the top element from the stack
    T top();            // Return the top element without removing it
    bool isEmpty();     // Check if the stack is empty
    T size();           // Return the size of the stack
};

// Function implementation for checking if the stack is empty
template <typename T>
bool Stack<T>::isEmpty() {
    return (head == nullptr);
}

// Function implementation for pushing data onto the stack
template <typename T>
void Stack<T>::push(T data) {
    Node<T>* new_node = new Node<T>(data);  // Create a new node with the given data
    new_node->next = head;                   // Set the next pointer to the current top
    head = new_node;                         // Update the top to the new node
    sz++;                                    // Increment the size of the stack
}

// Function implementation for popping the top element from the stack
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) return INT_MIN;  // If the stack is empty, return a sentinel value

    Node<T>* current = head;        // Save the current top node
    T data = head->data;            // Save the data of the top node
    head = head->next;              // Update the top to the next node
    delete current;                 // Delete the old top node
    sz--;                           // Decrement the size of the stack
    return data;                    // Return the popped data
}

// Function implementation for getting the top element without removing it
template <typename T>
T Stack<T>::top() {
    if (isEmpty()) return INT_MIN;  // If the stack is empty, return a sentinel value
    return head->data;              // Return the data of the top node
}

// Function implementation for getting the size of the stack
template <typename T>
T Stack<T>::size() {
    return sz;  // Return the size of the stack
}

// Function to determine the precedence of operators
int preced(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '/' or ch == '*')
        return 2;
    else if (ch == '+' or ch == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(string str) {
    Stack<char> stack;  // Stack to store operators during conversion
    string result;      // Resulting postfix expression

    // Loop through each character in the infix expression
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // If the character is an operand, add it to the result
        if ((ch >= 'a' && ch <= 'z') or (ch >= 'A' && ch <= 'Z') or (ch >= '0') && ch <= '9') {
            result += ch;
        }

        // If the character is '(', push it onto the stack
        else if (ch == '(')
            stack.push('(');

        // If the character is ')', pop and add operators from the stack until '(' is encountered
        else if (ch == ')') {
            while (stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop();  // Pop the '(' from the stack
        }

        // If the character is an operator
        else {
            // Pop and add operators from the stack with higher or equal precedence
            while (!stack.isEmpty() && preced(ch) <= preced(stack.top())) {
                result += stack.top();
                stack.pop();
            }
            stack.push(ch);  // Push the current operator onto the stack
        }
    }

    // Pop and add any remaining operators from the stack to the result
    while (!stack.isEmpty()) {
        result += stack.top();
        stack.pop();
    }

    // Print the resulting postfix expression
    cout << result << endl;
}

int main() {
    string expression;  // Input infix expression
    cin >> expression;  // Read infix expression from user input
    infixToPostfix(expression);  // Convert and print the corresponding postfix expression

    return 0;
}
