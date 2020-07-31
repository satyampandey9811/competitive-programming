// link to question - https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
public:
    int id;
    vector<string> res;
    
    CombinationIterator(string a, int k) {
        id = 0;
        int n = a.size();
        for(int i = (1 << k) - 1; i < (1 << n); i++) {
            string word;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) word += a[j];
            }
            if(word.size() == k) res.push_back(word);
        }
        sort(res.begin(), res.end());
    }
    
    string next() {
        return res[id++];
    }
    
    bool hasNext() {
        return id < res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */