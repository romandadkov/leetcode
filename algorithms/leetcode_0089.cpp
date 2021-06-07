/*
89. Gray Code
https://leetcode.com/problems/gray-code/
*/
class Solution {
public:
    /*
    1.
    https://www.cnblogs.com/grandyang/p/4315607.html
    vector<int> grayCode(int n) {
        vector<int> r;
        for (int i = 0; i < pow(2, n); ++i) {
            r.push_back((i >> 1) ^ i);
        }
        
        return r;
    }
    */
    
    /*
    2.
    mirror code approach
    0     0.0      0.00
    1  -> 0.1  ->  0.01
          ---      0.11
          1.1      0.10
          1.0      ----
                   1.10
                   1.11
                   1.01
                   1.00
    */
    vector<int> grayCode(int n) {
        vector<int> r{0};
        for (int i = 0; i < n; ++i) {
            int s = r.size();
            for (int j = s - 1; j >=0; --j) {
                r.push_back(r[j] | (1 << i));
            }
        }
        return r;
    }
};

