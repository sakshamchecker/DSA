#include<iostream>
int sort(int a[],int n, int x)
{
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return i;
	return -1;
}
main()
{
	int a[]={1,2,3,4,5};
	std::cout<<sort(a,5,3);
	return 0;
}