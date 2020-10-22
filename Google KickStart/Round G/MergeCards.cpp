#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define ll              long long
#define lint             long long int
#define ull             unsigned long long
#define db              double
#define ldb             long double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


const int mxn = 5100;  int n;
ldb ans = 0; int dp[mxn][mxn];
vector<ll>arr(mxn);

//brute force solution---------------------------------------------------------------
// void bruteforcesolution(vector<ll> v, int score)
// {

// 	memset(dp, 0, sizeof(dp));
// 	vector<ll>temp;
// 	if (v.size() == 1) {
// 		cout << "hi";
// 		ans += score; return;
// 	}
// 	for (int i = 0; i < v.size(); i++) {
// 		for (int j = 0; j < v.size(); j++) {
// 			if (i == j) {
// 				temp.push_back(v[i] + v[i + 1]);
// 			}
// 			else if (j != i + 1) {
// 				temp.push_back(v[j]);
// 			}
// 		}

// 		bruteforcesolution(temp, score + v[i] + v[i + 1]);

// 	}

// }
// --------------------------------------------------------------------------------------

// dyanamic programming solution----------------------------------------------------------

void dpsolution() {
	double dp[n][n]; int sum[n][n];
	for (int i = 0; i < n; i++) {
		sum[i][i] = arr[i]; dp[i][i] = 0;
	}
	for (int width = 2; width <= n; width++) {
		for (int left = 0, right = width - 1; right < n; left++, right++) {
			sum[left][right] = sum[left][left] + sum[left + 1][right];
			dp[left][right] = (width - 1) * sum[left][right] ;
			for (int x = left; x < right; x++) {
				dp[left][right] +=  dp[left][x] + dp[x + 1][right] ;
			}
			dp[left][right] /= (width - 1);
		}
	}
	cout << dp[0][n - 1];

}
// ------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	// freopen("error.txt", "w", stderr);
// 	freopen("output.txt", "w", stdout);
// #endif
	int test;
	cin >> test >> n;


	for (int tr = 1; tr <= test; tr++)
	{
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << "Case #" << tr << ": ";
		// bruteforcesolution(arr, 0);
		dpsolution();
		cout << setprecision(6);
		cout << fixed;
		cout << ans;
		cout << "\n";
	}
	//cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}