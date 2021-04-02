/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx/
*/

class Solution {
public:
    // http://en.wikipedia.org/wiki/Newton%27s_method
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        auto x1 = 1.;
        
        for (auto x0 = 0.; abs(x1 - x0) > 1e-6; x0 = x1, x1 = (x1 + (x / x1)) / 2 ) {}
        
        return int(x1);
    }
};
