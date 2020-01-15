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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n ;
	cin >> n ;

	string s ;
	cin >> s;

	char c = s[0];
	bool ok = true ;
	for (auto x : s) {
		if (x != c) {
			ok = false;
		}
	}

	if (ok) {
		cout << 0 << endl;
		return 0 ;
	}

	//try everything white

	string s1 = s ;
	vector<int> moves ;

	for (int i = 0 ; i < n - 1 ; ++i ) {
		if (s1[i] == 'B' && s1[i + 1] == 'B') {
			moves.push_back(i);
			s1[i] = s1[i + 1] = 'W';
		}
	}
	for (int i = 1 ; i < n ; ++i) {
		if (s1[i] == 'B') {
			if (s1[i - 1] == 'B') {
				continue;
			}
			int j = i ;
			while (s1[j - 1] == 'W') {
				s1[j - 1] = 'B';
				s1[j] = 'W';
				j--;
				moves.push_back(j);
			}
		}
	}
	for (int i = 0 ; i  < n - 1 ; ++i) {
		if (s1[i] == 'B' && s1[i + 1] == 'B') {
			moves.push_back(i);
			s1[i] = s1[i + 1] = 'W';
		}
	}


	string s2 = s;
	vector<int> moves2 ;
	for (int i = 0 ; i < n - 1 ; ++i ) {
		if (s2[i] == 'W' && s2[i + 1] == 'W') {
			moves2.push_back(i);
			s2[i] = s2[i + 1] = 'B';
		}
	}
	for (int i = 1 ; i < n ; ++i) {
		if (s2[i] == 'W') {
			if (s2[i - 1] == 'W') {
				continue;
			}
			int j = i ;
			while (s2[j - 1] == 'B') {
				s2[j - 1] = 'W';
				s2[j] = 'B';
				j--;
				moves2.push_back(j);
			}
		}
	}
	for (int i = 0 ; i  < n - 1 ; ++i) {
		if (s2[i] == 'W' && s2[i + 1] == 'W') {
			moves2.push_back(i);
			s2[i] = s2[i + 1] = 'B';
		}
	}

	if(min(sz(moves), sz(moves2)) > 3 *n ){
		cout << -1 << endl;
		return 0;
	}

	if (moves.size() < moves2.size()) {
		char c = s1[0];
		bool yes = true;

		for (auto x : s1) {
			if (x != c) {
				yes = false;
				break;
			}
		}
		if (yes) {
			cout << moves.size() << endl;
			for (auto x : moves) {
				cout << x + 1 << " ";
			}
			cout << endl;
			return 0;
		}

		yes = true ;
		c = s2[0];
		for (auto x : s2) {
			if (x != c) {
				yes = false;
				break;
			}
		}
		if (yes) {
			cout << moves2.size() << endl;
			for (auto x : moves2) {
				cout << x + 1 << " ";
			}
			cout << endl;
			return 0;
		}
	} else {
		char c = s2[0];
		bool yes = true;

		for (auto x : s2) {
			if (x != c) {
				yes = false;
				break;
			}
		}
		if (yes) {
			cout << moves2.size() << endl;
			for (auto x : moves2) {
				cout << x + 1 << " ";
			}
			cout << endl;
			return 0;
		}

		yes = true ;
		c = s1[0];
		for (auto x : s1) {
			if (x != c) {
				yes = false;
				break;
			}
		}
		if (yes) {
			cout << moves.size() << endl;
			for (auto x : moves) {
				cout << x + 1 << " ";
			}
			cout << endl;
			return 0;
		}
	}


	cout << -1 << endl;


	return 0;
}
