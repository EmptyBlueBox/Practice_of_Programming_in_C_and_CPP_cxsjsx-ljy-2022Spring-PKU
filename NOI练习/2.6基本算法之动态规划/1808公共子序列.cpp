#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//递推公式：（a的前i位和b的前j位的最长公共序列）
//dp[i][j]=0  when i==0||j==0
//dp[i][j]=dp[i-1][j-1]+1  when a[i]==b[j]
//dp[i][j]=max(dp[i-1][j],dp[i][j-1]) otherwise
int Max_Mutual_Substring_Length(string a, string b) {
	int dp[201][201] = { {0} }, la = a.length() - 1, lb = b.length() - 1;
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i] == b[j])//笔误，不是(a[i] == a[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[la][lb];
}
int main() {
	string a, b;
	while (cin >> a >> b) {
		a.insert(0, "0");//string只能用下标插入字符串，插入字符要用迭代器
		b.insert(0, "0");
		cout << Max_Mutual_Substring_Length(a, b) << endl;
	}
}