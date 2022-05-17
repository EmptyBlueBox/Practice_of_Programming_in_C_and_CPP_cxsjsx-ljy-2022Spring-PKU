#include <iostream>
using namespace std;
//《奥数典型题举一反三（小学六年级）》 (ISBN 978-7-5445-2883-2) 第四章 第二讲 例1
int main() {
	int a, b, c, cnt = 0;
	cin >> a >> b >> c;
	for (int x = 0; x <= c / a; x++)
		for (int y = 0; y <= c / b; y++)
			if (a * x + b * y == c)
				cnt++;
	cout << cnt << endl;
}