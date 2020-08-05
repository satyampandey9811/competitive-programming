// link to question - https://leetcode.com/problems/add-and-search-word-data-structure-design/

class node {
public:
    char data;
    node **children;
    bool isterminal;
    
    node(char data) {
        this -> data = data;
        children = new node*[26];
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isterminal = false;
    }
};

class WordDictionary {
public:
    node *root;
    
    WordDictionary() {
        root = new node('\0');
    }
        
    void addWord(node *root, string &word, int i) {
        if(word.size() == i) {
            root -> isterminal = true;
            return;
        }
        node *child;
        int index = word[i] - 'a';
        if(root -> children[index] != NULL) child = root -> children[index];
        else {
            child = new node(word[i]);
            root -> children[index] = child;
        }
        addWord(child, word, i + 1);
    }
    
    void addWord(string word) {
        addWord(root, word, 0);
    }
    
    bool search(node *root, string &word, int i) {
        if(i == word.size()) {
            return root -> isterminal;
        }        
        if(word[i] >= 'a' and word[i] <= 'z') {
            int index = word[i] - 'a';
            if(root -> children[index] == NULL) return 0;
            return search(root -> children[index], word, i + 1);
        }
        else {
            for(int j = 0; j < 26; j++) {
                if(root -> children[j] and search(root -> children[j], word, i + 1)) 
                    return 1;
            }
            return 0;
        }
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */