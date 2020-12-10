#include <iostream>
using namespace std;
void flip(bool a[],int n){
	int f0=0,f1=0;
	bool flag=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]==0){
			flag=1;
		}
		if(a[i]==1){
			if(flag==1){
				flag=0;
				f0++;
			}
		}
	}
	if(flag==1)	f0++;
	flag=0;
	for(int i=0;i<n;i++){
		if(a[i]==1){
			flag=1;
		}
		else{
			if(flag==1){
				flag=0;
				f1++;
			}
		}
	}
	if(flag==1)	f1++;
	// cout<<f1<<endl;
	cout<<"From "<<min(f0,f1)<<" to "<<max(f0,f1);
}
int main(int argc, char const *argv[])
{
	bool a[]={1,1,0,0,0,0,1,0,0,0,1};
	flip(a,11);
	return 0;
}
