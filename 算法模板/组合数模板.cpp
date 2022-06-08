#include <iostream>
using namespace std;

long long C(long long n, long long m) {//组合数公式的变形，支持到C(61, 31)
	long long ans = 1;
	for (long long i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i;	//注意：一定要先乘再除！！！
	}
	return ans;
}
int main() {
	long long n, m;
	cin >> n >> m;
	cout << C(n, m) << endl;
}