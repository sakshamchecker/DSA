#include <iostream>
using namespace std;
void bubsort(int a[],int n){
	// bool swapped;
	for(int i=0;i<n-1;i++){
		// swapped=0;
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				// swapped=1;
			}
		}
		// if(swapped==1)	break;
	}
}
void selectsort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])	min=j;
		}
		swap(a[i],a[min]);
	}
}
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
void mergesort(int a[], int b[],int na,int nb){
	int i=0,j=0, c[na+nb]={},z=0;
	while(z<=(na+nb)){
		if(a[i]<=b[j]){c[z]=a[i];	i++;	z++;}
		if(b[j]<=a[i]){c[z]=b[j];	j++;	z++;}
	}
	for(auto x:c)	cout<<x<<endl;
}
void mergesorts(int a[],int l,int r){
	if(r>l){
	int m=l+(r-l)/2;
	mergesorts(a,l,m);
	mergesorts(a,m+1,r);
	// merge(a,l,m,r);
	}
}
void naiveParti(int a[],int n,int len){
	int temp=a[n];
	int less[len]={}, more[len]={},l=0,m=0,i=0;
	for(int x=0;x<len;x++){
		if(a[x]<a[n]){
			less[l]=a[x];
			l++;
		}
		else if (a[x]>a[n]){
			more[m]=a[x];
			m+=1;
		}
	}
	for(i;i<l;i++)	a[i]=less[i];
	a[i]=temp;
	for(int j=0;j<m;j++)	{i++;	a[i]=more[j];}
	for(int x=0;x<len;x++)	cout<<a[x]<<endl;
}
int parti(int a[],int l,int h){ //lomuto(Partition about last number in array)
	int pivot=a[h];
	int i = l-1;
	for(int j=l;j<=h-1;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	//cout<<i;
	swap(a[i+1],a[h]);
	return(i+1);
}
void parti2(int a[],int pivo,int len){ //lomuto(partition about specific index value)
	int i=-1, pivot=a[pivo];
	for(int j=0;j<len;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
			if(i==pivo)	pivo=j;
		}
	}
	swap(a[i+1],a[pivo]);
}
void lomQSort(int a[],int l, int h){
	if(l<h){
		int p=parti(a,l,h);
		lomQSort(a,p+1,h);
		lomQSort(a,l,p-1);
	}
}
// void naiveQSort()
int main(int argc, char const *argv[])
{
	int a[]={4,22,5,6,28,26,7};
	// parti2(a,3,7);	
	lomQSort(a,0,6);
	for(auto x:a)	cout<<x<<endl;
	return 0;
}