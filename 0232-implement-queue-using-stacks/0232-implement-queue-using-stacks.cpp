class MyQueue {
public:
stack<int>m;
stack<int>t;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        while(!m.empty())
        {
            int el=m.top();
            m.pop();
            t.push(el);
        }
        m.push(x);
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
    
    int peek() {
        return m.top();
    }
    
    bool empty() {
        return m.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */