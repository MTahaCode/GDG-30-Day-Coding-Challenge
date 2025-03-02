#include <bits/stdc++.h>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    std::stack<char> Stack;
    for (char curr : s) {
        if (curr == '(' || curr == '{' || curr == '[') {
            Stack.push(curr);
            continue;
        }
        if (Stack.empty()) {
            return "NO";
        }
        char top = Stack.top();
        Stack.pop();
        if (!((top == '(' && curr == ')') || (top == '{' && curr == '}') || (top == '[' && curr == ']'))) {
            return "NO";
        }
    }
    if (Stack.empty()) {
        return "NO";
    }
    return "YES";
}

int main() {
    std::cout << isBalanced("{[()]}") << std::endl;
    std::cout << isBalanced("{[(])}") << std::endl;
    std::cout << isBalanced("{{[[(())]]}}") << std::endl;
}