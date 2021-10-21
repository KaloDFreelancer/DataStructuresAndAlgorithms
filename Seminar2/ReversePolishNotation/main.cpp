#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string inputStr = "12+345*-*";
    stack<int> numbersStack;
    for (char c: inputStr) {
//      if number
        if (c >= 48 && c <= 57) {
            numbersStack.push((int)c - 48); // -48 to get the int value of the char using the ascii table
        } else {
            int x1 = numbersStack.top();
            numbersStack.pop();
            int x2 = numbersStack.top();
            numbersStack.pop();
            switch (c) {
                case '+':
                    numbersStack.push(x1 + x2);
                    break;
                case '-':
                    numbersStack.push(x1-x2);
                    break;
                case '*':
                    numbersStack.push(x1*x2);
                    break;
                case '/':
                    numbersStack.push(x1/x2);
                    break;
                default:
                    throw logic_error("Operator not identified.");
            }
        }
    }
    if (numbersStack.size() == 1) {
        cout << "Result is: " << numbersStack.top();
    } else {
        throw logic_error("Problem with input string.");
    }
    return 0;
}
