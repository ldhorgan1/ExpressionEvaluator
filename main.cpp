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
    // TODO
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
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
