#include<iostream>
using namespace std;
int getCount(int coins[], int n, int sum){
    int db[sum + 1][n+1];
    for(int i=0 ; i <= n ; i++) db[0][1] = 1;
    for(int i = 1 ; i <= sum ; i ++) db[i][0] = 0;
    for (int i = 0; i < sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            db[i][j] = db[i][ j-1];
            if(coins[j-1] <= i)
                db[i][j]+= db[i = coins[j-1]][j];
        }
        
    }
    return db[sum][n];
}

int main(int argc, char const *argv[])
{
    int coins[5] = {1,2,3,4,5};
    cout<<getCount(coins, 5, 3);
    return 0;
}
    