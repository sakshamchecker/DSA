#include <iostream>
using namespace std;
min(int a,int b,int c,int d, int e, int f){
	int m=a;
	if(a<m)	m=a;
	if(b<m)	m=b;
	if(c<m)	m=c;
	if(d<m)	m=d;
	if(e<m)	m=e;
	if(f<m)	m=f;
	return m;
}
fun(int n){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(n>99){
				for(int k=0;k<10;k++){
					if(i*j*k==n)	return min(100*i+10*j+k,100*i+10*k+j, 100*j+10*k+i,100*j+10*i+k,100*k+10*i+j,100*k+10*j+i);
					return -1;
				}
			}
			if(i*j==n)
				{	if(i<j)	return 10*i+j;
					return 10*j+i;
				}
		}
	}
	return -1;
}




int main(int argc, char const *argv[])
{
	cout<<fun(56);
	return 0;
}