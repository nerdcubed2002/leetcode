class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ss=1;
        if(!st.empty())
        {
          while(!st.empty()&&st.top().first<=price)
          {
            ss+=st.top().second;
            st.pop();
          }
        }
        st.push(make_pair(price,ss));
        return ss;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */