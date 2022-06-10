#include <set>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
struct cmp {
	bool operator()(pii p1, pii p2) const {
		if (p1.first != p2.first)
			return p1.first > p2.first;
		else
			return p1.second < p2.second;
	}
};
int main() {
	int N;
	cin >> N;
	while (N--) {
		vector<set<pair<int, int>, cmp> > a(4);
		int n, cnt = 0;
		cin >> n;
		while (n--) {
			string cmd;
			cin >> cmd;
			if (cmd == "IN") {
				int A, B;
				cin >> A >> B;
				cnt++;
				a[A].insert(make_pair(B, cnt));
			} else {
				int A;
				cin >> A;
				if (a[A].empty())
					cout << "EMPTY\n";
				else {
					cout << a[A].begin()->second << endl;
					a[A].erase(a[A].begin());
				}
			}
		}
	}
}