#include<iostream>
using namespace std;

int fibo(int n){
    int table[n+1];
    table[0] = 0, table[1] = 1;
    for(int i=2;i<=n;i++){
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main(int argc, char const *argv[])
{
    cout<<fibo(5);
    return 0;
}
