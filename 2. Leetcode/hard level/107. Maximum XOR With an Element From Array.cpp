// link to question - https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

class trieNode {
public:
    vector<trieNode*> next;
    trieNode () {
        next = vector<trieNode*>(2, NULL);
    }
};

class Trie {
	trieNode *root, *temp;
    int c, res, val, i;
public:
	Trie() {
		root = new trieNode();
	}

	void insert (int n) {
        temp = root;
		for (i = 31; i >= 0; i--) {
            c = 1 & (n >> i);
			if (temp -> next[c] == NULL) {
				temp -> next[c] = new trieNode();
			}
			temp = temp -> next[c];
		}
	}

	int find (int x) {
		temp = root;
        res = 0;
        
        for (i = 31; i >= 0; i--) {
            val = 1 ^ (1 & (x >> i));
            if (temp -> next[val] == NULL)
                temp = temp -> next[1 - val];
            else {
                temp = temp -> next[val];
                res |= 1 << i;
            }
        }
        
        return res;
	}
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        int qlen = q.size();
        vector<int> ans(qlen, -1);
        
        for (int i = 0; i < qlen; i++) {
            q[i].push_back(i);
        }
        sort(q.begin(), q.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });
        sort(a.begin(), a.end());
        
        Trie t;
        int x, m, ind;
        int i = 0, j = 0;
        
        while (i < qlen and q[i][1] < a[0]) i++;
        
        while (i < qlen) {
            x = q[i][0], m = q[i][1], ind = q[i][2];
            
            while (j < n and a[j] <= m) {
                t.insert(a[j]);
                j++;
            }
            
            ans[ind] = t.find(x);
            i++;
        }
        
        return ans;
    }
};