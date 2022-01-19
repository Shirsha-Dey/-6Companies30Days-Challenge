#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<vector<string> > anagrams(vector<string>& str1) {
        vector<vector<string>> res;
        int i, j, k;
        int n = str1.size();
        vector<string> open;
        int count = 0;
        for (i = 0; i < n; i++){
            if (str1[i] == ""){
                count++;
                open.push_back(str1[i]);
            }
        }
        if (count != 0){
            res.push_back(open);
        }    
        for (i = 0; i < n; i++){
            if (str1[i] == "-1" || str1[i] == ""){
                continue;
            }
            vector<string> temp;
            temp.push_back(str1[i]);
            unordered_map<char, int> original;
            for (j = 0; j < str1[i].size(); j++){
                original[str1[i][j]]++;
            }
            for (j = i + 1; j < n ; j++){
                bool check = true;
                unordered_map<char, int> umap;
                for (k = 0 ; k < str1[j].size(); k++){
                    umap[str1[j][k]]++;
                }
                if (umap.size() == original.size()){
                    for (auto it : original){
                        if (umap.find(it.first) == umap.end()){
                            check = false;
                            break;
                        }
                        else if (umap.find(it.first) != umap.end() && umap[it.first] != it.second){
                            check = false;
                            break;
                        }
                    }
                }
                else{
                    check = false;
                }
                if (check == false){
                    continue;
                }
                else{
                    temp.push_back(str1[j]);
                    str1[j] = "-1";
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution1 ob;
        vector<vector<string> > res = ob.anagrams(string_list);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++){
            for (int j = 0; j < res[i].size(); j++){
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
