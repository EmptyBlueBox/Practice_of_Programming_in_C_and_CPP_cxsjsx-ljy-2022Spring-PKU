#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue {
		// 在此处补充你的代码
	public:
		int k;
		multiset<int, greater<int> > a;
		MyQueue(int _k) :k(_k) {}
		friend istream& operator>>(istream& is, MyQueue& mq) {
			int tmp;
			is >> tmp;
			if (!(tmp & 1))
				mq.a.insert(tmp);
			return is;
		}
		friend ostream& operator<<(ostream& os, MyQueue mq) {
			set<int>::iterator itr;
			int cnt = 0;
			for (itr = mq.a.begin(); itr != mq.a.end(); itr++) {
				os << *itr << ' ';
				cnt++;
				if (cnt == mq.k)
					break;
			}
			return os;
		}
		// 在此处补充你的代码
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout << q;
		cout << endl;
	}
	return 0;
}