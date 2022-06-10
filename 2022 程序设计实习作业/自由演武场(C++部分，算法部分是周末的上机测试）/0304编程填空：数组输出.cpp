#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
//根本不用Print，直接重载accumulate
//template <class T>
//class Print {
//	public:
//		int n,cnt=0;
//		T ans;
//		Print(int _n):n(_n) {}
//		void operator()(T a) {
//			ans+=a;
//			cnt++;
//			if(cnt==n)
//				cout<<ans<<endl;
//		}
//};
template <class T>
class Print {
	public:
		int n;
		Print(int _n):n(_n) {}
};
template<class T>
void accumulate(T* p1,T* p2,Print<T>(n)) {
	while(p1!=p2) {
		cout<<*p1;
		p1++;
	}
	cout<<endl;
}
// 在此处补充你的代码
int main() {
	string s[20];
	int num[20];
	int m,n;

	while(cin >> m >> n) {
		for(int i=0; i<m; i++) {
			cin >> s[i];
		}
		accumulate(s, s+m, Print<string>(m));
		for(int i=0; i<n; i++) {
			cin >> num[i];
		}
		accumulate(num, num+n, Print<int>(n));
	}
}