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


int n , w , h, l, original;
vector<string> mat ;
vector<pair<int, int>> robots(1);
pair<int, int> win ;

int dx[] = { 1, -1, 0, 0};
int dy[] = { 0, 0, 1, -1};

bool isValid(int x , int y, vector<pair<int, int>> &state, int r_id) {
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= h) return false;
	if (y >= w) return false;
	if (mat[x][y] == 'W') return false;

	for (int i = 0 ; i < sz(state) ; ++i) {
		if (i != r_id) {
			if (state[i].first == x && state[i].second == y) {
				return false;
			}
		}
	}

	return true;
}
int solve() {
	set<vector<pair<int, int>>> alreadyDone;
	queue<pair<vector<pair<int, int>>, int>> q ;

	q.push({robots, 0});
	alreadyDone.insert(robots);

	while (!q.empty()) {
		// debugg(q.size());
		pair<vector<pair<int, int>>, int> curr = q.front();
		q.pop();

		if (curr.first[0].first == win.first && curr.first[0].second == win.second) {
			return curr.second;
		}
		if (curr.second == l ) continue;
		for (int r_id = 0 ; r_id < sz(curr.first) ; ++r_id) {
			//r_id ROBOT TO MOVE!
			for (int mv = 0 ; mv < 4 ; ++mv ) {
				vector<pair<int, int>> State = curr.first ;
				int x = State[r_id].first + dx[mv];
				int y = State[r_id].second + dy[mv];
				// cout << "RID: " << r_id << std::flush << endl; 
				while (isValid(x, y, State, r_id)) {
					// debug(r_id); debug(x);debugg(y); cout << std::flush;
					x += dx[mv];
					y += dy[mv];
				}
				x -= dx[mv];
				y -= dy[mv];
				State[r_id].first = x;
				State[r_id].second = y;

				if(alreadyDone.count(State)==0){
					alreadyDone.insert(State);
					q.push({State,curr.second+1});
				}
			}
			// cout.flush();
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> w >> h >> l ;
	original = l ;
	mat.resize(h);
	for (int i = 0 ; i < h  ; ++i) {
		cin >> mat[i];
		for (int j = 0  ; j < w ; ++j) {
			if (mat[i][j] == 'X') {
				win.first = i ;
				win.second = j ;
			}
			if (mat[i][j] == '1') {
				robots[0] = {i, j};
				mat[i][j] = '.';
			}
			if (mat[i][j] >= '2' && mat[i][j] <= '4') {
				robots.push_back({i, j});
				mat[i][j] = '.';
			}
		}
	}

	// for(auto x: mat){
	// 	cout << x << endl; 
	// }
	// for(auto x : robots){
	// 	debug(x.first);
	// 	debugg(x.second);
	// }

	int ans = solve();
	if(ans == -1){
		cout << "NO SOLUTION" << endl;
	}else{
		cout << ans << endl;
	}
	return 0;
}
