#include <iostream>
using namespace std;
class kstacks{
	int *arr,*top,*next;
	int k,cap,freetop;
<<<<<<< HEAD
public:
	kstacks(int k1, int cap){
=======
	kstacks(int k1, int n){
>>>>>>> origin/main
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
<<<<<<< HEAD
		next[freetop-1]=-1;
	}
	void push(int x,int m){
		int i=freetop;
		freetop=next[i];
		next[i]=top[m];
		top[m]=i;
		arr[i]=x;
	}
	int pop(int m){
		int i=top[m];
		top[m]=next[i];
		next[i]=freetop;
		freetop=i;
		return arr[i];
	}
};
int main(int argc, char const *argv[])
{
	kstacks *a=new kstacks(5,10);
	return 0;
=======
		next[top-1]=-1;
	}
>>>>>>> origin/main
}