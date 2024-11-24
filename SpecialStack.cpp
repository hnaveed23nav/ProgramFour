#include "SpecialStack.h"

void SpecialStack::push(int value) {
    dataStack.push(value);
}

void SpecialStack::pop() {
    if (dataStack.empty()) {
        throw runtime_error("Stack is empty, cannot pop.");
    }
    dataStack.pop();
}

int SpecialStack::peek() const {
    if (dataStack.empty()) {
        throw runtime_error("Stack is empty, cannot peek.");
    }
    return dataStack.top();
}

bool SpecialStack::empty() const {
    return dataStack.empty();
}

void SpecialStack::printStack() const {
    if (dataStack.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<int> temp = dataStack;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
}

void SpecialStack::popOdd() {
    if (dataStack.empty()) {
        throw runtime_error("Stack is empty, cannot pop odd.");
    }

    stack<int> tempStack;
    bool found = false;

    while (!dataStack.empty()) {
        if (!found && dataStack.top() % 2 != 0) {
            dataStack.pop();
            found = true;
            break;
        }
        tempStack.push(dataStack.top());
        dataStack.pop();
    }

    while (!tempStack.empty()) {
        dataStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        throw runtime_error("No odd number found to pop.");
    }
}

void SpecialStack::popEven() {
    if (dataStack.empty()) {
        throw runtime_error("Stack is empty, cannot pop even.");
    }

    stack<int> tempStack;
    bool found = false;

    while (!dataStack.empty()) {
        if (!found && dataStack.top() % 2 == 0) {
            dataStack.pop();
            found = true;
            break;
        }
        tempStack.push(dataStack.top());
        dataStack.pop();
    }

    while (!tempStack.empty()) {
        dataStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        throw runtime_error("No even number found to pop.");
    }
}

