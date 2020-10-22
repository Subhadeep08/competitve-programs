#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
#define ld long double
#define endl 	 "\n";
#define mp 	 make_pair;

const int mod = 1000000007;
using namespace std;
//using namespace std::chrono;

ll sqr(int a) {
	return (ll) a * (ll) a;
}

ll values(int len, int partition) {
	int p = len / partition;
	return sqr(p) * (len - len % partition) + sqr(p + 1) * (len % partition);

}

ll improve(int len, int parts) {
	return values(len, parts) - values(len, parts + 1);
}

int main() {
	//auto start = high_resolution_clock::now(); // starting clock
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
	int n, k; int a; ll ans = 0;
	cin >> n, k;
	set<pair<ll, int>>record;
	for (int i = 0; i < n; i++) {

		record.insert(make_pair(improve(a, 1), i));

	}
	multiset<pair<ll, pair<ll, ll>>>s;
	for (int rem = 0; rem < n - k; rem++) {
		pair<ll, int>p = *record.begin();
		record.erase(record.begin());
		s.insert(improve(p.first, p.second), make_pair(p.first, p.second));
	}

	for (auto p : s) {

		ans += values(p.second.first, p.second.second);
	}
	printf("%d", &ans );




	return 0;
}