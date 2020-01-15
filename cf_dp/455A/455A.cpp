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

ll dp[MAXN][2];
ll dp2[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

 	int n ;
 	cin >>n ;
 	vector<ll> vect(n);
 	vector<ll> count(MAXN);
 	for(auto &x : vect){
 		cin >> x ;
 		count[x]++;
 	}
 	memset(dp,0,sizeof(dp));
 	int max_elt = *max_element(all(vect));
 	
 	dp2[0] = 0;
 	dp2[1] = count[1];
 	for(int i = 2 ; i <= max_elt ; ++i ){
 		//delete
 		// dp[i][1] = dp[i-1][0] + i * count[i] ; 
 		//don't delete
 		// dp[i][0] = max(dp[i-1][1],dp[i-1][0]);

 		dp2[i] = max(dp2[i-1], dp2[i-2] + i * count[i] );
 	}

 	// cout << max(dp[max_elt][0],dp[max_elt][1]) << endl ; 
 	cout << dp2[max_elt] << endl;


	return 0;
}
