#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Triplet{
	int val,aPos,vPos;
	Triplet(int v,int a,int vp){
		val=v;
		aPos=a;
		vPos=vp;
	}
};


struct MyHeap{
	bool operator()(Triplet &v1,Triplet &v2){return v1.val>v2.val;}
};


vector<int> mergeArr(vector<vector<int>> &arr){
	vector<int> res;
	priority_queue<Triplet,vector<Triplet>,MyHeap> pq;
	for(int i=0;i<arr.size();i++){
		Triplet t(arr[i][0],i,0);
		pq.push(t);
	}
	while(!pq.empty()){
		Triplet curr=pq.top();	pq.pop();
		res.push_back(curr.val);
		int ap=curr.aPos,vp=curr.vPos;
		if(vp+1 < arr[ap].size()){
			Triplet s(arr[ap][vp+1],ap,vp+1);
			pq.push(s);
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	vector<vector<int>> a;
	a.push_back({1,3,5});
	a.push_back({2,4,6});
	vector<int> res= mergeArr(a);
	for(auto x:res)	cout<<x;
	return 0;
}