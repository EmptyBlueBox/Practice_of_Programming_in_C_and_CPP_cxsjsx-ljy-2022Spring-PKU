#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
// 在此处补充你的代码
template<class T>
class MySet {
	public:
		typedef typename set<T>::iterator sti;
		set<T, greater<T> > a;//不知道哪里有问题可以注释一段代码试试，这里需要反向排序，因为A只重载了大于号，没有重载小于号
		void insert(T n) {
			a.insert(n);
		}
		sti begin() {
			return a.begin();
		}
		sti end() {
			return a.end();
		}
		sti find(T x) {
			return a.find(x);
		}
		void erase(sti itr) {
			a.erase(itr);
		}
		template<class T1>
		void erase(T1* p1, T1* p2) {
			for (T1* i = p1; i != p2; i++)
				a.erase(*i);
		}
};
// 在此处补充你的代码
struct A {
	int n;
	A(int i) :n(i) { }
	operator int() {
		return n;
	}
	bool operator >(const A& a) const {
		return n > a.n;
	}
};
template <class IT>
void print(IT s, IT e) {
	for (; s != e; ++s)
		cout << *s << ",";
	cout << endl;
}
int main() {
	MySet<int> mst;
	for (int i = 0; i < 10; ++i)
		mst.insert(i);
	print(mst.begin(), mst.end());
	int a[] = { 1,2,3,4 };
	mst.erase(a, a + 3);
	print(mst.begin(), mst.end());

	A b[] = { {7},{8} };
	mst.erase(b, b + 2);
	print(mst.begin(), mst.end());
	mst.erase(mst.find(6));
	print(mst.begin(), mst.end());
	for (int i = 0; i < 1000000; ++i)
		mst.insert(i);
	for (int i = 0; i < 1000000 - 10; ++i)
		mst.erase(mst.find(i));
	int n;
	cin >> n;
	MySet<A> msta;

	for (int i = 0; i < n; ++i) {
		string cmd;
		int n;
		cin >> cmd >> n;
		if (cmd == "ADD")
			msta.insert(A(n));
		else {
			if (msta.find(A(n)) != msta.end())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}