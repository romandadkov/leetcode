https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](auto v1, auto v2) {
            return v1.at(0) < v2.at(0);
        });
        
        vector<vector<int>> merged;
        for (auto interval : intervals) {
            if (merged.empty() || merged.back().at(1) < interval.at(0)) {
                merged.push_back(interval);
            }
            else {
                merged.back()[1] = max(merged.back().at(1), interval.at(1));
            }
        }
        
        return merged;
    }
};
