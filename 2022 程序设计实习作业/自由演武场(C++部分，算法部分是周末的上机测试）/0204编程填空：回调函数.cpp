#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;
class MyFunc {
// 在此处补充你的代码
	public:
		int power;
		MyFunc(int _power):power(_power) {}
		int operator()(int m) {
			int tmp=1;
			for(int i=1; i<=power; i++)
				tmp*=m;
			return tmp;
		}
// 在此处补充你的代码
};
int main() {
	int n;
	cin >> n;
	while(n--) {
		vector<MyFunc> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(MyFunc(i+1));
		int ans = 1;
		for (int i = 0; i < 5; ++i) {
			int m;
			cin >> m;
			ans += v[i](m);
		}
		cout << ans <<endl;
	}
}