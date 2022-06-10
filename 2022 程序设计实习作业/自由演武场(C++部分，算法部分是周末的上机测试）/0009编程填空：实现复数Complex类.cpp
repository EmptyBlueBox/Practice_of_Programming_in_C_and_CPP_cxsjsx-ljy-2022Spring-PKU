#include <iostream>
using namespace std;
// 在此处补充你的代码
class Complex {
		int r, i;
	public:
		Complex() {};
		Complex(string a) :r(a[0] - '0'), i(a[2] - '0') {};
		Complex(int a) :r(a), i(0) {};
		Complex(int a, int b) :r(a), i(b) {};
		Complex operator+(Complex a) {
			return Complex(this->r + a.r, this->i + a.i);
		}
		Complex operator-(Complex a) {
			return Complex(this->r - a.r, this->i - a.i);
		}
		Complex operator*(Complex a) {
			return Complex(this->r * a.r - this->i * a.i, this->i * a.r + this->r * a.i);
		}
		void operator+=(Complex a) {
			this->r += a.r, this->i += a.i;
		}
		void operator-=(Complex a) {
			this->r -= a.r, this->i -= a.i;
		}
		void operator*=(Complex a) { //+=，-=，*=要考虑自己和自己
			Complex tmp(*this);
			this->r = tmp.r * a.r - tmp.i * a.i;
			this->i = tmp.i * a.r + tmp.r * a.i;
		}
		friend ostream& operator<<(ostream& os, Complex a) { //临时对象不能引用
			if (a.i == 0 && a.r == 0) {
				os << 0;
				return os;
			} else if (a.r == 0) {
				os << a.i << 'i';
				return os;
			} else if (a.i == 0) {
				os << a.r;
				return os;
			} else {
				os << a.r << '+' << a.i << 'i';
				return os;
			}
		}
};
// 在此处补充你的代码
int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}