class MyStack {
public:
    stack<int>m;
    stack<int>t;
    MyStack() {
        
    }
    
    void push(int x) {
        
        t.push(x);
        while(!m.empty())
        {
            int el=m.top();
            m.pop();
            t.push(el);
        }
        while(!t.empty())
        {
            int el=t.top();
            t.pop();
            m.push(el);
        }

    }
    
    int pop() {
        int el=m.top();
        m.pop();
        return el;
    }
    
    int top() {
        int el=m.top();
        return el;
    }
    
    bool empty() {
        return m.empty();
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