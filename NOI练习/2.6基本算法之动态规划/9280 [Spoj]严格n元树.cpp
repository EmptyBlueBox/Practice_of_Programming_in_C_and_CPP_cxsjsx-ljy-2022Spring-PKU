#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//进行一个板子的粘
const int N = 210;
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
string Big_Integer_Sub(string a, string b) { //正常无多余0的输入
	bool is_Negative = false;
	if (a == b) return "0";//a==b特判
	else if (a.length() < b.length() || (a.length() == b.length() && a < b)) swap(a, b), is_Negative = true;//a<b就交换并标记答案为负数

	string ans;
	int na[N] = { 0 }, nb[N] = { 0 }, la = a.length(), lb = b.length(), lm = max(la, lb);
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());//把大整数的个位放在前面
	for (int i = 0; i < la; i++) na[i] = a[i] - '0';//将string变成数组
	for (int i = 0; i < lb; i++) nb[i] = b[i] - '0';
	for (int i = 0; i < lm; i++) {
		na[i] -= nb[i];//减法
		if (na[i] < 0)//借位
			na[i] += 10, na[i + 1]--;
	}
	while (!na[lm - 1]) lm--;//只要最高位是0就将总长度减一
	for (int i = 0; i < lm; i++) ans += na[i] + '0';//将数组变成string
	if (is_Negative) ans += '-';//负数加一个负号
	reverse(ans.begin(), ans.end());//把大整数的个位放到后面
	return ans;
}
string Big_Integer_Mul(string a, string b) { //高精度a乘高精度b，复杂度o(n^2)
	string s;
	int na[N] = { 0 }, nb[N] = { 0 }, nc[N] = { 0 }, la = a.size(), lb = b.size();//na存储被乘数，nb存储乘数，nc存储积,数组从下标1开始
	for (int i = la - 1; i >= 0; i--) na[la - i] = a[i] - '0';//将string变成数组
	for (int i = lb - 1; i >= 0; i--) nb[lb - i] = b[i] - '0';
	for (int i = 1; i <= la; i++)
		for (int j = 1; j <= lb; j++)
			nc[i + j - 1] += na[i] * nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
	for (int i = 1; i <= la + lb; i++)
		nc[i + 1] += nc[i] / 10, nc[i] %= 10;//统一处理进位
	if (nc[la + lb]) s += nc[la + lb] + '0';//判断第i+j位上的数字是不是0
	for (int i = la + lb - 1; i >= 1; i--)
		s += nc[i] + '0';//将整形数组转成字符串
	return s;
}
string Big_Integer_Power(string base, int exp) {
	string ans = base;
	while (--exp)
		ans = Big_Integer_Mul(ans, base);
	return ans;
}

int main() {
	int k, d;
	string dp[17];
	cin >> k >> d;
	dp[0] = "1";
	for (int i = 1; i <= d; i++)
		dp[i] = Big_Integer_Add(Big_Integer_Power(dp[i - 1], k), "1");
	cout << Big_Integer_Sub(dp[d], dp[d - 1]) << endl;
}