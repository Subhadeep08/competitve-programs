#include <bits/stdc++.h>
using namespace std;


int n, a, b, c;
void solve() {


    vector<int>res;

    assert(1 <= c && c <= n);
    assert(c <= a && a <= n);
    assert(c <= b && b <= n);

    if ((a + b - c) > n || ((a + b - c) == 1 && n > 2)) {
        cout << "IMPOSSIBLE";
    }
    else if (n == 1) {
        cout << "1 1";
    }
    else if (n == 2) {
        if (c == 1) {
            if (a > b) cout << "1 2"; else cout << "2 1";
        }
    }
    else {

        for (int i = 0; i < a - c; i++) res.push_back(2);
        for (int i = 0; i < c; i++)res.push_back(3);
        auto itr = res.begin() + 1;
        for (int i = 0; i < b - c; i++) res.push_back(2);
        int extra = n - (a + b - c);
        if (extra > 0) {

            res.insert(itr, extra, 1);
        }
    }

    for (int j : res) { cout << j << " ";}
    res = {};

}


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t;
    for (int i = 1; i < t; i++) {
        cin >> n >> a >> b >> c;
        cout << "Case #" << i  << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}