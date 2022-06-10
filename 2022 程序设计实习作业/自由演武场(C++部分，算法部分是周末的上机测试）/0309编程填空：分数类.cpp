#include <iostream>
using namespace std;
int gcd(int x, int y) {
	return x % y == 0 ? y : gcd(y, x % y);
}
class Fraction {
		int num, den;
	public:
		// 在此处补充你的代码
		Fraction(int _num, int _den = 1) :num(_num), den(_den) {}
		void operator*=(Fraction a) {
			num *= a.num;
			den *= a.den;
			int g = gcd(num, den);
			num /= g;
			den /= g;
		}
		void operator/=(Fraction a) {
			*this *= Fraction(a.den, a.num);
		}
		Fraction operator*(Fraction a) {
			a *= *this;
			return a;
		}
		Fraction operator/(Fraction a) {
			a /= *this;
			int tmp = a.num;
			a.num = a.den;
			a.den = tmp;
			return a;
		}
		operator double() {
			return num *1.0 / den;
		}
		friend ostream& operator<<(ostream& os, Fraction a) {
			os << a.num << '/' << a.den;
			return os;
		}
		// 在此处补充你的代码
};

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	Fraction f(a, b), g(c);
	f *= g;
	cout << f << endl;
	f /= g;
	cout << f << endl;
	f = f * f;
	cout << f << endl;
	f = f / g;
	cout << f << endl;
	cout << (float)f << endl;
	return 0;
}