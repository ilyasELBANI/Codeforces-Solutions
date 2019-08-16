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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

 	
	string s ;
	cin >> s ;
	string a="";
	string b="";;
	int i = 0;
	int j ;
	while(i < s.size()){
		for( j = 0 ; i+j < s.size() ; ++j){
			if(s[i+j]==';') break;
			if(s[i+j]==',') break;
		}
		string tmp =  s.substr(i,j);
		bool number = true;
		for(auto c : tmp){
			if(c<'0' ) number = false;
			if(c>'9' ) number = false;
		}
		if(tmp.front()=='0' && tmp.back()!='0') number = false;
		if(tmp.size()>1 && tmp.front()=='0' && tmp.back()=='0') number = false;
		if (tmp.size()==0) number= false;

		if(number){
			a+=tmp + ",";
		}else{
			b+=tmp+',';
		}
		i+=j+1;
	}
	if(s.back()==',') b+=',';
	if(s.back()==';') b+=',';

	if(a.size()){
		a.back()='\"' ;
		cout << "\"" << a <<endl ;
	}else{
		cout << "-" << endl;
	}

	if(b.size()){
		b.back()='\"' ;
		cout << "\"" << b <<endl ;
	}else{
		cout << "-" << endl;
	}

	return 0;
}
/*
aba,123;1a;0
012345678901

*/