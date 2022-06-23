#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

const int N = 1e5 + 5;
ll ans[N];
vector<ll> pwrs;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void precal () {
	ll mul = 1;
	for (int i = 0; i <= 63; i++) {
		pwrs.push_back(mul);
		mul <<= (ll)1;
	}
}

void reset () {

	while (!pq.empty()) pq.pop();
	for (int i = 0; i <= 63; i++) pq.push(pwrs[i]);

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	precal();
	int t, cs = 1; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		bool f = 0;
		vector<pair<int, int>> vt;
		for (int i = 0; i < q; i++) {
			int a, b; cin >> a >> b;
			if (b - a + 1 > 64) f = 1;
			vt.push_back({a, b});
		}
		cout << "Case " << cs++ << ":\n";
		if (f) cout << "Impossible\n";
		else {
			reset();
			sort (vt.begin(), vt.end());
			int left = 1, right = 1;
			for (int i = 0; i < q; i++) {

				int l = vt[i].first;
				int r = vt[i].second;

				while (left < l) {
					if (left <= n && ans[left] != (ll)0) pq.push(ans[left]);
					left++;
				}
				while (right <= r) {
					if (right >= left && right <= n) {
						ans[right] = pq.top();
						pq.pop();
					}
					right++;
				}

			}
			for (int i = 1; i <= n; i++) {
				cout << max(ans[i], (ll)1);
				ans[i] = 0;
				if (i != n) cout << " ";
			}
			cout << "\n";
		}
	}  

}
