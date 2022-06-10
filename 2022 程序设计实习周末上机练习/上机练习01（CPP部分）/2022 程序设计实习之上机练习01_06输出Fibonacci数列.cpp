#include <iostream>
#include <iterator>
using namespace std;
template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
	for(; s != e; ++s, ++x)
		*x = *s;
}
// 在此处补充你的代码
class Fib {
	public:
		int n, pre = 0, now = 1;
		Fib(int _n) :n(_n) {}
		bool operator!=(Fib tmp) {
			return n != tmp.n;
		}
		void operator++() {
			n++;
			int tmp = pre + now;
			pre = now;
			now = tmp;
		}
		int operator*() {
			return now;
		}
};
// 在此处补充你的代码
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;

		Fib f1(1), f2(n);
		ostream_iterator<int> it(cout, " ");
		Copy(f1, f2, it);
		cout << endl;
	}
	return 0;
}