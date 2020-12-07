#include <iostream>
#include <climits>
using namespace std;
class minHeap
{
public:
	int *arr;
	int size,cap;
	int left(int i)	{return 2*i + 1;}
	int right(int i){return 2*i + 2;}
	int parent(int i){return (i-1)/2;}
	minHeap(int c){
		arr=new int[c];
		size=0;
		cap=c;
	}
	void insert(int x){
		size++;
		arr[size-1]=x;
		int pos=size-1;
		int temp;
		int par=parent(pos);
		while(x<arr[par] && pos!=0){
			temp=arr[par];
			arr[par]=arr[pos];
			arr[pos]=temp;
			pos=par;
			par=parent(pos);
		}
	}
	void minHeapify(int i=0){
		int lt=left(i),rt=right(i);
		int smallest=i;
		if(lt<size && arr[lt]<arr[i])	smallest=lt;
		if(rt<size && arr[rt]<arr[i])	smallest=rt;
		if(smallest!=i){
			swap(arr[i],arr[smallest]);
			minHeapify(arr[smallest]);
		}
	}
	int extractMin(){
		if(size==0)	return INT_MAX;
		if(size==1)	return arr[0];
		minHeapify();
		swap(arr[0],arr[size-1]);
		size--;
		minHeapify();
		return arr[size];
	}
	void decKey(int i, int x){
		arr[i]=x;
		while(i!=0&& arr[parent(i)]>arr[i]){
			swap(arr[i],arr[parent(i)]);
			i=parent(i);
		}
	}
	void delKey(int i){
		swap(arr[i],arr[size-1]);
		size--;
		minHeapify(i);
	}
	void buildHeap(){
		for(int i=(size-2)/2;i>=0;i--)
			minHeapify(i);
	}

};
minHeap createHeap(int a[],int len){
	minHeap temp= minHeap(len);
	for(int i=0;i<len;i++){
		temp.insert(a[i]);
	}
	return temp;
}
int main(int argc, char const *argv[])
{
	minHeap a= minHeap(5);
	a.insert(35);
	a.insert(10);
	a.insert(25);
	a.insert(5);
	// a.arr[0]=55;
	// a.arr[1]=10;
	// a.arr[2]=65;
	// a.size=3;
	// cout<<a.arr[0]<<a.arr[1]<<a.arr[2]<<endl; 
	// a.minHeapify();
	// a.extractMin();
	// int a[]={1,4,5,2,3};
	// minHeap b=createHeap(a,5);
	for(int i=0;i<a.size;i++)	cout<<a.arr[i];
	return 0;
}
