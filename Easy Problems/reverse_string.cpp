#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <char> st;

    cout << "Enter string: " << endl;
    string s; 
    getline(cin, s);

    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }

    string rev;
    for(int i = 0; i < s.length(); i++){
        rev += st.top();
        st.pop();
    }

    cout << rev << endl;

    return 0;
}