// link to question - https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

class Node {
public:    
    bool terminal;			
    vector<Node*> children;
    
    Node() {        
        terminal = false;
        children.resize(26, NULL);        
    }
};

class Trie {
	Node *root;
public:
	Trie() {
		root = new Node();
	}
    
    void insert(string word) {
		insert(root, word);
	}
	
	void insert(Node *root, string word) {
		Node *temp = root;
		for(char& c: word) {
			int index = c - 'a';
			if(temp -> children[index] == NULL) {
				temp -> children[index] = new Node();
			}
			temp = temp -> children[index];
		}
		temp -> terminal = true;
	}

	bool search(string word) {
		Node *temp = root;
		for(char& c: word) {
			int index = c - 'a';
			temp = temp -> children[index];
			if (temp == NULL) {
                return 0;
            }
		}
        
		return temp -> terminal;
	}
};

class Solution {
public:
    int wordCount(vector<string>& sw, vector<string>& tw) {
        Trie t;
        for (auto &i :sw) {
            sort(i.begin(), i.end());
        }
        
        for (auto &i :sw) {
            t.insert(i);
        }
        
        int res = 0;
        int n = tw.size();
        
        for (int i = 0; i < n; i++) {
            sort(tw[i].begin(), tw[i].end());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < tw[i].size(); j++) {
                string s = tw[i].substr(0, j) + tw[i].substr(j + 1);
                if (t.search(s)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};