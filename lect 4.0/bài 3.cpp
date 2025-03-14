#include <iostream>

using namespace std;

class Stack {
private:
    char data[1000];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) {
        if (top < 999) {
            top++;
            stack[top] = c;
        }
    }
    void pop() {
        if (top >= 0) {
            top--;
        }
    }
    char peek() {
        return (top == -1) ? '\0' : stack[top];
    }
    bool empty() {
        return top == -1;
    }
private:
    char stack[1000];
    int top;
};

bool isValid(string s) {
    Stack st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.peek() == '\0') return false;
            char top = st.peek();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.peek() == '\0';
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}