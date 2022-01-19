#include <bits/stdc++.h>
using namespace std;

class Solution12 {
public:
  long long squaresInChessBoard(long long inp) {
    long long int arr[inp];

    long long int i, j, k;
    
    arr[0] = 1;
    
    for (i = 1; i < inp; i++)
    {
      arr[i] = ((i + 1) * (i + 1)) + arr[i - 1];
    }
    return arr[inp - 1];
  }
};

int main() {
  int time;
  cin >>time ;
  while (time--) {
    long long inp;

    cin >> inp;
    Solution12 obj1;
    cout << obj1.squaresInChessBoard(inp) << endl;
  }
  return 0;
}  