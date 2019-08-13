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
const long double EPS = 1e-9;
const long double PI = acos(-1);

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


struct vect {
	long double x;
	long double y;
	long double angle;
	int pos;

};

vector < vect > angles;

bool cmp (vect A, vect B ) {
	return A.angle < B.angle;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n ;
	cin >> n;
	cout << setprecision(10) << fixed ;
	for (int i = 0 ; i < n ; ++i) {
		vect tmp;
		tmp.pos = i + 1;
		cin >> tmp.x >> tmp.y ;
		tmp.angle = atan2(tmp.y, tmp.x) ;
		//debugg(tmp.angle);
		//tmp.angle = angle;
		//debugg(tmp.angle);
		//cout << endl;
		if (tmp.angle < 0 ) {
			tmp.angle += 2 * PI;
		}

		angles.push_back(tmp);
	}
	sort(all(angles), cmp) ;
	angles.push_back(angles[0]);
	/*	for (auto c : angles) {
			cout << c .angle << "\t" ;
		}
		cout << endl;
		for (auto c : angles) {
			cout << c .pos * 1.0 << "\t" ;
		}*/

	long double diff[n + 3];
	for (int i = 1 ; i < n + 1; ++i) {
		diff[i] =  angles[i].angle - angles[i - 1].angle  ;
		if (diff[i] < 0 ) {
			diff[i] += 2 * PI;
		}
		if (diff[i] > PI ) {
			diff[i] = 2 * PI - diff[i];
		}
	}
	//cout << endl;
	long double minimum = 555;
	int posmin = -1;

	for (int i = 1 ; i <= n ; ++i) {

		if (diff[i] < minimum ) {
			posmin = i ;
			minimum = diff[i];
		}
		//cout << diff[i] << "\t";
	}
//	cout << endl;

	cout << angles[posmin].pos << " " <<  angles[posmin - 1].pos << endl;



	return 0;
}
