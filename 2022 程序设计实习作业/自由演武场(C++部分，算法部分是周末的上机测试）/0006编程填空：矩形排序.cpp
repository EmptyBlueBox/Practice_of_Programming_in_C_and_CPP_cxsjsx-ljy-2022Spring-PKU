#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码
//在对关联容器自定义比较规则的时候要在重载<之后写const，因为set或map内部用了const
class Rectangle {
	public:
		int a, b, c, s;
		Rectangle(int x, int y) :a(x), b(y), c(2 * (a + b)), s(a* b) {}
		bool operator<(const Rectangle m)const {//here
			if (s == m.s)
				return c > m.c;
			else
				return s > m.s;
		}
		friend ostream& operator<<(ostream& os, Rectangle a) {
			cout << a.s << " " << a.c;
			return os;
		}
};
class Comp {
	public:
		bool operator()(Rectangle a, Rectangle b)const { //here
			if (a.c == b.c)
				return a.s < b.s;
			else
				return a.c < b.c;
		}
};
// 在此处补充你的代码
int main() {
	multiset<Rectangle> m1;
	multiset<Rectangle, Comp> m2;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m1.insert(Rectangle(a, b));
		m2.insert(Rectangle(a, b));
	}
	for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}