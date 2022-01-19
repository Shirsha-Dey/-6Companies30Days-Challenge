#include <bits/stdc++.h>
using namespace std;

class Solution3 {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int product = 1;
        int i, j = 0;
        int count = 0;
        for (i = 0; i < n; i++)
        {
            product *= a[i];

            while (product >= k && j <= i)
            {
                product /= a[j];
                j++;
            }

            count += (i - j + 1);
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution3 obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}