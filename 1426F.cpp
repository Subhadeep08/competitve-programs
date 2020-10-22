// problems from facebook hacker cup 2020
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int64_t  M = 1e7 + 7, N = 200002, k = 4;

int64_t  SubsequencesCount(string s) {

	int64_t dp[] = {1ll, 0ll, 0ll, 0ll};
	for (char ch : s) {

		if (ch == '?') {
			for (int64_t i = 3; i > 0; i--)
				dp[i] = (dp[i] * 3ll +  dp[i - 1]) % M;
			dp[0] = dp[0] * 3ll % M;
		}
		else dp[(int64_t)(ch - 'a' + 1)] = (dp[(int64_t)(ch - 'a' + 1)] + dp[(int64_t)(ch - 'a')]) % M;


	}

	cout << dp[3];
	return 0;

}



int32_t main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	SubsequencesCount(s);
	return  0;
}


