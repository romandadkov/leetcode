/*
https://leetcode.com/problems/insert-interval/
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto pos = find_if(begin(intervals), end(intervals), [left = newInterval.at(0)](auto interval) {
            return left < interval.at(0);
        });
        
        intervals.insert(pos, newInterval);
        
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
