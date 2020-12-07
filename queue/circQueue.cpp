#include <iostream>
using namespace std;
class Queue
{
private:
	int size,cap,front,*arr;
public:
	Queue(int c){
		cap=c;
		front=0;
		size=0;
		arr=new int[cap];
	}
	void enque(int x){
		if(size==cap){	cout<<"Queue Overflow";	return;}
		int rear=getRear();
		rear=(rear+1) % cap;
		arr[size]=x;
		size++;
	}
	void deque(){
		if(size==-1){	cout<<"Queue Underflow";	return;}
		front=(front+1)%cap;
		size--;
	}
	int getFront(){
		if(size==-1){	cout<<"Queue Underflow";	return -1;}
		return arr[front];
	}
	int getRear(){
		if(size==-1){	cout<<"Queue Underflow";	return -1;}
		return (front+size-1)%cap;
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