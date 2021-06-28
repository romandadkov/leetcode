/*
134. Gas Station
https://leetcode.com/problems/gas-station/
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int s = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            s += gas[i] - cost[i];
            if (s < 0) {
                s = 0;
                start = i + 1;
            }
        }
        
        return (total < 0) ? -1 : start;
    }
};
