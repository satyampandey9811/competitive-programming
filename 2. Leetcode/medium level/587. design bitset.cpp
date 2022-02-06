// link to question - https://leetcode.com/problems/design-bitset/

class Bitset {
public:
    bitset<100001> b;
    int s, c, f;
    
    Bitset(int size) {
        s = size;
        c = 0, f = 0;
    }
    
    void fix(int idx) {
        if (f % 2 == 0) {
            if (b[s - idx - 1] == 0) c++;
            b[s - idx - 1] = 1;
        }
        else {
            if (b[s - idx - 1]) {
                b[s - idx - 1] = 0;
                c++;
            }
        }
    }
    
    void unfix(int idx) {
        if (f % 2 == 0) {
            if (b[s - idx - 1]) c--;
            b[s - idx - 1] = 0;
        }
        else {
            if (!b[s - idx - 1]) {
                b[s - idx - 1] = 1;
                c--;
            }
        }
    }
    
    void flip() {
        f++;
        c = s - c;
    }
    
    bool all() {
        return c == s;
    }
    
    bool one() {
        return c > 0;
    }
    
    int count() {
        return c;
    }
    
    string toString() {
        string ans;
        for (int i = 0; i < s; i++) {
            if (f & 1) {
                if (b[i]) ans += '0';
                else ans += '1';
            }
            else {
                if (b[i]) ans += '1';
                else ans += '0';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */