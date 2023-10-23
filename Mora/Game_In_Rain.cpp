#include <iostream>
#include <string>
#include <stack>

using namespace std;

int convertToDecimal(string s, int base) {
    int result = 0;
    for (char c : s) {
        int digit = c - '0';
        result = result * base + digit;
    }
    return result;
}

int evaluateExpression(string expression) {
    stack<int> values;
    stack<char> operators;

    for (char c : expression) {
        if (c >= '0' && c <= '9') {
            int num = 0;
            while (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                c = expression[++i];
            }
            values.push(num);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/') && (c == '+' || c == '-')) {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') values.push(a + b);
                else if (op == '-') values.push(a - b);
                else if (op == '*') values.push(a * b);
                else if (op == '/') values.push(a / b);
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') values.push(a + b);
        else if (op == '-') values.push(a - b);
        else if (op == '*') values.push(a * b);
        else if (op == '/') values.push(a / b);
    }

    return values.top();
}

int main() {
    string input;
    getline(cin, input);

    int commaPos = input.find(',');
    int base = stoi(input.substr(0, commaPos));
    string expression = input.substr(commaPos + 1);

    // Convert expression to decimal
    int decimalExpression = convertToDecimal(expression, base);

    // Evaluate the expression with swapped operators
    string modifiedExpression = "";
    for (char c : expression) {
        if (c == '+') modifiedExpression += '-';
        else if (c == '-') modifiedExpression += '+';
        else if (c == '*') modifiedExpression += '/';
        else if (c == '/') modifiedExpression += '*';
        else modifiedExpression += c;
    }
    
    int result = evaluateExpression(modifiedExpression);
    cout << result << endl;

    return 0;
}
