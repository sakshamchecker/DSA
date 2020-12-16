#include <iostream>
using namespace std;
struct Interval
{
	int start;
	int end;
};
Interval check(Interval a1,Interval a2){
	Interval temp;
	if(a1.start<a2.start){
		if(a2.start<a1.end){
			temp.start=a1.start;
			temp.end=max(a1.end,a2.end);
		}
	}
	else if(a2.start<a1.start){
		if(a1.start<a2.end){
				temp.start=a2.start;
				temp.end=max(a2.end,a1.end);
			}
	}
	return temp;
}
void sort(Interval a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j].start>a[j+1].start){
				swap(a[j],a[j+1]);
			}
		}
	}

}
void merge(Interval a[],int &n){
	sort(a,n);
	int res=0;
	for(int i=1;i<n;i++){
		if(a[res].end>=a[i].start){
			a[res]=check(a[i],a[res]);
			res++;
		}
		else{res++;a[res]=a[i];}
	}
	n=res;
}
int main(int argc, char const *argv[]){
	Interval a[5];
	for(int i=0;i<5;i++){
		cin>>a[i].start;
		cin>>a[i].end;
	}
	sort(a,5);
	cout<<endl;
	for(auto x:a)	cout<<x.start<<','<<x.end<<" : ";
	return 0;
}