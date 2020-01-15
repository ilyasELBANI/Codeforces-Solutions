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
int n ;
string s ;
int  q;
int a;
char x ;

vector<vector<int>> charCount(26);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >>  n ;
	cin >> s ;

	for (auto & x : charCount) {
		x.resize(s.size());
	}

	for (int i = 0 ; i < sz(s); ++i) {
		for (int x = 0 ; x < 26 ; ++x) {
			if (i == 0 ) {
				charCount[x][i] = 0;
			} else {
				charCount[x][i] = charCount[x][i - 1];
			}
			if (s[i] - 'A' == x ) {
				charCount[x][i]++;
			}
		}
	}


	/*for(int x = 0 ; x < 26 ; ++x){
		cout << (char) (x+'A') << " : ";
		for(int i = 0 ; i < sz(s) ; ++i){
			cout << charCount[x][i];
		}
		cout << endl;
	}*/

	cin >> q ;

	while (q--) {
		cin >> a >> x ;
		debug(a); debugg(x);

		int start = ((a - 1) * a ) / 2;
		int end = ((a + 1) * a) / 2 ;

		debug(start);
		debug(end);
		debugg(end-start);

		int tmpstart = start % sz(s);
		int tmpend = (end) % sz(s);
		// if (tmpend < tmpstart) {
		// 	tmpend += sz(s);
		// }
		debug(tmpstart); debugg(tmpend);

		cout << endl;

	}







	return 0;
}
