/*
76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return {};
        }

        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> dict_t;
        for (auto c : t) {
            if (dict_t.find(c) == dict_t.end()) {
                dict_t.insert(make_pair(c, 1));
            }
            else {
                dict_t[c]++;
            }
        }

        // Number of unique characters in t, which need to be present in the desired window.
        const int required = dict_t.size();

        // Left and Right pointer
        int l = 0, r = 0;

        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.
        int formed = 0;

        // Dictionary which keeps a count of all the unique characters in the current window.
        unordered_map<char, int> window_counts;

        // ans list of the form (window length, left, right)
        array<int, 3> ans{numeric_limits<int>::max(), 0, 0};

        while (r < s.size()) {

            // Add one character from the right to the window
            const char c = s[r];
            if (window_counts.find(c) == window_counts.end()) {
                window_counts.insert(make_pair(c, 1));
            }
            else {
                window_counts[c]++;
            }

            // If the frequency of the current character added equals to the desired count
            // in t then increment the formed count by 1.
            if (dict_t.find(c) != dict_t.end() && window_counts[c] == dict_t[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                const char character = s[l];

                // Save the smallest window until now.
                if ((r - l + 1) < ans[0]) {
                    ans = {{r - l + 1, l, r}};
                }

                // The character at the position pointed by the `left` pointer is no longer a part of the window.
                window_counts[character]--;
                if (dict_t.find(character) != dict_t.end() && window_counts[character] < dict_t[character]) {
                    formed--;
                }

                // Move the left pointer ahead, this would help to look for a new window.
                l++;
            }

            // Keep expanding the window once we are done contracting.
            r++;
        }

        if (ans[0] == numeric_limits<int>::max()) {
            return {};
        }

        return s.substr(ans[1], ans[2] + 1 - ans[1]);
    }
};
