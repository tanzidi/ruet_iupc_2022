#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 1e6 + 5;

int parent[N];

int find (int node) {
	if (parent[node] == node) return node;
	return parent[node] = find (parent[node]);
}
ll ans = 0;
void solve (int n) {
	for (int i = n / 2; i >= 1; i--) {
		for (int j = i * 2; j <= n; j += i) {
			int par1 = find(i);
			int par2 = find(j);
			if (par1 != par2) {
				parent[par1] = par2;
				ans += __gcd(i, j);
			}
		}
	}
}


int main() {
  	int cs = 1, t;
  	scanf("%d", &t);
  	while (t--) {
  		int n; scanf("%d", &n);
  		for (int i = 1; i <= n; i++) {
  			parent[i] = i;
  		}
  		if (n == 1) {
  			printf("Case %d: 0\n", cs++);
  			continue;
  		}
  		solve(n);
  		printf("Case %d: %lld\n", cs++, ans);
  		ans = 0;
  	}
}
