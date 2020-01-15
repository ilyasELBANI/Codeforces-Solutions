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
ll fastPower(ll x, ll y)
{
	ll res = 1;
	while (y > 0)
	{
		if (y & 1) {
			res = (res * x) ;
		}
 
		y = y >> 1;
		x = (x * x) ;
	}
	return res;
}
 
int n , k ;
ll randomXor;
struct VectorHasher {
    int operator()(const vector<pair<int,int>> &V) const {
        long long h=0;
        for(int i=0;i<V.size();i++) {
            h = h * MOD + V[i].first;
            h = h * MOD + V[i].second;
        }
        return std::hash<long long>()(h^randomXor);
    }
};
 
unordered_map<vector<pair<int,int>>, int,VectorHasher> myInversesMap;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;

 	randomXor = chrono::system_clock::now().time_since_epoch().count() * 21;

 
	ll ans = 0;
 
	for (int i = 0 ; i < n ; ++i) {
		int x ;
		cin >> x ;
		//factorize x
		ll cpy = x ;
		ll inv  = 1;
		ll me = 1 ;
 
		vector<pair<int, int>> fct;
		vector<pair<int, int>> fctinv;
 
		for (int i = 2 ; i * i <= 100000 ; i ++ ) {
			//pair< prime , exponant>
			pair<int, int> tmp = {i, 0};
			while (x % i == 0 ) {
				x /= i;
				tmp.first *= i;
				tmp.second++;
			}
			tmp.second %= k;
 
			if (tmp.second != 0 ) {
				fct.push_back({i, tmp.second});
				fctinv.push_back({i, k - tmp.second});
			}
		}
		if (x > 1) {
			fct.push_back({x, 1});
			fctinv.push_back({x, k - 1});
		}
 
		if (myInversesMap.count(fctinv)) {
			ans += (ll)myInversesMap[fctinv];
		}
		myInversesMap[fct]++;
	}
 
	cout << ans << endl;
 
	/*for(auto x : myInversesMap){
		cout << x.first << " " << x.second << endl;
	}*/
 
	return 0;
}