// link to question - https://leetcode.com/problems/design-hashmap/

class MyHashMap {
public:
    vector<int> k, val;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto it = find(k.begin(), k.end(), key);
        if(it != k.end()) {
            int ind = it - k.begin();
            val[ind] = value;
        }
        else {
            k.emplace_back(key);
            val.emplace_back(value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto it = find(k.begin(), k.end(), key);
        if(it != k.end()) {
            int ind = it - k.begin();
            return val[ind];
        }
        else return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto it = find(k.begin(), k.end(), key);
        if(it != k.end()) {
            val[it - k.begin()] = -1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */