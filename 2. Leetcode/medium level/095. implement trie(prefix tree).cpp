// link to question - https://leetcode.com/problems/implement-trie-prefix-tree/

class node {
public:
    char data;
    node** children;
    bool isTerminal;
    
    node(char data) {
        this -> data = data;             
        children = new node*[26];
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;        
    }
    
    ~node() {
        for(int i = 0; i < 26; i++) {
            delete children[i];
        }
        delete [] children;
    }
};
class Trie {
    node *root;
public:    
    Trie() {
        root = new node('\0');
    }
        
    void insert(string word, node* root) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        if(root -> children[index] != NULL) {
            insert(word.substr(1), root -> children[index]);
            return;
        }
        node* child = new node(word[0]);
        root -> children[index] = child;
        insert(word.substr(1), child);
    }
    
    void insert(string word) {
        insert(word, root);
    }
        
    bool search(string word, node* root) {
        if(word.size() == 0) {
            return root -> isTerminal;
        }
        int index = word[0] - 'a';
        if(root -> children[index] == NULL) 
            return 0;
        return search(word.substr(1), root -> children[index]);
    }
    
    bool search(string word) {
        return search(word, root);
    }
        
    bool startsWith(string prefix, node* root) {
        if(prefix.size() == 0) {
            for(int i = 0; i < 26; i++) {
                if(root -> children[i] != NULL)
                    return 1;
            }
            return root -> isTerminal;
        }
        int index = prefix[0] - 'a';
        if(root -> children[index] == NULL)
            return 0;
        return startsWith(prefix.substr(1), root -> children[index]);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix, root);
    }
};