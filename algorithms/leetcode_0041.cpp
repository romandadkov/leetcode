/*
41. First Missing Positive
https://leetcode.com/problems/first-missing-positive/
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> s;
        copy(nums.begin(), nums.end(), inserter(s, s.end()));
        for (int i = 1;; ++i) {
            if (s.find(i) == s.end())
                return i;
        }
        return 0;
    }
};

// constexpr size_t N = 100;
// bitset<N> bs;
// for (const auto i : nums) {
// 	if (i <= 0) {
// 		continue;
// 	}
// 	bs |= ((unsigned long long)1 << i);
// }

// for (int i = 1;; ++i) {
// 	if (!bs.test(i))
// 		return i;
// }
// return 0;