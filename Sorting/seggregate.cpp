#include <iostream>
using namespace std;
void seggregate(int a[],int n){ //Two types
	int pos=0;
	for(int i=0;i<n;i++){
		if(a[i]<0){
			swap(a[i],a[pos]);
			pos+=1;
		}
	}
}
void seggregate2(int a[],int n){//Two Types //hoare's
	int i=-1,j=n;
	while(1){
		do{i++;}while(a[i]<0);
		do{j--;}while(a[j]>=0);
		if(i>=j)	return;
		swap(a[i],a[j]);
	}
}
void seggregate31(int a[],int n){
	int p[n];
	int j=0;
	for(int i=0;i<n;i++){
		if(a[i]==1){p[j]=a[i];	j++;}
	}
	for(int i=0;i<n;i++){
		if(a[i]==2){p[j]=a[i];	j++;}
	}
	for(int i=0;i<n;i++)
		if(a[i]==3){p[j]=a[i];	j++;}
	for(int i=0;i<n;i++)
		a[i]=p[i];
}
void seggregate32(int a[],int n){
	int low=0,mid=0,high=n-1;
	//do{l++}while(a[l]==1)
	while(mid<=high){
		switch(a[mid]){
			case 1: swap(a[low],a[mid]);
					low++;
					mid++;
					break;
			case 2: mid++;
					break;
			case 3:	swap(a[mid],a[high]);
					high--;
					break;
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,2,1,2,3};
	seggregate32(a,7);
	for(auto x:a){	cout<<x;}
	return 0;
}

// 3,3,2,1,1,2,3,2






