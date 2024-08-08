class MyStack {
public:
int N ;
    queue <int> que1; 
    queue <int> que2;

    
    MyStack() {
        N = 0;
    }
    
    void push(int x) {
        que2.push(x);
         
        N++;
        while (!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1,que2);
    }
    
    int pop() {
        if (N == 0) {
            return -1;  
        }
       int topElement = que1.front();
        que1.pop();
        N--;
        return topElement;
    }
    
    int top() {
         if (N == 0) {
            return -1;  // Return a sentinel value if stack is empty
        }
        return que1.front();
    }
    
    bool empty() {
        return N== 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */