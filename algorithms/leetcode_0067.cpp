/*
67. Add Binary
https://leetcode.com/problems/add-binary/
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        
        string ans;
        const int len_a = a.size();
        const int len_b = b.size();
        char c = '0';
        int i = len_a - 1, j = len_b - 1;
        for (char bc = '0'; i >= 0; --j, --i, bc = '0') {
            if (j >= 0) bc = b[j];
            auto p = plus(a[i], bc, c);
            ans.insert(0, 1, p.second);
            c = p.first;
        }
        
        if (!is_zero(c)) {
            ans.insert(0, 1, c);
            return ans;
        }
        
        return ans;
    }
    
    pair<char, char> plus(char a, char b, char c) const {
        bool a0 = is_zero(a);
        bool b0 = is_zero(b);
        bool c0 = is_zero(c);
        if (c0) {
            if (a0 && b0) return {'0','0'};
            if (a0 && !b0) return {'0','1'};
            if (!a0 && b0) return {'0','1'};
            if (!a0 && !b0) return {'1','0'};
        }
        else {
            if (a0 && b0) return {'0','1'};
            if (a0 && !b0) return {'1','0'};
            if (!a0 && b0) return {'1','0'};
            if (!a0 && !b0) return {'1','1'};
        }
        return {'0','0'};
    }
    
    inline bool is_zero(char c) const {
        return (c == '0');
    }
};

// also correct but slower
/*
    pair<char, char> plus(char a, char b, char c) const {
        const int i = num(a) + num(b) + num(c);
        // if (i == 0) return {'0','0'};
        if (i == 1) return {'0','1'};
        if (i == 2) return {'1','0'};
        if (i == 3) return {'1','1'};        
        return {'0','0'};
    }
    
    inline int num(char c) const {
        return int(c - '0');
    }
*/
