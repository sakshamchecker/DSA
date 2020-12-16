#include <iostream>
#include <algorithm>

using namespace std;
int maxGuests(int arr[],int dep[],int n){
	int res=0;
	for(int i=0;i<n;i++){
		int curr=0;
		for(int j=i;j<n;j++){
			if((arr[i]>=arr[j]&&arr[i]<=dep[i])||(arr[j]>=arr[i]&&arr[j]<=dep[i]))
				curr++;
		}
		res=max(res,curr);
	}
	return res;
}
int maxGuests1(int arr[],int dep[],int n){
	int res=0,i=0,j=0,count=0;
	sort(arr,arr+n);
	sort(dep,dep+n);
	while(i<n){
		if(arr[i]<dep[j]){
			count++;
			i++;
		}
		else if(arr[i]>arr[j]){
			count--;
			j++;
		}
		res=max(res,count);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={1000,1020,1100,930};
	int b[]={1030,1030,1130,1200};
	cout<<maxGuests1(a,b,4);
	return 0;
}
