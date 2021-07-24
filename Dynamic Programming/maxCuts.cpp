#include<iostream>
#include<vector>
using namespace std;

int maxCut(int n, int a , int b , int c){   //recc
    if(n<0)  return -1;
    if(n==0)    return 0;
    int res = max(max(maxCut(n-a, a, b, c), maxCut(n-b, a, b, c)), maxCut(n-c, a, b, c));

    if(res == -1)   return res;
    return res+1;
}

int maxCutDP(int n , int a, int b, int c){
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <=n; i++)
    {
        dp[i] = -1;
        if(i-a>=0)  dp[i] = max(dp[i], dp[i-a]);
        if(i-b>=0)  dp[i] = max(dp[i], dp[i-b]);
        if(i-c>=0)  dp[i] = max(dp[i], dp[i-c]);
        if(dp[i]!=-1)   dp[i]++;
    }

    return dp[n];
    
}

int main(int argc, char const *argv[])
{
    cout<<maxCutDP(5,2,2,1);
    return 0;
}
