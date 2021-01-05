#include <iostream>
#include <stack>
#include <vector>

using namespace std;


// void bubsort(int a[],int n){
// 	// bool swapped;
// 	for(int i=0;i<n-1;i++){
// 		// swapped=0;
// 		for(int j=0;j<n-1-i;j++){
// 			if(a[j]>a[j+1]){
// 				swap(a[j],a[j+1]);
// 				// swapped=1;
// 			}
// 		}
// 		// if(swapped==1)	break;
// 	}
// }



vector<pair<int,int>> sortInput(vector<pair<int,int>> v){
	for(int i=0;i<v.size()-1;i++){
		int min=i;
		for(int j=i+1;j<v.size();j++){
			if(v[j].second<v[min].second)	min=j;
		}
		swap(v[i],v[min]);
	}
	return v;
}


int maxOp(vector<pair<int,int>> v){
	v=sortInput(v);
	stack<pair<int,int>> s;
	s.push(v[0]);
	for(int i=1;i<v.size();i++){
		if(v[i].first>s.top().second)
			s.push(v[i]);
	}
	return s.size();
}



int main(int argc, char const *argv[])
{
	vector<pair<int,int>> a;
	a.push_back({2,4});
	a.push_back({3,5});
	a.push_back({0,1});
	cout<<maxOp(a);
	//for(auto x:a)	cout<<x.first<<' '<<x.second<<' ';
	return 0;
}