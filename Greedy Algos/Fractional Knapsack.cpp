#include <iostream>
#include <vector>
using namespace std;



float getRatio(pair<int,int> p){
	return (p.first/p.second)/1.0;
}



vector<pair<int,int>> sortInput(vector<pair<int,int>> v){
	for(int i=0;i<v.size()-1;i++){
		int min=i;
		for(int j=i+1;j<v.size();j++){
			if(getRatio(v[j])>getRatio(v[min]))		min=j;
		}
		swap(v[i],v[min]);
	}
	return v;
}



int knapSack(vector<pair<int,int>> v,int cap){
	v=sortInput(v);
	int res=0,curr_cap=cap;
	for(int i=0;i<v.size();i++){
		if(v[i].second<=curr_cap){
			curr_cap-=v[i].second;
			res+=v[i].first;
		}
		else{
			res+=(v[i].first)*(curr_cap/v[i].second);
			return res;
		}
	}
	return res;
}