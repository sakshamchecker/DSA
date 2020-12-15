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
	int l=0,r=n-1;
	//do{l++}while(a[l]==1)
	for(int i=0;i<n;i++){
		if(a[i]==1){
			swap(a[i],a[l]);
			l++;
		}
		if(a[i]==3){
			swap(a[i],a[r]);
			r--;
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[]={3,3,3,3,2,2,2};
	seggregate32(a,7);
	for(auto x:a){	cout<<x;}
	return 0;
}

// 3,3,2,1,1,2,3,2






