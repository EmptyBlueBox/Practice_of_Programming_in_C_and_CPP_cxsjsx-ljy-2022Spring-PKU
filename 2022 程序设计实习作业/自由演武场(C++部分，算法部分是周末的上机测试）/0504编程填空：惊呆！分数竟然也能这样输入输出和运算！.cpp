#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
	return (!b) ? a : gcd(b, a % b);
}
class Fraction {
		int p, q;
	public:
// 在此处补充你的代码
		Fraction(int _p = 1,int _q = 1):p(_p),q(_q) {
			int g=gcd(p,q);
			p/=g,q/=g;
		}
		friend istream& operator>>(istream& is,Fraction& f) {
			is>>f.p>>f.q;
			int g=gcd(f.p,f.q);
			f.p/=g,f.q/=g;
			return is;
		}
		friend ostream& operator<<(ostream& os,Fraction f) {
			if(f.q==1) {
				os<<f.p;
				return os;
			}
			os<<f.p<<"/"<<f.q;
			return os;
		}
		Fraction operator*(Fraction a) {
			a.p*=p,a.q*=q;
			int g=gcd(a.p,a.q);
			a.p/=g,a.q/=g;
			return a;
		}
// 在此处补充你的代码
};

int main() {
	int testcases;
	cin >> testcases;
	while (testcases --) {
		Fraction a, b, two(2);
		cin >> a >> b;
		cout << a << " * " << b << " = " << a * b << endl;
		cout << "2 * " << a << " = " << two * a << endl;
		cout << b << " * 3 = " << b * 3 << endl;
	}
	return 0;
}