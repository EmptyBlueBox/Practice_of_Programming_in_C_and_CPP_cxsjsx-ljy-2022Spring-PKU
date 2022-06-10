#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class C1 {
// 在此处补充你的代码
	public:
		vector<int>a;
		C1(int len,vector<int> _a):a(_a) {}
		typedef vector<int>::iterator vii;
		vii operator*() {
			return a.begin();
		}
		int& operator[](int n) {
			return a[a.size()-n-1];
		}
// 在此处补充你的代码
};

int main() {
	vector<int> v;
	int p;
	int size;
	int k;
	cin >> k;
	while(k--) {
		cin >> size;
		v.clear();
		for(int i = 0; i < size; ++i) {
			cin >> p;
			v.push_back(p);
		}
		C1 o1 = C1(size,v);
		ostream_iterator<int> it(cout,"---");
		copy(*o1, (*o1)+size, it);//*o1返回int指针
		cout<<endl;
		for(int i = 0; i < size; ++i) {
			o1[i]*=2;
			cout<<o1[i]<<"***";
		}
		cout<<endl;
	}

}