#include <bits/stdc++.h>
using namespace std;


class Solution15 {
public:
    bool PossiblePair(vector<int> numbers, int inp) {

        if (numbers.size() % 2 != 0) 
                return false;

        int i, j; int n = numbers.size();

        unordered_map<int, int> mine;
        for (i = 0; i < n; i++)
        {
            mine[numbers[i] % inp]++;
        }
        for (i = 0; i < n; i++)
        {
            int extra = numbers[i] % inp;

            if (extra == 0)
            {
                if (mine[extra] % 2 != 0)
                {
                    return false;
                }
            }
            else if (2 * extra == inp)
            {
                if (mine[extra] % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if (mine[extra] != mine[inp - extra]) return false;
            }
        }
        return true;
    }
};

int main() {
    int tmpCom;
    cin >> tmpCom;
    while(tmpCom--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++){ 
        cin >> nums[i];
        }
        Solution15 obj;
        bool answer = obj.PossiblePair(nums, k);
        if (answer)
            cout << "True"<<endl;
        else
            cout << "False"<<endl;
    }
    return 0;
}