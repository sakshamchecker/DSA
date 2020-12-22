#include <iostream>
#include <deque>
using namespace std;
int findPump(int petrol[],int dist[],int n){ //Naive
	for(int i=0;i<n;i++){
		int curr_petrol=0;
		int end=i;
		while(1){
			curr_petrol+=(petrol[end]-dist[end]);
			if(curr_petrol<0)
				break;
			end=(end+1)%n;
			if(end==i)
				return i+1;
		}
	}
	return -1;
}
int findPump1(int petrol[],int dist[],int n){ //dq (Better)
	deque<int> dq;
	int curr_petrol=0;
	for(int i=0;i<n;i++){
		curr_petrol+=petrol[i]-dist[i];
		if(curr_petrol>=0)	dq.push_front(i);
		else	if(dq.empty()==0)	dq.pop_back();	else	curr_petrol=0;
	}
	return dq.size();
}
int findPump2(int petrol[],int dist[],int n){ //array(efficient)
	int start=0,curr_petrol=0,prev_petrol=0;
	for(int i=0;i<n;i++){
		curr_petrol+=(petrol[i]-dist[i]);
		if(curr_petrol<0){
			start=i+1;
			prev_petrol=curr_petrol;
			curr_petrol=0;
		}
	}
	return ((curr_petrol+prev_petrol)>=0)?start+1:-1;
}
int main(int argc, char const *argv[])
{
	int a[]={50,10,60,100},b[]={30,20,100,10};
	cout<<findPump2(a,b,4);
	return 0;
}