/*
84. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        // dummy bar
        heights.push_back(0);
        // go through all the histogram's bars
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int t = st.top(); 
                st.pop();
                
                res = max(res, heights[t] * (st.empty() ? i : (i - st.top() - 1))); 
            }
            st.push(i);
        }
        
        return res;
    }
};
