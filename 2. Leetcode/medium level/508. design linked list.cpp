// link to question - https://leetcode.com/problems/design-linked-list/

class node {
public:
    int val;
    node *next;
    node *prev;
    
    node(int value) : val(value), next(NULL), prev(NULL) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    node *head, *tail;
    int totalNodes;
    
    MyLinkedList() {
        head = tail = NULL;
        totalNodes = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node *temp = head;
        int i = 0;
        while(temp) {
            if(i == index) return temp -> val;
            i++;
            temp = temp -> next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *newNode = new node(val);
        newNode -> next = head;
        if(!head) tail = newNode;
        else head -> prev = newNode;
        head = newNode;
        totalNodes++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *newNode = new node(val);
        newNode -> prev = tail;
        if(!tail) head = newNode;
        else tail -> next = newNode;
        tail = newNode;
        totalNodes++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0) addAtHead(val);
        else if(index == totalNodes) addAtTail(val);
        else if(index < totalNodes) {
            node *temp = head;
            int i = 0;
            while(temp) {
                if(i == index) break;
                i++;
                temp = temp -> next;
            }
            node *newNode = new node(val);
            newNode -> next = temp;
            temp -> prev -> next = newNode;
            newNode -> prev = temp -> prev;
            temp -> prev = newNode;
            totalNodes++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= totalNodes) return;
        node *temp;
        
        if(index == 0) {
            temp = head;
            if(totalNodes == 1) head = tail = NULL;
            else {
                head = head -> next;
                head -> prev = NULL;
            }
        }
        else if(index == totalNodes - 1) {
            temp = tail;
            if(totalNodes == 1) head = tail = NULL;
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
        }
        else {
            int i = 0;
            temp = head;
            while(temp) {
                if(i == index) break;
                i++;
                temp = temp -> next;
            }
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
        }
        delete temp;
        totalNodes--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */