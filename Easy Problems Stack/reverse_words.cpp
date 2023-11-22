#include <iostream>
#include <stack>

using namespace std;

const int maxSize = 100;

int main(){
    string words[maxSize];

    int numWords;
    cout << "Enter the number of words (up to "  << maxSize << "): ";
    cin >> numWords;

    if(numWords > maxSize){
        cout << "Error: number of words exceeds maximum size. " << endl;
        return 0;
    }
    
    cout << "Enter your sentence: " << endl;
    for(int i = 0; i < numWords; i++){
        cin >> words[i];
    }

    stack <string> st;

    string result;
    for(int i = 0; i < numWords; i++){
        st.push(words[i]);
    }

    for(int i = 0; i < numWords; i++){
        result += st.top();
        result += " ";
        st.pop();
    }

    cout << result << endl;
    return 0;
}
