/*
155. Min Stack
https://leetcode.com/problems/min-stack/
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
        : _min(numeric_limits<int>::max()) {
    }
    
    void push(int val) {
        if (val <= _min) {
            _st.push_back(_min);
            _min = val;
        }
        _st.push_back(val);
    }
    
    void pop() {
        const auto t = _st.back(); _st.pop_back();
        if (t == _min) {
            _min = _st.back(); _st.pop_back();
        }
    }
    
    int top() {
        return _st.back();
    }
    
    int getMin() {
        return _min;
    }
    
    int _min;
    vector<int> _st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */