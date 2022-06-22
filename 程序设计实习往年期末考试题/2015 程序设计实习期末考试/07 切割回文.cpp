#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string a;
bool isPalindrome(int l, int r) { //判断是否是回文不要用string的函数，否则TLE！！！
	for (int i = l; i <= r; i++)
		if (a[i] != a[l + r - i])
			return false;
	return true;
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		cin >> a;
		int len = a.length();
		a.insert(0, "0");
		int dp[1001];
		memset(dp, 0x3f, sizeof(dp));
		dp[1] = 0;//dp[0]不好判断，规避使用dp[0]
		for (int i = 2; i <= len; i++) {
			if (isPalindrome(1, i)) {
				dp[i] = 0;
				continue;
			} else
				for (int j = 2; j <= i; j++)//从[2,i]往后判断是不是回文，[1,i]已经特判过了，从而规避使用dp[0]！！！
					if (isPalindrome(j, i))
						dp[i] = min(dp[i], dp[j - 1] + 1);
		}
		cout << dp[len] << endl;
	}
}