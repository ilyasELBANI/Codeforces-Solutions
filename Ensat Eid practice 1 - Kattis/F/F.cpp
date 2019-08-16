#include <bits/stdc++.h>
using namespace std;

map< string , int > myWords;
map< string , vector<string> > myCats;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n ;
	cin >> n ;

	for ( int i = 0 ; i < n ; ++i) {
		string cat ;
		cin >> cat ;

		int W;
		cin >> W ;

		string word;
		vector<string> myVect;

		while (W--) {
			cin >> word ;
			myVect.push_back(word);
			myWords[word] = 0 ;
		}
		myCats[cat] = myVect;
	}

	string x ;

	while (cin >> x ) {
		if ( myWords.count(x) == 1 ) {
			myWords[x]++;
		}
	}

	/*	for(auto c : myWords){
			cout << c.first  << " : "  << c.second << endl;
		}*/

	vector< pair<int , string >>  ResultCats ;
	for (auto  cat  : myCats ) {
		int sum = 0;

		for (int i = 0 ; i < cat.second.size() ; ++i) {
			sum += myWords[cat.second[i]] ;
		}
	//	cout << sum << endl;

		ResultCats.push_back({ - sum , cat.first });
	}

	sort(ResultCats.begin(), ResultCats.end() );

	for (int i = 0; i < ResultCats.size() ; ++i) {
		if (ResultCats[i].first == ResultCats[0].first) {
			cout << ResultCats[i].second << endl;
		} else {
			break;
		}
	}
	return 0;
}
