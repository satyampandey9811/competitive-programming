// link to question - https://leetcode.com/problems/graph-connectivity-with-threshold/

class Solution {
public:
/***************  union find algorithm code starts  *****************/

vector<int> size;
vector<int> parent;
int totalComponents;

void init(int n) {
	size.resize(n, 1);
	parent.resize(n);
	for(int i = 0; i < n; i++) parent[i] = i;	
	totalComponents = n;
}

// uses path compression which takes amortized constant time.
int find(int x) {				
	int root = x;
	while(root != parent[root]) root = parent[root];
	while(x != root) {
		int next = parent[x];
		parent[x] = root;
		x = next;
	}	
	return root;
}

// uses union by rank 
void unify(int g, int h) {
	if(connected(g, h)) return;
	int root1 = find(g);
	int root2 = find(h);
	if(size[g] < size[h]) {
		parent[root1] = root2;
		size[root2] += size[root1];
	}
	else {
		parent[root2] = root1;
		size[root1] += size[root2];
	}
	totalComponents--;
}

// returns true if g and h are connected else returns false.
bool connected(int g, int h) {
	return find(g) == find(h);
}

// returns the size of the component/set to which 'g' belongs
int componentSize(int g) {
	return size[find(g)];
}

// returns the number of components/sets at the moment
int components() {
	return totalComponents;
}

/***************  union find algorithm code ends  *****************/
    
    vector<bool> areConnected(int n, int t, vector<vector<int>>& a) {
        init(n+1);
        vector<bool> ans(a.size());
        int f, s;
        
        for(int i = t + 1; i <= n; i++) {
            for(int j = 2; j * i <= n; j++) {
                unify(i, j * i);
            }
        }
        
        for(int i = 0; i < a.size(); i++) {
            f = a[i][0], s = a[i][1];
            if(connected(f, s)) ans[i] = true;
        }
        
        return ans;
    }
};