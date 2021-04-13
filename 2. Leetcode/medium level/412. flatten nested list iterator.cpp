// link to question - https://leetcode.com/problems/flatten-nested-list-iterator/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> a;
    int i;
    
    void go(int i, vector<NestedInteger>& b) {
        if(i == b.size()) return;
        NestedInteger *x = new NestedInteger(b[i]);
        
        if(x -> isInteger()) a.push_back(x -> getInteger());
        else go(0, x -> getList());
        
        go(i + 1, b);
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        i = 0;
        go(0, nestedList);
    }
    
    int next() {
        return a[i++];
    }
    
    bool hasNext() {
        return i != a.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */