#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

//每一天所获得的最多的美元是前一天的加元乘汇率乘0.97和前一天的美元的最大值，加元同理
//动态规划，滚动变量（因为递推公式只需要上一步的结果）
//要求两位精度可以乘100，用int算，再除以100输出，不会丢失精度
int main() {
	int n;
	while (cin >> n && n) {
		int maxUS = 100000, maxCAN = 0;
		double rate;
		for (int i = 0; i < n; i++) {
			cin >> rate;
			int tmpmaxUS = maxUS;
			maxUS = max(maxUS, int(maxCAN * rate * 0.97));
			maxCAN = max(maxCAN, int(tmpmaxUS / rate * 0.97));
		}
		cout << fixed << setprecision(2) << maxUS / 100.0 << endl;
	}
}