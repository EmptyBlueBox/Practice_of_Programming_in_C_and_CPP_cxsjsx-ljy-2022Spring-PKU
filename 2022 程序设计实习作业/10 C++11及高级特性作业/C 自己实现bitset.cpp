#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset {
		char a[bitNum / 8 + 1];
		MyBitset() {
			memset(a, 0, sizeof(a));
		};
		void Set(int i, int v) {
			char& c = a[i / 8];
			int bp = i % 8;
			if (v)
				c |= (1 << bp);
			else
				c &= ~(1 << bp);
		}
		// 在此处补充你的代码
		bool ini = false;
		class eb {
			public:
				int bit;
				eb& operator=(int tmp) {
					bit = tmp;
					return *this;
				}
				operator int() {
					return bit;
				}
				friend ostream& operator<<(ostream& os, eb tmp) {
					os << tmp.bit;
					return os;
				}
		} bit[21];
		eb& operator[](int n) {
			if (!ini) {
				for (int i = 0; i < bitNum; i++) {
					bit[i] = a[i / 8] >> (i % 8) & 1;
				}
				ini = true;
			}
			return bit[n];
		}
		// 在此处补充你的代码
		void Print() {
			for (int i = 0; i < bitNum; ++i)
				cout << (*this)[i];
			cout << endl;
		}

};

int main() {
	int n;
	int i, j, k, v;
	while (cin >> n) {
		MyBitset<20> bs;
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t, 1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}