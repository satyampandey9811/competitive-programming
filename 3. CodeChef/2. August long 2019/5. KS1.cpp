// link to question - https://www.codechef.com/AUG19B/problems/KS1

#include <bits/stdc++.h>
#define int long long 
using namespace std;

void testcase() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	unordered_map<int, vector<int>> mp;
	int x = 0;
	mp[0].push_back(-1);
	for (int i = 0; i < n; i++) {
		x ^= a[i];
		mp[x].push_back(i);
	}
	for (auto val : mp) {
		int m = val.second.size();							
		int c = 1, p = 0, q = 0, r;
		for (int i = m - 1; i >= 0; i--) {
			p += val.second[i] * (m - c);
			c++;
		}
		c = 1;
		for (int i = 0; i < m; i++) {
			q += val.second[i] * (m - c);
			c++;
		}
		r = (m*(m - 1)) / 2;
		ans += p - q - r;		
	}
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef SP
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif	
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		testcase();
		cout << '\n';
	}
	
}