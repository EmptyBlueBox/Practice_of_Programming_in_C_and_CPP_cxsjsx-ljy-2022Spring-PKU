#include <iostream>
using namespace std;
//《奥数典型题举一反三（小学六年级）》 (ISBN 978-7-5445-2883-2) 第一章 第一讲 例1
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 2;; i++) {
		if (a % i == b % i && b % i == c % i) {
			cout << i << endl;
			return 0;
		}
	}
}