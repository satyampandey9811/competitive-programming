// link to question - https://leetcode.com/problems/stream-of-characters/

class trienode {
public:
    char data;
    bool isterminal;
    vector<trienode*> children;
    
    trienode(char data) {
        this -> data = data;
        isterminal = false;
        children.resize(26, NULL);        
    }
};

class StreamChecker {
public:
    trienode *root = new trienode('\0');
    string s;
    
    // void insert(trienode* root, string &word, int i) {
    //     if(i == word.size()) {            
    //         root -> isterminal = true;
    //         return;
    //     }
    //     int index = word[i] - 'a';
    //     trienode *child = root -> children[index];
    //     if(!child) {
    //         child = new trienode(word[i]);                
    //         root -> children[index] = child;
    //     }
    //     insert(child, word, i + 1);
    // }
    
    StreamChecker(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            trienode *temp = root;
            for(char c: word) {
                int index = c - 'a';
                if(temp -> children[index] == NULL) {
                    temp -> children[index] = new trienode(c);
                }
                temp = temp -> children[index];                
            }
            temp -> isterminal = true;
        }
    }
    
    // bool search(trienode* root, string &word, int i) {
    //     if(i == word.size()) {
    //         return root -> isterminal;
    //     }
    //     int index = word[i] - 'a';
    //     if(root -> children[index] == NULL) return 0;
    //     return search(root -> children[index], word, i + 1);
    // }
    
    bool query(char letter) {
        s += letter;        
        trienode *temp = root;
        for(int i = s.size() - 1; i >= 0; i--) {                    
            int index = s[i] - 'a';
            temp = temp -> children[index];
            if(temp == NULL) return 0;
            if(temp -> isterminal) return 1;
        }
        return 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */