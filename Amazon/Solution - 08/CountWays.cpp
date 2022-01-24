#include<bits/stdc++.h>
using namespace std;
class Solution08{
public:
    long long countWays(int m){
        return m / 2 + 1;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        Solution08 ob;
        cout << ob.countWays(m) << endl; 
        }
    return 0;
}