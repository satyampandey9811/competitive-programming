// link to question - https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

/***************  disjoint set union code starts  *****************/

class unionFind {
private:
    vector<int> setSize;
    vector<int> parent;
    int totalComponents;
    int maxSetSize;

public:
    unionFind (int n) {
        setSize = vector<int>(n, 1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        totalComponents = n;
        maxSetSize = 1;
    }

    // uses path compression which takes amortized constant time.
    int find (int x) {
        int root = x;
        while (root != parent[root]) root = parent[root];
        while (x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    // uses union by rank 
    void unify (int g, int h) {
        if (connected(g, h)) return;
        int root1 = find(g);
        int root2 = find(h);
        if (setSize[g] < setSize[h]) {
            parent[root1] = root2;
            setSize[root2] += setSize[root1];
        }
        else {
            parent[root2] = root1;
            setSize[root1] += setSize[root2];
        }
        totalComponents--;
        maxSetSize = max({maxSetSize, setSize[root1], setSize[root2]});
    }

    // returns true if g and h are connected else returns false.
    bool connected (int g, int h) {
        return find(g) == find(h);
    }

    // returns the size of the component/set to which 'g' belongs
    int componentSize (int g) {
        return setSize[find(g)];
    }

    // returns the total number of components/sets at the moment
    int components () {
        return totalComponents;
    }

    // returns the maximum set size among all the components
    int maxComponentSize () {
        return maxSetSize;
    }
};

/***************  disjoint set union code ends  *****************/

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        unionFind a(n);
        for (auto &i :edges) {
            a.unify(i[0], i[1]);
        }
        for (int i = 0; i < n; i++) {
            ans += n - a.componentSize(i);
        }
        ans /= 2;
        return ans;
    }
};