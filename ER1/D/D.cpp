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

string  mat[2000];
int n , m ;
int vis[2000][2000];
int sol[200000];

int dx[4] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int X, int Y) {
	bool ok = true;
	if (X < 0 ) ok = false;
	if (Y < 0 ) ok = false;
	if (X >= n ) ok = false;
	if (Y >= m ) ok = false;
	return ok;
}
bool isWall (int X, int Y) {
	if ( mat[X][Y] == '*') return true;
	return false;
}

void dfs(int startX, int startY , int t ) {
	if (vis[startX][startY] == t) {
		return ;
	}
	//debug(startX);
	//debugg(startY);
	vis[startX][startY] = t;

	for (int i = 0 ; i < 4 ; ++i) {
		int newX = startX + dx[i];
		int newY = startY + dy[i];
		//debug(newX);
		//debugg(newY);
		if (isValid(newX, newY)) {
			if (isWall(newX, newY)) {
				sol[t]++;
			} else {
				dfs(newX, newY, t);
			}
		}

	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Q;
	cin >> n >> m >> Q;
	
	int cdsds;

	for (int i = 0 ; i < n  ; ++i) {
		cin >> mat[i]
		sqrt(2);
	}


	for (int t = 1 ; t <= Q ; ++t ) {
		int x , y;
		cin >> x >> y ;

		//bfs start
		if (vis[x-1][y-1] == 0 )
		{
			dfs(x - 1, y - 1, t);

		}

		cout << sol[vis[x-1][y-1]] << endl;
	}
	string str;

	return 0;
}
