#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)((x).size())
#define debug(x) cout << #x << ":" << x << ' ';
#define debugg(x) cout << #x << ":" << x << ' ' << "\n";
#define endl "\n"

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

struct node {
	int id;
	int x;
	int y;
	vector<int> courses;
};

vector<node> resto;

node  tmp;
vector<node> listrestaurantPourPlat[21];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int C, R , B;
	cin >> C >> R >> B;

	tmp.id = -1;
	resto.push_back(tmp);
	for (int i = 0 ; i < R ; ++i) {
		tmp.courses.clear();
		tmp.id = i + 1;
		cin >> tmp.x >> tmp.y ;
		tmp.courses.push_back(-1);
		for (int j = 0 ; j < C ; ++j) {
			int c;
			cin >> c ;
			tmp.courses.push_back(c);
		}
		resto.push_back(tmp);
	}

	for (int i = 1 ; i <= R ; ++i) {
		for (int j = 1 ; j <= C ; ++j) {
			if (resto[i].courses[j] != 0 ) {
				listrestaurantPourPlat[j].push_back(resto[i]);
			}
		}
	}

	const int MAXX = 110;

	//dp [course][Restaurant][budgetutilisé]
	int dp[21][MAXX][MAXX];
	memset(dp, -1, sizeof(dp[0][0][0]) * 21 * MAXX * MAXX);
	//cout << dp [2][2] << endl;
	//init

	for (auto x : listrestaurantPourPlat[1]) {
		dp[1][x.id][x.courses[1]] = 0;
	}


	int minn = INF ;
	
	for (int k = 2 ; k <= C ; ++k) {
		for (auto r_before : listrestaurantPourPlat[k - 1]) {
			for (int i = 1; i <= 100 ; ++i) {
				//temps actuel pour budget i : dp[r.id][i]
				if (dp[k - 1][r_before.id][i] >= 0) {
					for (auto r_curr : listrestaurantPourPlat[k]) {
						if (i + r_curr.courses[k] > B ) {
							continue;
						}
						if(dp[k][r_curr.id][i + r_curr.courses[k]] !=-1){
							dp[k][r_curr.id][i + r_curr.courses[k]] = min( dp[k][r_curr.id][i + r_curr.courses[k]] , dp[k - 1][r_before.id][i] + abs( r_before.x - r_curr.x) + abs( r_before.y - r_curr.y));
						}
						else
						dp[k][r_curr.id][i + r_curr.courses[k]] = dp[k - 1][r_before.id][i] + abs( r_before.x - r_curr.x) + abs( r_before.y - r_curr.y);
					}
				}
			}
		}
	}

	for (int i = 1 ; i <= R ; ++i) {
		for (int j = 1 ; j <= B ; ++j) {
			if (dp[C][i][j] == -1) continue;
			minn = min(minn , dp[C][i][j]);
			//debugg(dp[C][i][j]);
		}
	}
	
	//debugg(minn);
	if(minn == INF) cout << -1 << endl ;
	else 
		cout << minn << endl;
	return 0;
}
