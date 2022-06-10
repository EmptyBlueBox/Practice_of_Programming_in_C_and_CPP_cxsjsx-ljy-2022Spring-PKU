#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
	// 在此处补充你的代码
public:
	int all = 0, cnt = 0;
	int* ans;
	CMean(int& n) {
		ans = &n;
	}
	void operator()(int n) {
		cnt++;
		all += n;
		*ans = all / cnt;
	}
	// 在此处补充你的代码
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while (t--) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	return 0;
}