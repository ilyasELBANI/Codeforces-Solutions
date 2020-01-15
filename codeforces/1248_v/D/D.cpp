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
int n, m;
string s;

int getBeauty() {
	int sol = 0;

	for (int x = 0; x < n; ++x) {
		int cnt = 0;
		int y = x;
		while (y < x + n && cnt >= 0) {
			if (s[y] == '(') ++cnt;
			else --cnt;

			++y;
		}

		if (cnt == 0 && y == x + n) ++sol;
		if (cnt < 0) x = y - 1;
	}

	return sol;
}

int main() {
	

	scanf("%d" , &n );
	char s[10000];
	char s1[10000];
	scanf("%s",s);
	strcpy(s1,s);
	strcat(s,s1);

	int left = 1, right = 1;
	int sol = getBeauty();


	for (int i = 0 ; i < n  ; ++i) {
		for (int j = i ; j < n  ; ++j) {
			if (s[i] == s[j]) continue;
			swap(s[i], s[j]);
			swap(s[i + n], s[j + n]);
			int ans = getBeauty() ;
			
			if (ans > sol) {
				sol = ans ;
				left = i ;
				right = j ;
			}
			swap(s[i], s[j]);
			swap(s[i + n], s[j + n]);
		}
	}

	//cout << sol << endl;
	//cout << left   << " " << right   << endl;
	printf("%d\n%d %d", sol , left, right);



	return 0;
}
