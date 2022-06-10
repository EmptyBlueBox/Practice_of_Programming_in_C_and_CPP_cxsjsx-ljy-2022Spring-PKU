#include <iostream>
#include <string>
#include <set>
using namespace std;

class Counter {
		int cnt;
	public:
		Counter() :cnt(0) {}
		virtual void push(void*) = 0;
		virtual string name() = 0;
		void inc() {
			++cnt;
		}
		int number() {
			return cnt;
		}
};

template<class T>
class TCounter : public Counter {
		// 在此处补充你的代码
	public:
		string n;
		set<T>a;
		TCounter(string _a) :n(_a) {};
		virtual string name() {
			return n;
		}
		virtual void push(void* p) {
			T tmp = *(T*)p;//void*要对指针强制类型转换而不是先*再转换！！！
			if (a.find(tmp) == a.end())
				inc();
			a.insert(tmp);
		}
		// 在此处补充你的代码
};

Counter* build_counter(string name) {
	if (name == "int") return new TCounter<int>("int");
	else return new TCounter<string>("string");
}



int main() {
	int n, m;
	cin >> n >> m;
	Counter* a = build_counter("int"), * b = build_counter("string");
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a->push(&x);
	}
	for (int i = 0; i < m; ++i) {
		string x;
		cin >> x;
		b->push(&x);
	}
	cout << a->name() << ": " << a->number() << endl;
	cout << b->name() << ": " << b->number();
	return 0;
}