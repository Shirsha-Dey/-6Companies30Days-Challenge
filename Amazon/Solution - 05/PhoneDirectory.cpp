#include <bits/stdc++.h>
using namespace std;

class Solution05 {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        vector<vector<string>> ans;
        int i, j, k;
        for (i = 0; i < s.size(); i++){
            vector<string> path;
            set<string> st;
            string temp = s.substr(0, i + 1);
            for (j = 0; j < n ; j++){
                if (contact[j].size() >= temp.size()){
                    string temp2 = contact[j].substr(0, temp.size());
                    if (temp == temp2){
                        st.insert(contact[j]);
                    }
                }
            }
            for (auto it : st){
                path.push_back(it);
            }
            if (path.size() == 0){
                path.push_back("0");
                ans.push_back(path);
            }
            else{
                ans.push_back(path);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution05 ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++) {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}