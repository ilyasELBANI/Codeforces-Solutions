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
int lg2(unsigned long long x)   {   return 64 - __builtin_clzll(x) - 1;	}
int lg2(int x)   {   return 32 - __builtin_clz(x) - 1;	}


//Variables Declaration


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll X , Y ;
	cin >> X >> Y;


	ll answer = 0 ;

	int curr = 0;

	ull  value = 0;
	ull  a_tmp ;

	ull nani =(1ll << 63) - 1ll;

	set<ull> answers;
	for (int A = 1 ; A <= 63 ; ++A ) {
		a_tmp = (1ll << A) - 1ll;

		for (int B = 1 ; B <= 63 ; ++ B ) {
			if (A + B > 63 ) continue;
			value = 0 ;
			bool Aturn = 1;
			for (int k = 1 ; k <= 63 ; ++k) {

				if (Aturn) {
				
					value <<= A ;
					value += a_tmp;
					Aturn = !Aturn;
					if ( X <= value && value <= Y) {
						answers.insert(value);
					}

				} else {
			
					value <<= B;
					Aturn = !Aturn;
					if ( X <= value && value <= Y) {
						answers.insert(value);
					}
				}

			}

			//debugg(tmp.to_ullong());
		}
	}

	a_tmp = (1ll << 63) - 1ll;

	if ( X <= a_tmp && a_tmp <= Y) {
		answers.insert(value);
	}

	cout << answers.size() << endl;
	return 0;
}
