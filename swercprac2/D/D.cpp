#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define debug(x) cout << #x << ":" << x << ' ';
#define debugg(x) cout << #x << ":" << x << ' ' << "\n";
#define endl "\n"

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int n , m;
vector<int> possibilities(50,0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m ;

	for(int i =  1 ; i <= n  ; ++ i){
		for (int j = 1 ; j <= m ; ++j){
			possibilities[i+j]++;
		}
	}

	int maxx = *max_element(all(possibilities));
	for(int i = 1 ; i <= n +m ; ++i){
		if(maxx== possibilities[i]){
			cout << i << endl;
		}
	}

	return 0;
}
