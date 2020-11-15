// link to question - https://leetcode.com/problems/design-an-ordered-stream/

class OrderedStream {
public:
    int ptr, n;
    vector<string> a;
    
    OrderedStream(int m) {
        ptr = 0, n = m;
        a.resize(n);
    }
    
    vector<string> insert(int id, string value) {
        a[id - 1] = value;
        vector<string> ans;
        if(ptr < id - 1) return ans;
        
        while(ptr < n and a[ptr] != "") {
            ans.push_back(a[ptr++]);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */