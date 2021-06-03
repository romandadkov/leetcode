/*
85. Maximal Rectangle
https://leetcode.com/problems/maximal-rectangle/
*/

/*
This question is an extension of the 84. Largest Rectangle in Histogram. 
Each line of matrix can be thought of as a histogram. For each histogram we can calculate largest rectangle area. 
But first we need to corrct heaights vector on each line. Since the question limits the input matrix characters to only '0' and '1',
for each point, if it is ‘0’, assign 0, if it is ‘1’, assign the previous height value plus 1.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        vector<int> heights;
        for (int i = 0; i < matrix.size(); ++i) {
            heights.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                heights[j] = (matrix[i][j] == '0') ? 0 : (1 + heights[j]);
            }
            res = max(res, largestRectangleArea(heights));
        }
        
        return res;
    }
    
    
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

