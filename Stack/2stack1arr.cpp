#include <iostream>
using namespace std;
class doublestack
{
	int *a,cap,top1,top2;
public:
	doublestack(int n){
		cap=n;
		top1=-1;
		top2=n;
		a=new int[n];
	}
	void push1(int x){
		if(top1<top2-1){
			top1++;
			a[top1]=x;
		}
		else
			cout<<"Overflow";
	}
	void push2(int x){
		if(top1<top2-1){
			top2--;
			a[top2]=x;
		}
		else
			cout<<"Overflow";
	}
	void pop1(){
		if(top1==-1){
			cout<<"Underflow";
			return;
		}
		cout<<a[top1];
		top1--;
	}
	void pop2(){
		if(top2==cap){
			cout<<"Underflow";
			return;
		}
		cout<<a[top2];
		top2++;
	}
};
int main(int argc, char const *argv[])
{
	doublestack dual(10);
	dual.push1(5);
	dual.push2(10);
	dual.pop2();
	return 0;
}