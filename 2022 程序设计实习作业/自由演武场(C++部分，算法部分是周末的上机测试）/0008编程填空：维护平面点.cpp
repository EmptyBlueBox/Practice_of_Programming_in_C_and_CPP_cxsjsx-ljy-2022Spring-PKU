#include <set>
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
//dev和vs2019输出不一样???
typedef pair<int, int> p;
class myComp {
public:
	bool operator()(p a, p b) const {
		if (a.first == -1 || b.first == -1) {
			//cout << a.first << ' ' << a.second << "  " << b.first << ' ' << b.second << endl;
			if (a.second == b.second)
				return a.first == -1;
			return a.second > b.second;
		}
		else {
			//cout << a.first << ' ' << a.second << "  " << b.first << ' ' << b.second << endl;
			if (a.first == b.first)
				return a.second == -1;
			return a.first < b.first;
		}
	}
};
// 在此处补充你的代码
int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		}
		else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		}
		else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		}
		else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}