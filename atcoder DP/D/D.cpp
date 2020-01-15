#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)((x).size())
#define debug(x) cout << #x << ":" << x << ' ';
#define debugg(x) cout << #x << ":" << x << ' ' << "\n";
#define endl "\n"
#define L(X) ((X)<<1)
#define R(X) (((X)<<1)|1)
#define M(X,Y) (((X)+(Y))>>1)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long int LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1);

template<typename T>   T max_self(T& a, T b) { if (a < b) a = b; return a; }
template<typename T>   T min_self(T& a, T b) { if (a > b) a = b; return a; }
template<typename T>   T add(T x, T y) { return ((x % MOD)  + (y % MOD)) % MOD;}
template<typename T>   T mul(T x, T y) { return ((x % MOD) * (long long)(y % MOD)) % MOD;}
template<typename T>   T sub(T x, T y) { return add(x, -y + MOD);}
template<typename T>   T gcd(T a, T b) { return b ? gcd(b, a % b) : a;}
template<typename T>   T lcm(T a, T b) { return a / gcd(a, b) * b;}
template<typename T>   vector<T> read(vector<T>& v, int n) {v.resize(n); for (auto &x : v)cin >> x;}
template<typename T>   void trav(vector<T> &v) {for (int i = 0 ; i < (int)v.size() ; ++i) {cout << v[i]; if (i != (int)v.size() - 1) cout << ' ';}}
int lg2(long long x)   {   return 64 - __builtin_clzll(x) - 1;	}
int lg2(int x)   {   return 32 - __builtin_clz(x) - 1;	}


//Variables Declaration
int N , W ;
vector<pair<ll, ll>> vect;

ll dp[110][MAXN];

ll solve(int n , int w) {
	if (dp[n][w] >= 0 ) return dp[n][w];
	if (n >= N) return 0;
	if (w == 0 ) return 0;

	if (w - vect[n].first < 0) return solve(n + 1, w);

	ll sol = 0;
	//debug(n);  debugg(w);
	sol = max( solve(n + 1, w) + 0 , solve(n + 1, w - vect[n].first) + vect[n].second );

	return dp[n][w] = sol ;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, 0, sizeof(dp));

	cin >> N >> W;
	vect.resize(N+1);

	for (int i = 1; i <= N; ++i)
	{
		pair<int,int> tmp;
		cin >> tmp.first >> tmp.second;
		vect[i]= tmp;
	}
	cout << solve(0, W) << endl;

/*
	for (int i = 1; i <=N; ++i) 	{
		for(int j = 0 ; j <= W ; ++j){
			if( j - vect[i].first >= 0 ){
				dp[i+1][j] = max ( dp[i+1][j] ,  dp[i][j-vect[i].first] + vect[i].second);
			}
			dp[i+1][j] = max(dp[i+1][j] , dp[i][j]);
		}
	}

	cout << dp[N+1][W] << endl;
*/

	return 0;
}
