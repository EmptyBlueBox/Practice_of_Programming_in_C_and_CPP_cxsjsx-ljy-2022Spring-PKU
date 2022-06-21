#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 80;
//高精度加法，无负数
string Big_Integer_Add(string a, string b) { //正常无多余0的输入
	string ans;
	int na[N] = { 0 }, nb[N] = { 0 }, la = a.length(), lb = b.length(), lm = max(la, lb);
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());//把大整数的个位放在前面
	for (int i = 0; i < la; i++) na[i] = a[i] - '0';//将string变成数组
	for (int i = 0; i < lb; i++) nb[i] = b[i] - '0';
	for (int i = 0; i < lm; i++) na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;//加法并处理进位
	if (na[lm]) lm++;//如果最高位也进位了就将总长度加一
	for (int i = 0; i < lm; i++) ans += na[i] + '0';//将数组变成string
	reverse(ans.begin(), ans.end());//把大整数的个位放到后面
	return ans;
}
vector<string> dp(251, "0");
int main() {
	int n;
	dp[0] = "1", dp[1] = "1", dp[2] = "3";//别忘了dp[0]="1"
	for (int i = 3; i <= 250; i++) {
		dp[i] = Big_Integer_Add(dp[i], dp[i - 1]);
		dp[i] = Big_Integer_Add(dp[i], dp[i - 2]);
		dp[i] = Big_Integer_Add(dp[i], dp[i - 2]);//不是加二，是乘
	}
	while (cin >> n)
		cout << dp[n] << endl;
}