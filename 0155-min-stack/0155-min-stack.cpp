class MinStack {
public:
    stack<int>mini;
    stack<int>st;
    void placemin(stack<int>&mini,int el)
    {
        if(!mini.empty())
        {
            if(el<mini.top())
            mini.push(el);
            else
            mini.push(mini.top());
        }
        else
        mini.push(el);
    }
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        placemin(mini,val);
    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */