// link to question - https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

class trieNode {
public:
	bool terminal;   // whether a string terminates here or not
	int count;       // how many strings have the same prefix
	vector<trieNode*> children;

	trieNode() {
		terminal = false;
		count = 0;
		children = vector<trieNode*>(26, NULL);
	}
};

class Trie {
	trieNode *root;
public:
	int distinctWords;

	Trie() {
		distinctWords = 0;
		root = new trieNode();
	}

	bool insertWord (trieNode *root, string word) {
		trieNode *temp = root;
		for (char& c: word) {
			int index = c - 'a';
			if (temp -> children[index] == NULL) {
				temp -> children[index] = new trieNode();
			}
			temp = temp -> children[index];
			temp -> count++;
		}
		if (temp -> terminal) return 0;
		return temp -> terminal = true;
	}

	void insertWord (string word) {
		if (insertWord(root, word)) distinctWords++;
	}

	int search (string word) {
        int ans = 0;
		trieNode *temp = root;
		for (char& c: word) {
			int index = c - 'a';
			temp = temp -> children[index];
			if (temp == NULL) break;
            ans += temp -> count;
		}
		return ans;
	}
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie a;
        int n = words.size();
        for (auto &i :words) {
            a.insertWord(i);
        }
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            ans[i] = a.search(words[i]);
        }
        
        return ans;
    }
};