#include<bits/stdc++.h>
using namespace std;

class Solution07 {
public:
	string FirstNonRepeating(string s) {
		int freq[26] = {0};
		int i, j, k;
		string ans = "";
		queue<int> q;

		for (i = 0; i < s.size(); i++){
			if (freq[s[i] - 'a'] == 0){
				q.push(s[i]);
			}

			freq[s[i] - 'a']++;

			while (!q.empty() && freq[q.front() - 'a'] != 1){
				q.pop();
			}

			if (q.empty()) ans.push_back('#');
			else ans += q.front();
		}

		return ans;
	}

};


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string A;
		cin >> A;
		Solution07 obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  