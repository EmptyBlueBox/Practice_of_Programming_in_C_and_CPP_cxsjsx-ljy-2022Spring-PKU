#include <iostream>
#include <string>
#include <cstring>
	using namespace std;
	template <class T>
	class myclass {
		// 在此处补充你的代码
	//public:
	//	T* p = new T[100];
	//	int size;
	//	myclass(T* p0, int len0) :p(p0), size(len0) {
	//		for (int i = 0; i < size; i++)
	//			p[i] = p0[i];
	//	}
	 	public:
			T* p;
		int size;
		myclass(T* p0, int len0) :p(p0), size(len0) {
			p = new T[size];//new在构造函数里
			for (int i = 0; i < size; i++)
				p[i] = p0[i];
		}
		// 在此处补充你的代码
		~myclass() {
			delete[] p;
		}
		void Show()
		{
			for (int i = 0; i < size; i++) {
				cout << p[i] << ",";
			}
			cout << endl;
		}
	};
	int a[100];
	int main() {
		char line[100];
		while (cin >> line) {
			myclass<char> obj(line, strlen(line));;
			obj.Show();
			int n;
			cin >> n;
			for (int i = 0; i < n; ++i)
				cin >> a[i];
			myclass<int> obj2(a, n);
			obj2.Show();
		}
		return 0;
	}
