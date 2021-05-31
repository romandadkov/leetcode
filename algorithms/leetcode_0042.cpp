/*
42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        const auto size = height.size();
        vector<int> left_max(size), right_max(size);
        
        left_max[0] = height[0];
        for (int i = 1; i < size; ++i) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        
        auto answear = 0;
        for (int i = 0; i < size; ++i) {
            answear += min(left_max[i], right_max[i]) - height[i];
        }
        
        return answear;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        
        for (int current = 0; current < height.size(); ++current) {
            while (!st.empty() && height[current] > height[st.top()]) {
                auto top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current);
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for (int left = 0, right = height.size() - 1, left_max = 0, right_max = 0; left < right;) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                }
                else {
                    ans += (left_max - height[left]);
                }
                ++left;
            }
            else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                }
                else {
                    ans += (right_max - height[right]);
                }
                --right;
            }
        }
        return ans;
    }
};