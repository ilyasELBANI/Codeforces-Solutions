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
vector<vector<pair<int, int>>> adj;

ll dijkstra(int s, vector<int> & d, vector<vector<int>> & p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, vector<int>());

	d[s] = 0;
	multiset<pair<int, int>> q;
	q.insert({0, s});
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				q.erase({d[to], to});
				d[to] = d[v] + len;
				p[to].clear();
				q.insert({d[to], to});
			}
			if (d[v] + len == d[to]) {
				p[to].push_back(v);
			}
		}
	}
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
	vector<int> path;

	for (int v = t; v != s; v = p[v])
		path.push_back(v);
	path.push_back(s);

	reverse(path.begin(), path.end());
	return path;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n , m ;
	cin >> n >> m ;
	adj.resize(n);

	for (int i = 0 ; i <  m ; ++i) {
		int u, v , w ;
		cin >> u >> v >> w ;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<int> d ;
	vector<vector<int>> p ;
	dijkstra(0, d, p);
	vector<int> path  =  restore_path(0, n - 1, p);

	for (auto x : path ) {
		cout << x << " ";
	}
	cout << endl;



	return 0;
}
