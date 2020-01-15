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
bool cmp(string& A, string& B) {
	if (A.front() == B.front()) {
		if (A.back() == B.back()) {
			string tmpA = A.substr(1, sz(A) - 2 );
			string tmpB = B.substr(1, sz(B) - 2 );
			return tmpA < tmpB ; 
		} else {
			return A.back() < B.back();
		}
	}
	return A.front() < B.front();
}

int fact[1001];
void initFact(){
	fact[0] = 1 ;
	fact[1] = 1 ;
	for(int i = 2 ; i <= 1000 ; ++i){
		fact[i] = i * fact[i-1];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	initFact();

	string s ;

	int n ;
	cin >> n ;

	for (int i = 1 ; i <= n ; ++i) {
		s += i + '0';
	}


	vector<string> mySols ;

	do {
		// debugg(s);
		if (find(all(mySols), s) == mySols.end() && find(all(mySols), string(s.rbegin(), s.rend())) == mySols.end()) {
			mySols.push_back(s);
		}
	} while (next_permutation(all(s)));

	debugg(mySols.size());
	sort(all(mySols), cmp);
	cout << "###############################################" << endl;

	vector<int> vect(n+1);
	for (auto x :  mySols) {
		for (auto c : x ) {
			cout << c << " " ;
		}
		cout << endl;
		vect[x[0]-'0']++;
	}

	cout << "###############################################" << endl;
	debugg(mySols.size());
	for(int i = 1 ; i <= n ; ++i){
		cout << i << " : "  << vect[i] << endl;
	}

	cout << "############# My solution ############# " << endl;

	ll sol = 0 ;
	ll sol2= 0;
	for(int i = 0 ; i <= n-1 ; ++i){
		sol += fact[n-1] - fact[n-2]*i;
		sol2 += - fact[n-2]*i;
	}
	sol2+= fact[n];
	debugg(sol);
	debugg(sol2);

	ll sol3 = fact[n] - fact[n-2] * (n * (n-1))/2;
	debugg(sol3);

	ll sol4 = (fact[n] ) /2 ;
	debugg(sol4);

	return 0;
}
