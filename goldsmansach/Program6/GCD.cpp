class Solution6 {
public:
    string gcdOfStrings(string str1, string str2) {
        int i,j,k,n = str1.size(),m = str2.size();
      
        if(str1 + str2 != str2 + str1)
        {
            return "";
        }
        else
        {
            return str2.substr(0,__gcd(n,m));
        }
    }
};
