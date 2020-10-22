
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char testcase();
int main () {
	std::ios_base::sync_with_stdio(false);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t; scanf("%d", &t);

	for (int  tr = 1; tr <= t; tr++)
	{

		cout << "Case #" << tr << ": " << testcase();
		// char ch = testcase(); cout << ch;

		cout << "\n";

	}

	return 0;
}
char testcase() {

	int nax = 1e6 + 5;
	char str[nax]; int n;
	scanf("%d", &n);
	scanf("%s", &str);
	int count_a = 0, count_b = 0;


	for (int i = 0; i < n; i++) {
		if (str[i] == 'A')
			count_a++;
		else if (str[i] == 'B')
			count_b++;
	}
	if (abs(count_a - count_b) == 1)
		return 'Y';
	else return 'N';


}

