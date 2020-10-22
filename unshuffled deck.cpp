#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
// #define int long long
#define ld long double
#define endl 	 "\n";

const int mod = 1000000007;
using namespace std;
using namespace std::chrono;
int n;
vector<int>deck(52);

void renewdeck(std::vector<int> v) {
	vector<int>newdeck(n, 0); int count = 0;
	for (int len : v) {
		for (int i = 0; i < len; i++ ) {
			newdeck[n - 1 - i - count] = deck[count + i];
		}
		count += len;
	}
	deck.clear();
	deck = newdeck;
}

void solve() {

	vector<vector<int>>ops;
	vector<int>op;
	auto find = [&](int x) {
		for (int i = 0; i < n; i++)
			if (deck[i] == x) return i;
	};


	for (int i = 1; i < n && !(is_sorted(deck.begin(), deck.end())) ; i++) {
		int j;
		int locate = find(1);
		if (locate != 0 && locate != n - 1) {
			for ( j = locate + 1; j < n; j++)
				if (deck[j] == i + 1)
					break;

			if (j <= n - 1) {
				op.push_back(locate);
				if (j - locate - i)op.push_back(j - locate - i); else op.push_back(i);
				op.push_back(n - 1 - j + 1);
			}
			else {
				for ( j = locate - 1; j >= 0; j--) if (deck[j] == i) break;
				if (j == 0) { op.push_back(locate - j); op.push_back(i); if (n - locate - i)op.push_back(n - locate - i);}
				else { op.push_back(j); op.push_back(j - locate); op.push_back(i); if (n - locate - i) op.push_back(n - locate - i); }

			}
		}
		else if (locate == 0) {
			for (j = 1; j < n; j++) {
				op.push_back(j);
				op.push_back(n - j);
			}
		}
		else if (locate == n - 1) {
			for (j = locate - 1; j >= 0; j--)if (deck[j] == i) break;
			if (j == 0) {op.push_back(locate - j); op.push_back(1);}
			else {op.push_back(j); op.push_back(j - locate); op.push_back(1);}
		}

		ops.push_back(op);
		renewdeck(op);
		op.clear();
	}

	cout << ops.size() << "\n";
	for (auto op : ops) {
		cout << op.size() << " ";
		for (int itr : op) {
			cout << itr << " ";
		}
		cout << "\n";
	}
}


int main() {
	auto start = high_resolution_clock::now(); // starting clock
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> deck[i];
	}
	solve();

	auto stop = high_resolution_clock::now(); // stop clock
	auto duration = duration_cast<microseconds>(stop - start); // printing duration
	cerr << "Time taken by function: " << duration.count() << " milliseconds" << endl;
	return 0;
}

// authors solution


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); // Remove in problems with online queries!

//     cin >> N;
//     for (int i = 0; i < N; i++) cin >> deck[i];

//     if (is_sample()) return 0;

//     vector<vector<int>> ops;
//     while (1) {
//         vector<int> op;
//         for (int i = 0; i < N; i++) {
//             if (deck[i] == i+1) continue;
//             if (i != 0) op.push_back(i);
//             for (int j = i+1; j < N; j++) {
//                 if (deck[j] == deck[j-1] + 1) continue;
//                 op.push_back(j-i);
//                 for (int k = j; k < N; k++) {
//                     if (deck[k] != deck[i]-1) continue;
//                     op.push_back(k-j+1);
//                     if (k < N-1) op.push_back(N-1-k);
//                     break;
//                 }
//                 break;
//             }
//             break;
//         }
//         if (op.empty()) break;
//         ops.push_back(op);
//         make_op(op);
//     }

//     cout << ops.size() << "\n";
//     for (auto op: ops) {
//         cout << op.size() << " ";
//         for (int x: op) cout << x << " ";
//         cout << "\n";
//     }
// }

