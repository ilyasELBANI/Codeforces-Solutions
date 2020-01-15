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
const ll MOD = 1e9 + 7;
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
struct mat{
	ll a[3][3];
	mat(){
		a[0][0] = 28 ;
		a[0][1] = -175 ;
		a[0][2] = 300 ;
		a[1][0] = 1 ;
		a[1][1] = 0 ;
		a[1][2] = 0 ;
		a[2][0] = 0 ;
		a[2][1] = 1 ;
		a[2][2] = 0 ;
	}

	mat operator*(const mat &m) const{
		mat ret ; 
		for(int i = 0 ; i < 3 ; ++i){
			for( int j = 0 ; j < 3 ; ++j){
				ll &sum = ret.a[i][j] = 0;
				for(int k = 0 ; k < 3 ; ++k){
					sum = add(sum , mul( a[i][k] , m.a[k][j])) ;
				}
			}
		}
		return ret;
	}
};

mat bp( mat m , ll p){
	if ( p == 1 ) return m ;
	mat tmp = bp(m, p >> 1 );
	tmp = tmp * tmp;
	return (p%2==0)? tmp : (tmp*m);
}

ll dp[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

 	int q ;
 	cin >> q ;

 	while(q--){
 		vector<ll> u(4,0);
 		ll n;

 		for(int i = 0 ; i < 3 ; ++i){
 			cin >> u[i] ;
 		}
 		cin >> n ;

 		if(n <= 3) {
 			cout << u[n-1] << endl;
 			continue;
 		}

 		mat m; 

 		m = bp(m,n-3);

 		ll res = 0;
 		for (int i = 0  ; i < 3 ; ++i){
 			res = add(res,mul(m.a[0][i] , u[i]));
 		}

 		// debugg(res);
 		if(res <0 ) res+= MOD;
 		cout << res << endl;

 	}





	return 0;
}
