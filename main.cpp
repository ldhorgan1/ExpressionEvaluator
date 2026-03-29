#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    string current = "";

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];

        if (c == ' ') {
            if (current != "") {
                tokens.push_back({current});
                current = "";
            }
        }
        else if (c >= '0' && c <= '9') {
            current += c;
        }
        else {
            if (current != "") {
                tokens.push_back({current});
                current = "";
            }

            string op = "";
            op += c;
            tokens.push_back({op});
        }
    }
    if (current != "") {
        tokens.push_back({current});
    }
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    if (op == "+" || op == "-") {
        return 1;
    }
    else if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    int count = 0;

    for (int i = 0; i < tokens.size(); i++) {
        string s = tokens[i].value;

        if (s == "(" || s == ")") {
            return false;
        }
        else if (isOperator(s)) {
            if (count < 2) {
                return false;
            }
            count -= 1;
        }
        else {
            bool isNumber = true;

            for (int j = 0; j < s.length(); j++) {
                if (s[j] < '0' || s[j] > '9') {
                    isNumber = false;
                }
            }
            if (!isNumber) {
                return false;
            }
            count += 1;
        }
    }
    return count == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    if (tokens.size() == 0) {
        return false;
    }

    int balance = 0;

    for (int i = 0; i < tokens.size(); i++) {
        string s = tokens[i].value;

        if (s == "(") {
            balance++;
        }
        else if (s == ")") {
            balance--;
            if (balance < 0) {
                return false;
            }
        }
        else if (isOperator(s)) {
            if (i == 0 || i == tokens.size() - 1) {
                return false;
            }
            if (isOperator(tokens[i - 1].value)) {
                return false;
            }
        }
        else {
            for (int j = 0; j < s.length(); j++) {
                if (s[j] < '0' || s[j] > '9') {
                    return false;
                }
            }
        }
    }
    if (balance != 0){
        return false;
    }

    return true;
}
// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<string> ops;

    for (int i = 0; i < tokens.size(); i++) {
        string s = tokens[i].value;

        if (s == "(") {
            ops.push(s);
        }
        else if (s == ")") {
            while (!ops.empty() && ops.top() == "(") {
                output.push_back({ops.top()});
                ops.pop();
            }
            if (!ops.empty()) {
                ops.push(s);
            }
        }
        else if (isOperator(s)) {
            while (!ops.empty() && isOperator(ops.top()) &&
                precedence(ops.top()) >= precedence(s)) {
                output.push_back({ops.top()});
                ops.pop();
            }
            ops.push(s);
        }
        else {
            output.push_back({s});
        }
    }
    while (!ops.empty()) {
        output.push_back({ops.top()});
        ops.pop();
    }
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
   for (int i = 0; i < tokens.size(); i++) {
       string s = tokens[i].value;

       if (isOperator(s)) {
           double b = stack.top();
           stack.pop();
           double a = stack.top();
           stack.pop();

           if (s == "+") {
               stack.push(a + b);
           }
           else if (s == "-") {
               stack.push(a - b);
           }
           else if (s == "*") {
               stack.push(a * b);
           }
           else if (s == "/") {
               stack.push(a / b);
           }
       }
       else {
           stack.push(stod(s));
       }
   }
    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
