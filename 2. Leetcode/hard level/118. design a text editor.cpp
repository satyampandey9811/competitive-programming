// link to question - https://leetcode.com/problems/design-a-text-editor/

struct node {
    node* next;
    node* prev;
    char c;
    
    node (char d) {
        next = NULL;
        prev = NULL;
        c = d;
    }
};

class TextEditor {
public:
    node* head;
    
    TextEditor() {
        head = new node('A');
    }
    
    void addText(string a) {
        int n = a.size();
        node* last = head -> next;
        
        for (auto &i :a) {
            node* newnode = new node(i);
            newnode -> prev = head;
            head -> next = newnode;
            head = newnode;
        }
        
        head -> next = last;
        if (last) last -> prev = head;
    }
    
    int deleteText (int k) {
        if (head -> c == 'A') return 0;
        
        int ans = 0;
        node* last = head -> next;
        
        for (int i = 0; i < k; i++) {
            if (head -> c == 'A') break;
            head = head -> prev;
            ans++;
        }
        
        head -> next = last;
        if (last) {
            last -> prev = head;
        }
        
        return ans;
    }
    
    string cursorLeft (int k) {
        for (int i = 0; i < k; i++) {
            if (head -> c == 'A') {
                break;
            }
            head = head -> prev;
        }
        
        node* temp = head;
        string ans;
        
        for (int i = 0; i < 10; i++) {
            if (temp -> c == 'A') {
                break;
            }
            ans += temp -> c;
            temp = temp -> prev;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string cursorRight (int k) {
        for (int i = 0; i < k; i++) {
            if (!head -> next) {
                break;
            }
            head = head -> next;
        }
        
        node* temp = head;
        string ans;
        
        for (int i = 0; i < 10; i++) {
            if (temp -> c == 'A') {
                break;
            }
            ans += temp -> c;
            temp = temp -> prev;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

