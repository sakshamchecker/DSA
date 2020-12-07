#include <iostream>
using namespace std;
class Queue
{
private:
	int size,cap,*arr;
public:
	Queue(int c){
		cap=c;
		size=0;
		arr=new int[cap];
	}
	void enque(int x){
		if(size==cap){	cout<<"Queue Overflow";	return;}
		arr[size]=x;
		size++;
	}
	void deque(){
		if(size==-1){	cout<<"Queue Underflow";	return;}
		for(int i=0;i<size-1;i++)	arr[i]=arr[i+1];
		size--;
	}
	int getFront(){
		if(size==-1){	cout<<"Queue Underflow";	return -1;}
		return arr[0];
	}
	int getRear(){
		if(size==-1){	cout<<"Queue Underflow";	return -1;}
		return arr[size-1];
	}
	bool isFull(){
		return size==cap;
	}
	bool isEmpty(){
		return size!=cap;
	}
	int getSize(){
		return size;
	}
	void trans(){
		for(int i=0;i<size;i++ )	cout<<arr[i]<<endl;
	}
};
int main()
{
	Queue a= Queue(5);
	a.enque(10);
	a.enque(20);
	a.enque(30);
	a.enque(40);
	a.enque(50);
	a.deque();
	a.trans();
	return 0;
}