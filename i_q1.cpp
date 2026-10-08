#include <bits/stdc++.h>
using namespace std;

string removeInvalid(string s) {
    string temp = "";
    int open = 0;

    for (char c : s) {
        if (c == '(') {
            open++;
            temp += c;
        }
        else if (c == ')') {
            if (open > 0) {  
                open--;
                temp += c;
            }
        }
        else {
            temp += c;    
        }
    }

    string result = "";
    int close = 0;

    for (int i = temp.size() - 1; i >= 0; i--) {
        if (temp[i] == ')') {
            close++;
            result += ')';
        }
        else if (temp[i] == '(') {
            if (close > 0) {  
                close--;
                result += '(';
            }
        }
        else {
            result += temp[i];
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s;
    getline(cin, s);

    cout << removeInvalid(s);
}
