#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, info[1001], dp1[1001], dp2[1001], ans = 0xc0c0c0c0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> info[i], dp1[i] = dp2[i] = 1;
	dp1[1] = dp2[n] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (info[j] >= info[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);
	for (int i = n - 1; i >= 1; i--)
		for (int j = n; j > i; j--)
			if (info[i] >= info[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
	ans = max(dp1[n], dp2[1]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = max(ans, dp1[i] + dp2[j]);
	cout << ans << endl;
}