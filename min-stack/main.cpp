/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

#include <vector>

class MinStack {
    vector<pair<int, int>> v_;
public:
    MinStack() {}

    void push(int x) {
        int i = v_.empty() ? 0
            : v_[v_.back().second].first < x ? v_.back().second : v_.size();
        v_.emplace_back(x, i);
    }

    void pop() {
        v_.pop_back();
    }

    int top() {
        return v_.back().first;
    }

    int getMin() {
        return v_[v_.back().second].first;
    }
};
