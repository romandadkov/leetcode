/*
150. Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<int> st;
        for (const auto& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                st.push(stoi(token));
            } 
            else {
                const int a = st.top(); st.pop();
                const int b = st.top(); st.pop();
                if (token == "+") st.push(b + a);
                if (token == "-") st.push(b - a);
                if (token == "*") st.push(b * a);
                if (token == "/") st.push(b / a);
            }
        }
        return st.top();
    }
};
