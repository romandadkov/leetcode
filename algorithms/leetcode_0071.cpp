/*
71. Simplify Path
https://leetcode.com/problems/simplify-path/
*/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        const string separator{"/"};
        string p;
        vector<string> s; // stack
        
        while (getline(ss, p, separator.at(0))) {            
            if (p == ".." && !s.empty()) {
                s.pop_back();
            }
            else if (p != "" && p != "." && p != "..") {
                s.push_back(separator + p);
            }
        }
        
        if (s.empty()) {
            return separator;
        }
        
        return get_ans(s);
    }
    
    string get_ans(const vector<string>& v) const {
        stringstream ss;
        copy(begin(v), end(v), ostream_iterator<string>(ss));
        return ss.str();
    }
};
