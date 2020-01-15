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


struct nd {
	int type;
	double valuePerGram;
	int NumberOfGrams;
	int VALUE;
};


bool cmp(nd& A , nd& B) {
	if (  A.valuePerGram == B.valuePerGram ) {
		return A.type < B.type;
	}
	return A.valuePerGram > B.valuePerGram ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , weightmax;


	cin >> n >> m >> weightmax;

	vector<nd> vect ;
	for (int i = 0 ; i < n ; ++i) {
		nd tmp;
		double C , W ;
		cin >> C >> W ;

		tmp.type = 0 ;
		tmp.valuePerGram  = C / W ;
		tmp.NumberOfGrams = W;
		tmp.VALUE = C ;
		vect.push_back(tmp);
	}

	for (int i = 0 ; i < m ; ++i) {
		nd tmp;
		double C , W ;
		cin >> C >> W ;

		tmp.type = 1 ;
		tmp.valuePerGram  = C ;
		tmp.NumberOfGrams = W;
		tmp.VALUE = C * W ;
		vect.push_back(tmp);

	}

	sort(all(vect), cmp);


	int val = 0 ;

	for (auto x : vect) {
		if (x.type == 0) {
			if (weightmax - x.NumberOfGrams >= 0) {
				val += x.VALUE;
				weightmax -= x.NumberOfGrams;
			}
		} else {
			int gramsToUse =  x.NumberOfGrams ; 
			if(gramsToUse > weightmax ){
				gramsToUse = weightmax; 
			}
			//debug(weightmax);debug(gramsToUse);
			val += x.valuePerGram * gramsToUse;
			weightmax -= gramsToUse;

		}
		//debugg(val);
	}

	//debugg(val);
	cout << val << endl;

	return 0;
}