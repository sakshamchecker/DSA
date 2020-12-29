#include <iostream>
#include <vector>
#include <set>
using namespace std;
void getCieling(int a[],int n){
	set<int> s;
	cout<<-1<<' ';
	s.insert(a[0]);
	for(int i=1;i<n;i++){
		auto it = s.lower_bound(a[i]); 
        if (it == s.end()) // If no greater found 
            cout << "-1"
                 << " "; 
        else
            cout << *it << " "; 
  
        // Then insert 
        s.insert(a[i]); 
	}
}
int main(int argc, char const *argv[])
{
	int a[]={10,20,30};
	getCieling(a,3);
	return 0;
}