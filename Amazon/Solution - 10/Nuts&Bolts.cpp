#include <bits/stdc++.h>
using namespace std;
class Solution10 {
public:

	void matchPairs(char nuts[], char bolts[], int n) {
		
		map<char, int> m;
		m['!']++;
		m['#']++;
		m['$']++;
		m['%']++;
		m['&']++;
		m['*']++;
		m['@']++;
		m['^']++;
		m['~']++;

		map<char, int> nutmap;
		map<char, int> boltmap;

		for (int i = 0; i < n ; i++){
			nutmap[nuts[i]]++;
			boltmap[bolts[i]]++;
		}
		int j = 0;
		for (auto i : m){
			if (nutmap.find(i.first) != nutmap.end() && boltmap.find(i.first) != boltmap.end()){
				nuts[j] = i.first;
				bolts[j] = i.first;
				j++;
			}
		}
	}

};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char nuts[n], bolts[n];
		for (int i = 0; i < n; i++) {
			cin >> nuts[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> bolts[i];
		}
		Solution10 ob;
		ob.matchPairs(nuts, bolts, n);
		for (int i = 0; i < n; i++) {
			cout << nuts[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n; i++) {
			cout << bolts[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}