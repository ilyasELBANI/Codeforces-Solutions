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



//AUCUNE GESTION DE MEMOIRE AVEC FREE ... la flemme
//TO_DO : Gerer la destruction

struct Edge {
	int from, to ;
	// residual_ptr is the inverse edge TO --> FROM which contain the residual
	Edge* residual_ptr;
	ll flow, capacity;

	Edge(int from, int to , ll capacity) {
		this->from = from;
		this->to = to;
		this->capacity = capacity;
		this->flow = 0;
	}

	bool isResidual() {
		return capacity == 0;
	}

	ll remainingCapacity() {
		return capacity - flow;
	}

	void augment(ll minFlowInPath) {
		flow += minFlowInPath;
		residual_ptr->flow -= minFlowInPath;
	}
};


struct NetworkFlowBase {
	//n == nodes INCLUDING Source and Sink
	//s == source
	//t == target (sink)
	int n , s , t ;

	ll maxFlow;
	vector<vector<Edge*>> adjListEdges;

	vector<int> visited;

	bool alreadySolved = false;


	//n number of nodes INCLUDING SOURCE AND SINK
	static int visitedValidation;

	NetworkFlowBase(int n , int s , int t ) {
		this->n = n ;
		this->s = s ;
		this->t = t ;
		this->maxFlow = 0;

		adjListEdges.resize(n, vector<Edge*>());
		visited.resize(n, 0);
	}

	void addEdge(int from, int to , int capacity) {
		Edge* edgeFromTo = new Edge(from, to, capacity);
		Edge* edgeToFrom = new Edge(to, from, 0);

		edgeFromTo->residual_ptr = edgeToFrom;
		edgeToFrom->residual_ptr = edgeFromTo;

		adjListEdges[from].push_back(edgeFromTo);
		adjListEdges[to].push_back(edgeToFrom);
	}

	void visit(int i ) {
		visited[i] = visitedValidation;
	}

	bool isVisited(int i ) {
		return visited[i] == visitedValidation;
	}

	void markAllNodesUnvisited() {
		visitedValidation++;
	}

	ll executeMaxFlow() {
		if (alreadySolved) return maxFlow;
		alreadySolved = true;
		solve();
		return maxFlow;
	}

	virtual void solve() = 0;
};
int NetworkFlowBase::visitedValidation = 1;


struct FordFulkersonDFSsolverAdjList : NetworkFlowBase {
	FordFulkersonDFSsolverAdjList(int n , int s , int t)
		: NetworkFlowBase(n, s, t) {
	};

	void solve() {
		//for ( ll f = dfs(s,LLINF) ; f!=0 ; f = dfs(s,LLINF))
		ll f = -9999;
		do {
			f = dfs(s, LLINF );
			this->markAllNodesUnvisited();
			this->maxFlow += f;
			//debug(f); debugg(maxFlow);
		} while ( f != 0);
	}

	ll dfs(int node, ll minFlow) {
		if (node == t ) return minFlow;

		this->visit(node);
		for ( Edge* e  : this->adjListEdges[node] ) {
			//debug(node); debug(e->from);debugg(e->to);
			ll residualCapacity = e->remainingCapacity();
			//test this after
			//ll resi = e->residual_ptr->flow;
			if ( residualCapacity > 0 && !isVisited(e->to)) {
				ll currMinFlow = dfs(e->to , min(minFlow, residualCapacity));

				if ( currMinFlow > 0 ) {
					e->augment(currMinFlow);
					return currMinFlow;
				}
			}
		}
		//no augmentedpath was found // LAST STEP
		return 0;
	}
};

int S;
int N_FC, K_FC, N_T_FC;
int N_IC, K_IC, N_T_IC;
ll D_IC, D_FC;
int N_Conflicts;

vector<bitset<6>> possibleDays ;
bitset<6> graphDays = bitset<6>("000000");


int GLOBAL_ID = 0;
int START_FC = 0;
int START_IC = -1; //SETUP LATER

int SRC_ID = -1; //SETUP LATER
int TRG_ID = -1; //SETUP LATER

struct Node {
	int id;
	int day;
	ll  startTime;
	ll  endTime;
	int t_id;

	Node(int d, int sT, int tid):
		day(d), startTime(sT), t_id(tid) {
		endTime = startTime + D_FC ;
		id = GLOBAL_ID++;
	}
};

vector<Node> FC_list;
vector<Node> IC_list;

vector<set<int>> CONFLICTS_list;

bool FC_IC_Ok(int fromFC, int toIC){
	Node& fc_node = FC_list[fromFC];
	Node& ic_node = IC_list[toIC];

	if( CONFLICTS_list[fc_node.t_id].count(ic_node.t_id)) return false;
	if(fc_node.day != ic_node.day) return true;
	if( fc_node.endTime+5 <= ic_node.startTime ) return true;
	if( ic_node.endTime+5 <= fc_node.startTime ) return true;


	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	//GENERATE ALL POSSIBLE DAYS MASKS in a sorted order
	//
	string s = "000000";
	for (int bits_ON = 1 ;  bits_ON <= 6 ; ++bits_ON) {
		s[6 - bits_ON] = '1';

		string tmp = s ;
		do {
			possibleDays.push_back(bitset<6>(tmp));
		} while ( next_permutation(tmp.begin(), tmp.end()));
	}

	//PRINT ALL MASKS

	/*for(auto x : possibleDays){
		cout << x << "\t" << x.to_ulong()<< "\t" << x.count() <<endl;
	}*/

	cin >> S ;


	//READ FC Courses
	cin >> N_FC >> K_FC  >> D_FC >>  N_T_FC  ;
	D_FC *= 60LL;

	GLOBAL_ID = 0;

	for (int i = 0 ; i < N_FC ; ++i ) {
		int Day_i, H_i, M_i , T_id;
		cin >> Day_i >> H_i >> M_i >> T_id;
		graphDays.set(Day_i - 1, true);
		ll startTime = H_i * 60LL + M_i * 1LL;

		FC_list.push_back(Node(Day_i, startTime, T_id));
	}


	//READ IC Courses
	cin >> N_IC >> K_IC  >> D_IC >>  N_T_IC  ;
	D_IC *= 60LL;

	START_IC = GLOBAL_ID;

	for (int i = 0 ; i < N_IC ; ++i ) {
		int Day_i, H_i, M_i , T_id;
		cin >> Day_i >> H_i >> M_i >> T_id;
		graphDays.set(Day_i - 1, true);
		ll startTime = H_i * 60LL + M_i * 1LL;

		IC_list.push_back(Node(Day_i, startTime, T_id));
	}


	//READ CONFLICTS
	cin >> N_Conflicts; 
	CONFLICTS_list.resize(N_T_FC+5);
	for(int i = 0 ; i < N_Conflicts ; ++i){
		int fc_teacher_id, ic_teacher_id ;
		cin >> fc_teacher_id >> ic_teacher_id ;

		CONFLICTS_list[fc_teacher_id].insert(ic_teacher_id);
	}



	// BUILDING THE GRAPH

	SRC_ID = GLOBAL_ID++;
	TRG_ID = GLOBAL_ID++;
	FordFulkersonDFSsolverAdjList FGraph(N_FC + N_IC + 2, SRC_ID, TRG_ID);

	for (int to = START_FC ; to < N_FC ; ++to ) {
		FGraph.addEdge(SRC_ID, to , K_FC);
	}
	
	for (int from = START_IC ; from < N_IC ; ++from ) {
		FGraph.addEdge(from, TRG_ID , K_IC);
	}

	for (int from = START_FC ; from < N_FC ; ++from) {
		for (int to = START_IC ; to < N_IC ; ++to) {
			//TEST IF TIME CONDITIONS + Teacher conflicts conditions are met
			//cout << "Currently Trying to Add : "; debug(from); debugg(to);
			if (FC_IC_Ok(from,to)){
			//	cout << "Added : " ;
			//	debug(from); debugg(to);
				FGraph.addEdge(from,to, K_FC);
			}
		}
	}
	//debugg(graphDays);

	//Find a solution :
	int ans = INF;

	//debugg(FGraph.maxFlow);
	FGraph.executeMaxFlow();

	
	debugg(FGraph.maxFlow);




	return 0;
}
