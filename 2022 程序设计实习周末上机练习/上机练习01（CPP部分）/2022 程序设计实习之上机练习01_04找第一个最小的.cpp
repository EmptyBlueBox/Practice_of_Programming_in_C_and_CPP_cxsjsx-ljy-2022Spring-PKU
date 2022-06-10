#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 在此处补充你的代码
template<class Ts,class T,class Pred>
Ts FindFirstLess(Ts p1, Ts p2, T m, Pred f) {
	for (Ts i = p1; i < p2; i++)
		if (f(*i, m))
			return i;
	return p2;
}
// 在此处补充你的代码
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n ;
		string type;
		cin >> n >> type;
		vector<int> vi;
		vector<string> vs;
		if( type == "N") {
			int a,m;
			for(int i = 0; i < n  - 1; ++i) {

				cin >> a;
				vi.push_back(a);
			}
			cin >> m;
			vector<int>::iterator p = FindFirstLess(vi.begin(),vi.end(),m,less<int>());
			if( p!= vi.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl;

		} else {
			string a,m;
			for(int i = 0; i < n - 1; ++i) {
				cin >> a;
				vs.push_back(a);
			}
			cin >> m;
			vector<string>::iterator p = FindFirstLess(vs.begin(),vs.end(),m,less<string>());
			if( p!= vs.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl;

		}
	}
	return 0;
}