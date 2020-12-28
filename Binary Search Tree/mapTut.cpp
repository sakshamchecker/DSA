#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<int, int> map;
	map.insert({10,100});
	map[2]=40; //insert //creates new if not present
	map.at(2)=20; //Only for existing key
	for(auto &x:map){	//cout<<map.first()<<' '<<map.second()<<'\n';
		cout<<x.first<<' '<<x.second++<<'\n';
	}
	for(auto &x:map){	//cout<<map.first()<<' '<<map.second()<<'\n';
		cout<<x.first<<' '<<x.second<<'\n';
	}
	for(auto it=map.begin();it!=map.end();it++)
		cout<<(*it).first<<' '<<(*it).second<<'\n';
	if(map.find(2)==map.end())	cout<<"Not Found\n";
	else	cout<<(*map.find(2)).second;
	for(auto it=map.find(2);it!=map.end();it++)	cout<<(*it).first<<' ';
	return 0;
}