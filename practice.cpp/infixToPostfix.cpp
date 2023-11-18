#include <iostream>
#include <stack>
using namespace std;

int preced(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' or ch == '/') return 2;
    else if(ch == '+' or ch == '-') return 1;
    else return -1;
}

void infixToPostfix(string s){
    stack <char> st;
    string result;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if((ch >= 'a' && ch <= 'z') or (ch >= 'A' && ch <= 'Z') or (ch >= '0' && ch <= '9')){
            result += ch;
        }

        else if(ch == '(') {
            st.push(ch);
        }
        
        else if(ch == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        
        else{
            while(!st.empty() && preced(ch) <= preced(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main(){
    string expression; 
    cin >> expression;   

    infixToPostfix(expression);

    return 0;
}