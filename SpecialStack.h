#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include <stack>
#include <iostream>
#include <stdexcept>

using namespace std;

class SpecialStack {
private:
    stack<int> dataStack;

public:
    void push(int value);
    void pop();
    int peek() const;
    bool empty() const;
    void printStack() const;
    void popOdd();
    void popEven();
};

#endif


