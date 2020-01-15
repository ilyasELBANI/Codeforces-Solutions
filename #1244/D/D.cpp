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



int colors[100010][4];

vector<int> adj[100003];
int visited[100010];

int moves[100010];

void init(int start) {

	if (visited[start]) return;

	visited[start] = 1;
	if ( visited[adj[start][0]] == 0) {
		moves[start] = adj[start][0];
		init(adj[start][0]);
	}
	if (adj[start].size() > 1) {
		if ( visited[adj[start][1]] == 0) {
			moves[start] = adj[start][1];
			init(adj[start][1]);
		}
	}
}

int solColors[100100][7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n ;
	cin >> n ;

	for (int i = 1 ;  i <= 3  ; ++i) {
		for(int j = 1 ; j <= n ; j ++){
			cin >> colors[j][i];
		}
	}

	for (int i = 0 ; i < n - 1  ; ++i) {
		int x , y ;
		cin >> x >> y ;
		adj[x].push_back(y);
		adj[y].push_back(x);


		if (adj[x].size() > 2) {

			cout << -1 << endl;
			return 0;
		}

		if (adj[y].size() > 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	//find leaf;
	int start = -1;
	for (int i = 1 ; i <= n ; ++i) {
		if (adj[i].size() == 1) {
			start = i;
		}
	}
	memset(visited, 0 , sizeof(visited[0] * 100005));

	init(start);

	vector<ll> way(7, 0);

	vector<int> route[7];
	route[1] = { -1,   1, 2, 3};
	route[2] = { -1,   1, 3, 2};
	route[3] = { -1,   2, 3, 1};
	route[4] = { -1,   2, 1, 3};
	route[5] = { -1,   3, 1, 2};
	route[6] = { -1,   3, 2, 1};

	int cursor = 1;
	while (moves[start] != 0) {

		for (int i = 1 ; i <= 6 ; ++i) {
			way[i] += colors[start][route[i][cursor]];
			solColors[start][i] = route[i][cursor];
		}
		cursor++;
		if (cursor == 4) {
			cursor = 1 ;
		}
		start = moves[start];
	}

	for (int i = 1 ; i <= 6 ; ++i) {
		way[i] += colors[start][route[i][cursor]];
		solColors[start][i] = route[i][cursor];

	}

	ll minn = LLINF;
	int minpos = -1;
	for (int i = 1 ; i <= 6 ; ++i) {
		if(minn > way[i]){
			minn = way[i];
			minpos = i ;
		}
	}
	cout << minn << endl;
	for(int i = 1 ; i<= n ; ++i ){
		cout << solColors[i][minpos]<< " " ;
	}
	return 0;
}
