// link to question - https://leetcode.com/problems/stream-of-characters/

class trienode {
public:
    char data;
    bool isterminal;
    vector<trienode*> children(26);
    
    trienode(char data) {
        this -> data = data;
        isterminal = false;
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
}

class StreamChecker {
public:
    trienode *root = new trienode('\0');
    
    void insert(trienode* root, string &word, int i) {
        if(i == word.size()) {            
            root -> isterminal = true;
            return;
        }
        int index = word[i] - 'a';
        trienode *child = root -> children[index];
        if(!child) child = new trienode(word[i]);                
        insert(child, word, i + 1);
    }
    
    StreamChecker(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) 
            insert(root, words[i], 0);
    }
    
    bool query(char letter) {
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */