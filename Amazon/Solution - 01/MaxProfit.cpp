#include <bits/stdc++.h>
using namespace std;
class Solution01 {
public:
    int maxProfit(int k, int n, int prices[]){

        int i, j;

        int dp[k + 1][n];
        for (i = 0; i < n ; i++){
            dp[0][i] = 0;
        }
        for (i = 0; i <= k ; i++){
            dp[i][0] = 0;
        }
        for (int trans = 1; trans <= k ; trans++){
            int max = INT_MIN;
            for (int days = 1; days < n ; days++){
                if (dp[trans - 1][days - 1] - prices[days - 1] > max){
                    max = dp[trans - 1][days - 1] - prices[days - 1];
                }

                if (max + prices[days] > dp[trans][days - 1]){
                    dp[trans][days] = max + prices[days];
                }
                else{
                    dp[trans][days] = dp[trans][days - 1];
                }
            }
        }

        return dp[k][n - 1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cout << "Enter the value of max transactions : " << endl;
        cin >> K;
        cout << "Enter the value of n : " << endl;
        cin >> N;
        int A[N];
        cout << "Enter the prices : " << endl;
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution01 ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}