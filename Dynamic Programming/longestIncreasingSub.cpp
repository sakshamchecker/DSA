#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> a ){ //O(n2)
    vector<int> lis (a.size());
    lis[0] = 1;
    for(int i = 1 ; i< a.size(); i ++){
        lis[i] = 1;
        for(int j = 0; j< i ; j++){
            if(a[j]<a[i])   lis[i] = max(lis[i], lis[j]+1);
        }
    }
    int res = lis[0];
    for(int i = 0 ; i<a.size() ; i++) res=max(res, lis[i]);
    return res;
}


int ceil(vector<int> tail, int l, int r, int x){

    while(r>l){
        int m = l + (r-l)/2;
        if(tail[m]>=x)  r= m;
        else
            l = m+1;
    }
    return r;

}

int lisc(vector<int> a ){ //O(nlogn)
    vector<int> tail(a.size());
    tail[0] = a[0];
    int len = 1;
    for(int i = 1 ; i < a.size(); i ++){
        if(tail[len-1] < a[i]){
            tail[len] = a[i]; len++;
        }
        else{
            int c = ceil(tail, 0, len-1, a[i]);
            tail[c] = a[i];
        }
    }
    return len;
}

int main(){
    vector<int> a = {3,4,2,5,8};
    cout<<lisc(a);
}