#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch);
string reverse(string s);
void infixToPrefix(string str);

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' or ch == '/') return 2;
    else if(ch == '+' or ch == '-') return 1;
    else return -1;
}

string reverse(string s){
    // declare stack
    stack <char> stck;

    // pusing into stack.
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        stck.push(ch);
    }

    string rev;
    // popping from stack
    while(not stck.empty()){
        rev += stck.top();
        stck.pop();
    }
    return rev;
}

void infixToPrefix(string str){
    stack <char> stck;

    str = reverse(str);

    string result;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if((ch >= 'A' && ch <= 'Z') or (ch >= 'a' && ch <= 'z') or (ch >= '0' && ch <= '9')){
            result += ch;
        }

        else if(ch == '(')
            stck.push('(');

        else if(ch == ')'){
            while(stck.top() != '('){
                result += stck.top();
                stck.pop();
            }
            stck.pop();
        }
        
        else{
            while(not stck.empty() && precedence(ch) <= precedence(stck.top())){
                result += stck.top();
                stck.pop();
            }
            stck.push(ch);
        }
    }

    while(not stck.empty()){
        result += stck.top();
        stck.pop();
    }
    
    result = reverse(result);

    cout << result << endl;
}

int main(){
    cout << "Enter expression: " << endl;

    string expression; 
    cin >> expression;
    
    infixToPrefix(expression);
    return 0;
}

