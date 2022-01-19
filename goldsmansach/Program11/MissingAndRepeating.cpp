#include <bits/stdc++.h>
using namespace std;

class Solution11 {
public:
    int *findElements(int *ar1, int n) {
        int i, j, k;
        int *out = new int[2];
        for (i = 0; i < n; i++){
            if (ar1[abs(ar1[i]) - 1] < 0){
                out[0] = abs(ar1[i]);
            }
            else{
                ar1[abs(ar1[i]) - 1] = -ar1[abs(ar1[i]) - 1];
            }
        }
        for (i = 0; i < n ; i++){
            if (ar1[i] > 0){
                out[1] = i + 1;
            }
        }
        return out;
    }
};


int main() {
    int time;
    cin >> time;
    while (time--) {
        int n;
        cin >> n;
        int init[n];
        for (int i = 0; i < n; i++) {
            cin >> init[i];
        }
        Solution11 obj1;
        auto out = obj1.findElements(init, n);
        cout << out[0] << " " << out[1] << "\n";
    }
    return 0;
}