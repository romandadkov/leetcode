/*
https://leetcode.com/problems/powx-n/

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

1.00000
2147483647
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return myPowHelper(1/x, n);
        return myPowHelper(x, n);
    }
    double myPowHelper(double x, int n) {
        if (n != 0)
        {
            double answ = myPowHelper(x, n / 2);
            if (n % 2) return answ * answ * x;
            if (n / 2) return answ * answ;
        }
        return 1.;
    }
};

int main()
{
	// test data
    double x; int n;
    x=2.;n=10; cout << "x=" << x<< " n=" << n << " pow=" <<myPow(x,n) << endl;
    x=2.1;n=3; cout << "x=" << x<< " n=" << n << " pow=" <<myPow(x,n) << endl;
    x=2.;n=-2; cout << "x=" << x<< " n=" << n << " pow=" <<myPow(x,n) << endl;
    x=1.;n=2147483647; cout << "x=" << x<< " n=" << n << " pow=" <<myPow(x,n) << endl; // 1
    x=0.00001;n=2147483647; cout << "x=" << x<< " n=" << n << " pow=" <<myPow(x,n) << endl; // 0
    
    return 0;
}
