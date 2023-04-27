#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;
bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
double evaluatePostfix(string postfix) {
    stack<double> s;

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            double num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            if(postfix[i] == '.'){
                int k = 0;
                i++;
                while(isdigit(postfix[i])){
                    k++;
                    num = num + pow(10, -k) * (postfix[i] - '0');
                    i++;
                }
            }
            s.push(num);
            i--;
        } else if(isOperator(postfix[i])) {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();
            double res;
            switch (postfix[i]) {
                case '+':
                    res = operand1 + operand2;
                    break;
                case '-':
                    res = operand1 - operand2;
                    break;
                case '*':
                    res = operand1 * operand2;
                    break;
                case '/':
                    res = operand1 / operand2;
                    break;
                case '^':
                    res = pow(operand1, operand2);
                    break;
            }
            s.push(res);
        }
    }
    return s.top();
}

int main() {
    string postfix;
    getline(cin, postfix);
    double res = evaluatePostfix(postfix);
    cout << res << endl;
    return 0;
}
