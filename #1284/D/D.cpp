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

	vector<pair<int, int>> a(n) ;
	vector<pair<int, int>> a2(n) ;
	vector<pair<int, int>> b(n) ;
	vector<pair<int, int>> b2(n) ;

	set<int> a_set;
	set<int> b_set;

	for (int i = 0 ; i < n ; ++i) {
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second ;
		a_set.insert(a[i].first);
		a_set.insert(a[i].second);
		b_set.insert(b[i].first);
		b_set.insert(b[i].second);
	}

	map<int,int> a_map;
	map<int,int> b_map;

	int i = 0;
	for(auto x : a_set){
		a_map[x] = i++;
	}
	i = 0;
	for(auto x : b_set){
		b_map[x] = i++;
	}

	for(int i= 0 ; i < n ; ++i){
		a2[i].first = a_map[a[i].first];
		a2[i].second = a_map[a[i].second];
		b2[i].first = b_map[b[i].first];
		b2[i].second = b_map[b[i].second];
	}

	sort(all(a2));
	sort(all(b2));
	if(a2==b2){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	// if (a_sol == b_sol) {
	// 	cout << "YES" << endl;
	// }
	// else {
	// 	cout << "NO" << endl;
	// }


	return 0;
}
