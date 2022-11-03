#include <iostream>
#include "lstack.h"
#include "arrstack.h"
#include <string>
#include <assert.h>

void toPostfix(std::string);
bool isOperand(char);
bool isOperator(char);
int pr(char);
void test();
bool isValid(std::string);

int main()
{
    test();
    std::string s1;
    std::cout << "\n\nEnter the parenthesis: ";
    std::cin >> s1;
    bool res = isValid(s1);
    std::cout << "Valid = " << res;

    std::string infix;
    std::cout << "\n\nEnter the expression:" << std::endl;
    std::cin >> infix;
    toPostfix(infix);

    return 0;
}

void test() {
    // Below is the test for LStack class
    LStack<int> s1;
    s1.push(2);
    s1.push(7);
    s1.push(4);
    int myTop = s1.top();
    std::cout << "My top element is: " << myTop << std::endl;
    s1.pop();
    bool flag = s1.empty();
    std::cout << "Stack is empty = " << flag << std::endl;
    s1.print();
    std::cout << '\n';

    // Below is the test for the ArrStack class
    ArrStack<char> s2(7);
    s2.push('a');
    s2.push('b');
    s2.push('c');
    std::cout << "Top: " << s2.top() << " " << std::endl;
    s2.pop();
    std::cout<<"Empty = "<<s2.empty() << std::endl;
    s2.print();
    s2.clear();
    return;
}

bool isValid(std::string s) {
    LStack<char> st;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
        else if (s[i] == '}') {
            if (st.empty() || st.top() != '{') {
                return false;
            }
            st.pop();
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        }
        else {
            return false;
        }
    }
    return st.empty();
}

void toPostfix(std::string infix) {
    LStack<char> st1;
    for (int i = 0; i < infix.size(); ++i) {
        if (infix[i] == '(') {
            st1.push(infix[i]);
        }
        else if (isOperand(infix[i])) {
            std::cout << infix[i];
        }
        else if (isOperator(infix[i])) {
            while (!st1.empty() && isOperator(st1.top()) && (pr(st1.top()) >= pr(infix[i]))) {
                std::cout << st1.top();
                st1.pop();
            }
            st1.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!st1.empty() && st1.top() != '(') {
                std::cout << st1.top();
                st1.pop();
            }
            if (st1.empty()) {
                std::cout << "Invalid input!" << std::endl;
            }
            else {
                st1.pop();
            }
        }
        else {
            std::cout << "Invalid input!" << std::endl;
        }
    }
    while (!st1.empty()) {
        std::cout << st1.top();
        st1.pop();
    }

}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isOperator(char c){
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^');
}

int pr(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        assert(false);
        return 0;
    }
}