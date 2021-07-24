#include<iostream>
using namespace std;

int editDist(string s1, string s2, int m, int n){ //reccursive
    if(m==0)    return n;
    if(n==0)    return m;
    if(s1[m-1]==s2[n-1])  return editDist(s1,s2, m-1, n-1);
    return 1 + min(min(editDist(s1,s2,m,n-1), editDist(s1,s2,m-1,n)), editDist(s1,s2,m-1,n-1));
}


int editDist(string s1, string s2){
    int dp[s1.length()+1][s2.length()+1];
    for (int i = 0; i <= s1.length(); i++) {
        for (int j = 0; j <= s2.length(); j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i; 
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            else
                dp[i][j]= 1 + min(min(dp[i][j - 1],  dp[i - 1][j]), dp[i - 1][j - 1]); 
        }
    }
    return dp[s1.length()][s2.length()];
}


int main()
{
    string s2 = "saturday" , s1 = "sunday";
    cout<<editDist(s1,s2);
    return 0;
}
