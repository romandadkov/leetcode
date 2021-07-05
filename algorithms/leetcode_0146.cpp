/*
146. LRU Cache
https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = _m.find(key);
        if (it == _m.end()) {
            return -1;
        }
        _l.splice(_l.begin(), _l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = _m.find(key);
        if (it != _m.end()) {
            _l.erase(it->second);
        }
        _l.push_front(make_pair(key, value));
        _m[key] = _l.begin();
        if (_m.size() > _capacity) {
            int k = _l.rbegin()->first;
            _l.pop_back();
            _m.erase(k);
        }
    }
    
private:
    int _capacity{0};
    list<pair<int, int>> _l;
    unordered_map<int, list<pair<int, int>>::iterator> _m{};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */