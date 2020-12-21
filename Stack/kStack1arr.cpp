#include <iostream>
using namespace std;
class kstacks{
	int *arr,*top,*next;
	int k,cap,freetop;
	kstacks(int k1, int n){
		arr=new int[cap];
		top=new int[k];
		next= new int[cap];
		for(int i=0;i<cap;i++){
			top[i]=-1;
		}		
		freetop=0;
		for(int i=0;i<cap-1;i++){
			next[i]=i+1;
		}
		next[top-1]=-1;
	}
}