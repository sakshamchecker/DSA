#include <iostream>
using namespace std;
int ser(int n){
	if(n==0){
		std::cout<<0;
	}
	else{
		printf("%d",n );
		ser(n-1);
	}
	return 0;
}
int sero(int n){
	if(n==0)	return 0;
	sero(n-1);
	cout<<n;
	return 0;
}
int sum(int n,int su=0){
	if(n==0)	return su;
	su+=n%10;
	su=sum(n/10,su);
	return su;
}
int main(int argc, char const *argv[])
{
	cout<<sum(1110012929);
	return 0;
}