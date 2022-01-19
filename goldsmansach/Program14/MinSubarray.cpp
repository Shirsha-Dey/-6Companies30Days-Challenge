#include <bits/stdc++.h>
using namespace std;


class Solution14 {
public:
    int lenOfMinSubArray(int goal, vector<int>& numbers) {
        int i = 0,j = 1, k, n = numbers.size();

        int answers = INT_MAX;

        if(numbers[0] >= goal) 
             return 1;
        
        int def_count = 2;
        int total_sum = numbers[0];
        int flag = 0;
        
        while(i <= j && j < n && i < n)
        {
            if(flag == 0) total_sum += numbers[j];

            if(total_sum >= goal)
            {
                answers = min(answers,def_count);
                total_sum -= numbers[i];
                i++;
                def_count--;
                flag = 1;
            }
            else
            {
                flag = 0;
                def_count++;
                j++;
            }
        }
        if(answers == INT_MAX) 
             return 0;
        return answers;
    }
};
