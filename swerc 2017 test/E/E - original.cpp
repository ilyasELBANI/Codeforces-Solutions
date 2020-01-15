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

int STUDENTS;
int N_FC, K_FC , D_FC, N_TEACHERS_FC ;
int N_IC, K_IC , D_IC, N_TEACHERS_IC ;

set<int> conflicts[3000];

struct node {
	ll DAY ;
	ll H_START ;
	ll M_START ;
	ll startTime;
	ll endTime;
	ll T_ID ;
	int TYPE;
	int ID;

	node(int id, ll day, ll hstart, ll mstart, ll t_id, int type) {
		ID = id;
		DAY 	= day ;
		H_START = hstart ;
		M_START = mstart ;
		T_ID 	= t_id ;
		startTime = H_START * 60 + M_START;
		if (type == 0 )		{
			endTime = startTime + D_FC * 60 + 5  ;
		} else {
			endTime = startTime + D_IC * 60 + 5  ;
		}
		TYPE = type;
	}
};
int src = 0;
int target ;
vector<node> Cours;
vector<vector<int>> capacity ;
vector<vector<int>> adj ;

void generateGraph() {
	for (int i = 0 ; i < sz(Cours) ; ++i) {
		if (Cours[i].TYPE == 0) {
			capacity[0][Cours[i].ID] = K_FC ;
			adj[src].push_back(Cours[i].ID);
			adj[Cours[i].ID].push_back(src);
		} else {
			capacity[Cours[i].ID][target] = K_IC ;
			adj[Cours[i].ID].push_back(target);
			adj[target].push_back(Cours[i].ID);
		}
	}
	for (int i = 0 ; i < Cours.size() ; ++i) {
		for (int j = i + 1 ; j < Cours.size() ; ++ j) {
			if (Cours[i].TYPE == Cours[j].TYPE) continue;

			bool flag = false;
			if (Cours[i].endTime <= Cours[j] .startTime) flag = true;
			if (Cours[j].endTime <= Cours[i] .startTime) flag = true;
			if (conflicts[Cours[i].T_ID].count(Cours[j].T_ID) ) flag = false;
			if (flag == false ) continue;

			adj[i].push_back(j);
			adj[j].push_back(i);
			capacity[i][j] = INF;
		}
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	capacity.resize(2200, vector<int>(2200));

	cin >> STUDENTS;

	cin >> N_FC >> K_FC >> D_FC >> N_TEACHERS_FC ;
	int id = 1 ;
	for (int i = 0 ; i < N_FC ; ++i) {
		ll d , hstart, mstart, t_id;
		cin >> d >> hstart >> mstart >> t_id;
		node e =  node(id++, d, hstart, mstart, t_id, 0);
		Cours.push_back(e);
	}

	cin >> N_IC >> K_IC >> D_IC >> N_TEACHERS_IC ;
	id = 1001;
	for (int i = 0 ; i < N_FC ; ++i) {
		ll d , hstart, mstart, t_id;
		cin >> d >> hstart >> mstart >> t_id;
		node e =  node(id++, d, hstart, mstart, t_id, 1);
		Cours.push_back(e);

	}
	 target = Cours.size();

	int nbrConflits;
	cin >> nbrConflits;
	for (int i = 0  ; i < nbrConflits ; ++i) {
		int FC_T, IC_T;
		cin >> FC_T  >> IC_T;
		conflicts[FC_T].insert(IC_T);
	}


	generateGraph();

	debugg(maxflow(src,target));




	return 0;
}
