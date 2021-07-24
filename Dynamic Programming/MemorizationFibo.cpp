#include<iostream>
#include<vector>
using namespace std;

vector<int> mem(100,-1);

int fib(int n){
    if(mem[n]==-1){
        int res;
        if(n==1 || n==0)
            res = n;
        else
            res = fib(n-1) + fib(n-2);
        mem[n]=res;
    }
    return mem[n];
}

int main(int argc, char const *argv[])
{
    cout<<fib(5);
    return 0;
}
