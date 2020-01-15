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
pair<int, int> win;
vector<string> mat ;

struct robot {
	int x;
	int y;
	int id;

	robot(int xx , int yy , int idd) {
		x = xx ;
		y = yy ;
		id = idd;
	}

	robot(const robot &r ) {
		x = r.x;
		y = r.y;
		id = r.id;
	}
	void print() {
		debug(id); debug(x); debugg(y);
	}
	string hashString() {
		string tmp = "";
		tmp += id + '0';
		tmp += x + '0';
		tmp += y + '0';
		tmp += '-';
		return tmp;
	}
};

bool operator<(const robot& a, const robot& b ) {
	return a.id < b.id || (a.x < b.x && a.y < b.y);
}

vector<robot> robots;

bool isObstacle(int id, int x, int y) {
	if (x < 0) return true;
	if (y < 0) return true;
	if (x >= h) return true;
	if (y >= w) return true;
	if (mat[x][y] == 'W') return true;
	if (mat[x][y] == id + '0') return false;
	if (mat[x][y] >= '1' && mat[x][y] <= '4')  return true;

	return false;

}
string myHash;
string vectorToString(vector<robot> robots) {
	string tmp = "";
	for (auto x : robots) {
		tmp += x.hashString();
	}
	return tmp;
}

void solve() {
	map<string,int> States;

	queue<vector<robot>> q ;
	States[vectorToString(robots)] = 0;
	bool ok = false;
	int sol = 0 ;
	q.push(robots);
	while ( !q.empty()) {
		vector<robot> vect = q.front();
		q.pop();

		robot r1 = vect[0];
		int moves = States[vectorToString(vect)];
		// r1.print();

		if (r1.x = win.first && r1.y == win.second) {
			// r1.print();
			sol = moves;
			ok = true;
			break;
		}

		for (auto r : vect) {
			mat[r.x][r.y] = r.id + '0';
		}

		for (auto r : vect) {
			vector<robot> newStateUP(vect);
			vector<robot> newStateDOWN(vect);
			vector<robot> newStateLEFT(vect);
			vector<robot> newStateRIGHT(vect);
			//up
			int up = 0;
			while (!isObstacle(r.id, r.x + up, r.y)) {
				up++;
			}
			up--;
			newStateUP[r.id - 1].x = r.x + up;
			myHash = vectorToString(newStateUP);
			if (States.count(myHash) == 0) {
				// debugg(myHash);
				q.push(newStateUP);
				States[myHash] = moves +1 ;
			}

			//down
			int down = 0;
			while (!isObstacle(r.id, r.x - down, r.y)) {
				down++;
			}
			down--;
			newStateDOWN[r.id - 1].x = r.x - down;
			myHash = vectorToString(newStateDOWN);
			if (States.count(myHash) == 0) {
				// debugg(myHash);
				q.push(newStateDOWN);
				States[myHash] = moves +1 ;
			}

			//up
			int right = 0;
			while (!isObstacle(r.id, r.x, r.y + right)) {
				right++;
			}
			right--;
			newStateRIGHT[r.id - 1].y = r.y + right;


			myHash = vectorToString(newStateRIGHT);

			if (States.count(myHash) == 0) {

				// debugg(myHash);
				q.push(newStateRIGHT);
				States[myHash] = moves +1 ;
			}

			//up
			int left = 0;
			while (!isObstacle(r.id, r.x, r.y - left)) {
				left++;
			}
			left--;
			newStateLEFT[r.id - 1].y = r.y - left;
			myHash = vectorToString(newStateLEFT);
			if (States.count(myHash) == 0) {
				// debugg(myHash);
				q.push(newStateLEFT);
				States[myHash] = moves +1 ;
			}

			// debugg(vect.second);
			// debugg(vectorToString(vect.first));
			// debugg(vectorToString(newStateUP));
			// debugg(vectorToString(newStateDOWN));
			// debugg(vectorToString(newStateLEFT));
			// debugg(vectorToString(newStateRIGHT));
			// cout << "#################" << endl;
		}

		// while(!q.empty()){
		// 	auto x = q.front();
		// 	q.pop();
		// 	for(auto elt : x){
		// 		elt.print();
		// 	}
		// 	cout << endl ;
		// }
		for (auto r : vect) {
			mat[r.x][r.y] = '.';
		}

	}

	debugg(sol);
	debugg(l);

	if (!ok) {
		cout << "NO SOLUTION" << endl;
	} else {
		debug(l); debugg(original);
	}

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
			if (mat[i][j] >= '1' && mat[i][j] <= '4') {
				robot r (i , j , mat[i][j] - '0');
				robots.push_back(r);
				mat[i][j] = '.';
			}
		}
	}

	sort(all(robots));
	for (auto x :  robots) {
		x.print();
	}
	cout << " __________________________  " << endl;
	// for(int i = 0 ; i < sz(robots) ; ++i){
	// 	debug(robots[i].x);
	// 	debug(robots[i].y);
	// 	debugg(robots[i].id);
	// }

	solve();







	return 0;
}
