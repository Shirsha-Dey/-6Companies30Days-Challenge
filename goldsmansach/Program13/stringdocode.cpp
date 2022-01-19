#include <bits/stdc++.h>
using namespace std;

class Solution13 {
    string decode_now(string &str, int &itr)
    {
        string result;
        while (itr < str.length() && str[itr] != ']')
        {
            if (isdigit(str[itr])) 
            {
                int k = 0;
                while (itr < str.length() && isdigit(str[itr])) 
                {
                    k = k * 10 + (str[itr] - '0');
                    itr++;
                }

                itr++; 
                string rem = decode_now(str, itr); 
                while (k > 0) 
                {
                    result += rem;
                    k--;
                }
                itr++; 
            }
            else
            {
                result.push_back(str[itr++]); 
            }
        }
        return result;
    }

public:
    string decodedString(string s) {
         int i = 0;
        return decode_now(s, i);
    }
};



int main() {
    int time;
    cin >> time;
    while (time--) {
        string s;
        cin >> s;
        Solution13 obj;
        cout << obj.decodedString(s) << endl;
    }
    return 0;
}  