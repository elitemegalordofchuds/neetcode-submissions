class MinStack {
private:
    std::stack<int> mystack{};
    std::stack<int> minstack{};
public:
    MinStack() {}
    
    void push(int val) {
        if (!minstack.empty() && val <= minstack.top()){
            minstack.push(val);
        }
        if (minstack.empty()){
            minstack.push(val);
        }
        mystack.push(val);
    }
    
    void pop() {
        if (mystack.top() == minstack.top()){
            minstack.pop();
        }
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
