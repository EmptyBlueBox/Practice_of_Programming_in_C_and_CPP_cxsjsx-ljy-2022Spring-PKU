#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl '\n'//差十倍
using namespace std;

const int N = 100;
string add(string a, string b) { //正常无多余0的输入
	string ans;
	int na[N] = { 0 }, nb[N] = { 0 }, la = a.length(), lb = b.length(), lm = max(la, lb);
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
	for (int i = 0; i < la; i++)
		na[i] = a[i] - '0';
	for (int i = 0; i < lb; i++)
		nb[i] = b[i] - '0';
	for (int i = 0; i < lm; i++)
		na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
	if (na[lm])
		lm++;
	for (int i = lm - 1; i >= 0; i--)
		ans += na[i] + '0';
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);//cin,cout解绑
	int m;
	string a, Max_String;;//前i位加j个加号的最小值
	for (int i = 0; i < 50; i++)
		Max_String += '9';
	while (cin >> m >> a) {
		string dp[52][52];//加号个数，前多少位
		int len = a.length();
		for (int i = 1; i <= len; i++)
			dp[0][i] = a.substr(0, i);
		for (int i = 1; i <= m; i++) { //i个加号
			for (int j = i + 1; j <= len; j++) { //前j位
				dp[i][j] = Max_String;
				for (int k = i; k <= j - 1; k++) { //枚举前j位的最后一个小字符串。这个小字符串之前至少有i个字符，k大于等于i！！！
					string tmp = add(dp[i - 1][k], a.substr(k, j - k));
					if (tmp.length() < dp[i][j].length() || (tmp.length() == dp[i][j].length() && tmp < dp[i][j]))
					//字典序，长度小的可能在前，要么短，要么一样长字典序小
						dp[i][j] = tmp;
				}
			}
		}
		cout << dp[m][len] << endl;
	}
}