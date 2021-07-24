#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> memo(100, vector<int> (100, -1));

int lcs(string s1, string s2, int m, int n){    //Memoization
    if(memo[m][n]!=-1)  return memo[m][n];

    if(m==0 || n==0)    memo[m][n]=0;
    else{
        if(s1[m-1]==s2[n-1])
            memo[m][n] = 1+ lcs(s1,s2,m-1,n-1);
        else
            memo[m][n] = max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
    }
    return memo[m][n];
}

int lcs(string s1, string s2){ //Tabulation
    int m = s1.length(), n = s2.length();
    vector<vector<int>> db(m+1, vector<int> (n+1, 0));

    for(int i = 1; i<m; i++){
        for(int j = 1; j<m ; j++){
            if(s1[i-1] = s2[j-1])
                db[i][j] = 1 + db[i-1][j-1];
            else
                db[i][j] = max(db[i-1][j], db[i][j-1]);
        }
    }
    return db[n][n];


}
int main(int argc, char const *argv[])
{
    string s1 = "Hello";
    string s2 = "Heo";
    cout<<lcs(s1,s2);
    return 0;
}
