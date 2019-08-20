// link to question - https://www.codechef.com/AUG19B/problems/ZOMCAV/

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	int n;
	cin >> n;
	vector<int> c(n), h(n),r(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) {
		int x = i - c[i], y = i + c[i];
		x = max(x, 0), y = min(y, n - 1);
		r[x]++;
		if (y + 1 < n)
			r[y + 1]--;
	}
	for (int i = 1; i<n; i++) {
		r[i] += r[i - 1];
	}
	sort(r.begin(), r.end());
	sort(h.begin(), h.end());
	for (int i = 0; i < n; i++) {
		if (r[i] != h[i]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main() {
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
	return 0;
}