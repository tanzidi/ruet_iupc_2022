#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAX_N = 1e5 + 5;
const int LOG = 18;
vector<int> g[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];
int idx = 0;
unordered_map<string, int> mp;

int get_lca(int a, int b) {
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j];
		}
	}
	if(a == b) {
		return a;
	}
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  	int cs = 1, t; cin >> t;
  	while (t--) {
  		int n; cin >> n;
  		cout << "Case " << cs++ << ":\n";
  		mp["Main"] = idx++;
  		for (int i = 0; i < n; i++) {
	  		char c; cin >> c;
	  		if (c == '+') {
	  			string a, b, c, d;
	  			cin >> a >> b >> c >> d;
	  			if (mp.find(b) == mp.end()) mp[b] = idx++;
	  			g[mp[d]].push_back(mp[b]);
	  			up[mp[b]][0] = mp[d];
				for(int j = 1; j < LOG; j++) {
					up[mp[b]][j] = up[up[mp[b]][j-1]][j-1];
				}
	  			depth[mp[b]] = depth[mp[d]] + 1; 
	  		}
	  		else {
	  			string a, b, c, d, e;
	  			cin >> a >> b >> c >> d >> e;
	  			e.pop_back();
	  			e.pop_back();
	  			if (mp.find(a) != mp.end() && mp.find(e) != mp.end()) {
	  				int lca = get_lca(mp[a], mp[e]);
	  				if (lca != mp[a]) cout << "no\n";
	  				else cout << "yes\n";
	  			}
	  			else cout << "no\n";
	  		}
  		}
  		mp.clear();
  		idx = 0;
  		for (int i = 0; i <= n; i++) {
  			depth[i] = 0;
  			g[i].clear();
  			for (int j = 0; j < LOG; j++) {
  				up[i][j] = 0;
  			}
  		}
  	}

}
