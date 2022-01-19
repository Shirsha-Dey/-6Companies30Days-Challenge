#include <bits/stdc++.h>
using namespace std;

class Solution7 {
public:
    int findPosition(int n , int m , int k) {

        int temp = n - k + 1;
        int temp2 = m - temp;
        if (m + k <= n + 1)
        {
            return m + k - 1;
        }
        else
        {
            int ans = temp2 % n;
            if (ans == 0)
            {
                return n;
            }
            else
            {
                return ans;
            }
        }
    }
};

int main() {
    int t;
    
    cin >> t;
    while (t--) {
        int N, M, K;

        cin >> N >> M >> K;

        Solution7 obj;
        cout << obj.findPosition(N, M, K) << endl;
    }
    return 0;
}  