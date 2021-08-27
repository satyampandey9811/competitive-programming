// link to question - https://leetcode.com/problems/word-search-ii/

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class node {
public:
    bool terminal;
    node* children[26];
    
    node() {
        terminal = false;
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class trie {
    node *root;
public:
    trie() {
        root = new node();
    }
    
    void insertWord(string word) {
        node* temp = root;
        for(char &c :word) {
            int ind = c - 'a';
            if(!temp -> children[ind]) {
                temp -> children[ind] = new node();
            }
            temp = temp -> children[ind];
        }
        temp -> terminal = true;
    }
    
    node* getRoot() {
        return root;
    }
};

class Solution {
public:
    vector<string> ans;
    int m, n;
    
    void dfs(string &s, node* r, int i, int j, vector<vector<char>> &a) {
        s += a[i][j];
        if(r -> terminal) {
            ans.push_back(s);
            r -> terminal = false;
        }
        char temp = a[i][j];
        a[i][j] = '.';
        
        for(int k = 0; k < 4; k++) {
            int row = i + dir[k][0], col = j + dir[k][1];
            if(row < 0 or col < 0 or row == m or col == n)
                continue;
            if(a[row][col] == '.') continue;
            int ind = a[row][col] - 'a';
            if(r -> children[ind]) {
                dfs(s, r -> children[ind], row, col, a);
            }
        }
        
        s.pop_back();
        a[i][j] = temp;
    }
    
    void find(node *root, vector<vector<char>>& a) {
        int ind;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ind = a[i][j] - 'a';
                if(root -> children[ind]) {
                    string s;
                    dfs(s, root -> children[ind], i, j, a);
                }
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {
        trie t;
        for(auto &w :words) t.insertWord(w);
        node *root = t.getRoot();
        
        m = a.size(), n = a[0].size();
        find(root, a);
        return ans;
    }
};