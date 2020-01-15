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

const int MAXN = 2e5 + 5;
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
int dp[MAXN][2];
int n ;
vector<int> vect;

int maxx = 0;


int dist(pair<int, int> p) {
	return p.second - p.first;
}
void solve() {
	int maxx = 1 ;
	int len = 1 ;

	int tmpstart = 0 ;

	int start = 0 ;
	int end = 0 ;
	vector<pair<int, int>> sols ;
	sols.push_back({ -5, -10});
	for (int i = 1 ; i < n ; ++i) {
		//je suppose que je l'utilise
		if (vect[i] > vect[i - 1]) {
			len++;
		} else {

			//si je l'utilise
			if (maxx <= len) {

				maxx = len ;
			}
			start =  tmpstart;
			end = tmpstart + len ;
			sols.push_back({start, end});

			tmpstart = i;
			len = 1 ;
		}
		//
	}
	start =  tmpstart;
	end = tmpstart + len;
	maxx = len ;
	sols.push_back({start, end});

	sols.push_back({ -5, -10});
	sols.push_back({ -50, -100});
	sols.push_back({ -500, -1000});

	debugg(end - start);

	for (auto x : sols) {
		cout << x.first << " " << x.second << endl;
	}
	cout << endl;

	for (int i = start ; i < end ; ++i) {
		debug(i); debugg(vect[i]);
	}

	int answer = 0 ;
	for (int i = 1 ; i < sols.size() - 1 ; ++i) {
		answer = max(answer, dist(sols[i]));
		if ( sols[i].second == sols[i + 1].first  ) {
			
		}
		if ( sols[i].second == sols[i + 1].first && sols[i].second + 1 == sols[i + 2].first ) {
			answer = max(answer, dist(sols[i]) + dist(sols[i + 2]));
		}

	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n ;
	vect.resize(n);
	for (auto &x : vect) {
		cin >> x ;
	}

	solve();



	return 0;
}
