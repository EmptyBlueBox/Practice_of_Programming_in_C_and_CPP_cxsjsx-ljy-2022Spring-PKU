#include<iostream>
using namespace std;

class Midterm {
	private:
		int val;
	public:
		// 在此处补充你的代码
		operator int() {
			return val;
		}
		Midterm() {
			val = 0;
		}
		Midterm(int n) :val(n) {}
		int operator++(int) {//重载a++要写（int）
			val++;
			return (val);
		}
		Midterm& operator-=(int n) {
			val -= n;
			return *this;
		}
		// 在此处补充你的代码
};

int Min(int a,int b) {
	if(a < b)
		return a;
	else
		return b;
}
int main() {
	Midterm a;
	cout << a << endl;
	cout << a + 2021 << endl;
	Midterm b(1000);
	cout << b ++ << endl;
	((b-=10)-=20)-=30;
	cout << b ++ << endl;
	cout << Min(255,b) <<endl;
	return 0;
}