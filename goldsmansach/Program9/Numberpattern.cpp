
#include<bits/stdc++.h>
using namespace std;


class Solution9 {
public:
  string printMinNmbrForPattern(string str) {
  
    stack<string> st;
    string ans = "";
    int num = 1;
    int n = str.size();
    for (int i = 0; i < n; i++){
      if (str[i] == 'D'){
        st.push(to_string(num));
        num++;
      }
      else{
        st.push(to_string(num));
        num++;

        while (st.size() > 0){
          ans += st.top();
          st.pop();
        }
      }
    }
    st.push(to_string(num));
    while (st.size() > 0){
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};



int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string S;
    cin >> S;
    Solution9 obj1;
    cout << obj1.printMinNmbrForPattern(S) << endl;
  }
  return 0;
}
