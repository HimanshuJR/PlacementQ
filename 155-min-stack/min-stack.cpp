#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    vector<int> myStack;

public:
    MinStack() {
    }
    
    void push(int val) {
        myStack.push_back(val);
    }
    
    void pop() {
        myStack.pop_back();
    }
    
    int top() {
        return myStack.back();
    }
    
    int getMin() {
        int ret = INT_MAX;
        
        for (auto x : myStack) 
            if (x < ret) ret = x;
        
        return ret;
    }
};