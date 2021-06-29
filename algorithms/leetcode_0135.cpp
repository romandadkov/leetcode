/*
135. Candy
https://leetcode.com/problems/candy/
*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int r = 0;
        vector<int> l2r(ratings.size(), 1);
        vector<int> r2l(ratings.size(), 1);        
        
        for (int i = 1; i < l2r.size(); ++i) {
            if (ratings[i - 1] < ratings[i]) {
                l2r[i] = l2r[i - 1] + 1;
            }
        }
        
        for (int i = r2l.size() - 2; i >= 0; --i) {
            if (ratings[i + 1] < ratings[i]) {
                r2l[i] = r2l[i + 1] + 1;
            }
        }
        
        for (int i = 0; i < l2r.size(); ++i) {
            r += max(l2r[i], r2l[i]);
        }
        
        return r;
    }
};
