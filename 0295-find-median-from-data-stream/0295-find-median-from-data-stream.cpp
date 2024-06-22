class MedianFinder {
public:
    priority_queue<int>max_h;
    priority_queue<int,vector<int>,greater<int>>min_h;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_h.size()==0||num<=max_h.top())
        {
            max_h.push(num);
        }
        else
        min_h.push(num);

        int max_s=max_h.size();
        int min_s=min_h.size();
        if(max_s-min_s==2||max_s-min_s==-2)
        {
            if(max_s>min_s)
            {
                int el=max_h.top();
                max_h.pop();
                min_h.push(el);
            }
            else
            {
                int el=min_h.top();
                min_h.pop();
                max_h.push(el);
            }
        }
    }
    
    double findMedian() {
        int max_s=max_h.size();
        int min_s=min_h.size();
        if(max_s==min_s)
        {
            return ((double)max_h.top()+(double)min_h.top())/2.0;
        }
        else
        {
            if(max_s>min_s)
            return (double)max_h.top();
            else
            return (double)min_h.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */