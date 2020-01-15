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

const int MAXN = 3005;
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
string s, t ;

int dp[MAXN][MAXN];

ll solve(int i , int j ) {
	if (i >= sz(s) ) return 0;
	if (j >= sz(t) ) return 0;
	if (dp[i][j] > 0 ) {
		return dp[i][j];
	}

	ll ans = 0;
	if (s[i] == t[j]) {
		ans = max(ans, solve(i + 1, j + 1) + 1) ;
	} else {
		ans = max(ans, solve(i + 1, j) );
		ans = max(ans, solve(i, j + 1) );
	}

	return dp[i][j] = ans ;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	memset(dp, 0, sizeof(dp));

	cin >> s >> t ;

	s =  s;
	t =  t;

	cout << "BEFORE" << endl;
	cout << solve(0, 0) << endl ;
	cout << "AFTER" << endl;

	int i = 0, j = 0;
	string res = "";


	for (int i = 0 ; i < sz(s) ; ++i) {
		for (int j = 0 ; j < sz(t) ; ++j) {
			cout << dp[i][j] << "\t" ;
		}
		cout << endl;
	}

	while ( i < sz(s) &&  j < sz(t) ) {
		if (s[i] == s[j]) {
			res += s[i];
			i++, j++;
		} else {
			if ( dp[i + 1][j] > dp[i][j + 1]) {
				i++;
			} else {
				j++;

			}
		}
	}

	debugg(res);

	return 0;
}
