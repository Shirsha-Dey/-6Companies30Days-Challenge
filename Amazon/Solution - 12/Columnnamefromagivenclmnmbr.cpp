#include<bits/stdc++.h>
using namespace std;

class Solution12 {
public:
    string colName (long long int n){
        string ans = "";

        while (n != 0){
            n--;
            int rem = n % 26;
            char ch = 'A' + rem;
            ans = ch + ans;
            n = n / 26;
        }
        return ans;
    }
};
int main(){
    int t; cin >> t;
    while (t--){
        long long int n; cin >> n;
        Solution12 obj;
        cout << obj.colName (n) << '\n';
    }
}