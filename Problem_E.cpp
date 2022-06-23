#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll m = 1e9 + 7;

const int N = 1e5 + 5;
int fact[N], ifact[N];

ll mod_mul (ll a, ll b) {
	return ((a % m) * (b % m)) % m;
}
ll mod_sum (ll a, ll b) {
	return ((a % m) + (b % m) + m) % m;
}

ll expo (ll a, ll b) {
	if (b == 1LL) return a % m;
	ll x;
	if (b & 1LL) {
		x = expo (a, b - 1LL);
		return mod_mul(x, a);
	}
	else {
		x = expo (a, b / 2LL);
		return mod_mul(x, x);
	}
}

ll mod_inv (ll a) {
	return expo (a, m - 2) % m;
}

void precal () {
	fact[0] = 1;
	ifact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mod_mul(fact[i - 1], i);
		ifact[i] = mod_mul(ifact[i - 1], mod_inv(i));
	}
}

ll pow_of_base (ll n, ll b) {
	ll ret = 0;
	while (n) {
		n /= b;
		ret += n;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	precal ();
	int cs = 1, t; cin >> t;
	while (t--) {
		ll n, b; cin >> n >> b;
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			ll zero_cnt = pow_of_base(i + 1LL, b);
			ll ncr = mod_mul(fact[n - 1LL], mod_mul(ifact[i], ifact[n - i - 1LL]));
			ll zero_total = mod_mul(zero_cnt, ncr);
			ans = mod_sum(ans, zero_total);
		}
		cout << "Case " << cs++ << ": " << ans << "\n";
	}  

}
