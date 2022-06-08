#include <iostream>
using namespace std;

long long C(long long n, long long m) {//组合数公式的变形，支持到C(62, 31)
	long long ans = 1;
	for (long long i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i;	//注意：一定要先乘再除！！！
	}
	return ans;
}
int main() {
	//一个盒子可以放多个同颜色的球，不止一个
	//只放红和只放蓝相乘
	long long n, a, b;
	cin >> n >> a >> b;
	cout << C(n + a, a) * C(n + b, b) << endl;
}