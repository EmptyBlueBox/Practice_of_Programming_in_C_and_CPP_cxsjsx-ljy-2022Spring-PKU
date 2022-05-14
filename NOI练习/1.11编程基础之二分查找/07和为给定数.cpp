#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main() {
	ll n,tmp,aim;
	multiset<ll> a;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>tmp;
		a.insert(tmp);
	}
	cin>>aim;
	set<ll>::iterator itr=a.begin(),end=a.end(),find;
	for(ll i=0; i<n; i++) {
		find=a.find(aim-*itr);
		if(find!=end&&find!=itr) {//找到的不能是自己的迭代器，防止自己加自己是答案
			cout<<*itr<<' '<<aim-*itr<<endl;
			return 0;
		}
		itr++;
	}
	cout<<"No"<<endl;
}