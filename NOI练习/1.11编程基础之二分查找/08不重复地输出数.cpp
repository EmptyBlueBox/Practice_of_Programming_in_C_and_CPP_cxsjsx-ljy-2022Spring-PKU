#include <iostream>
#include <set>
using namespace std;
int main() {
	int n,tmp;
	set<int> a;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>tmp;
		a.insert(tmp);
	}
	n=a.size();
	set<int>::iterator itr=a.begin();
	for(int i=0; i<n; i++) {
		cout<<*itr<<' ';
		itr++;
	}
}