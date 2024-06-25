class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       vector<int> suffix(n, n);
       vector<int> prefix(n, -1);
       stack<int> st;
       
       // Calculate prefix (left boundaries)
       for(int i = 0; i < n; i++) 
       {
          while(!st.empty() && heights[st.top()] >= heights[i])
          {
              st.pop();
          }
          if(!st.empty()) {
              prefix[i] = st.top();
          }
          st.push(i);
       }

       while(!st.empty()) st.pop();

       // Calculate suffix (right boundaries)
       for(int i = n - 1; i >= 0; i--)
       {
          while(!st.empty() && heights[st.top()] >= heights[i])
          {
              st.pop();
          }
          if(!st.empty()) {
              suffix[i] = st.top();
          }
          st.push(i);
       }
       
       int max_area = 0;

       for(int i = 0; i < n; i++)
       {
          int width = suffix[i] - prefix[i] - 1;
          max_area = max(max_area, width * heights[i]);
       }
       return max_area;
    }
};