#include <iostream>
#define int long long
using namespace std;

signed main() {
	string a, b;
	cin >> a >> b;
	int lena = a.length(), lenb = b.length();
	a.insert(0, "0"), b.insert(0, "0");
	bool dp[21][21] = { {false} };
	dp[0][0] = true;
	if (a[1] == '*')
		dp[1][0] = true;//注意初始化：a只有*，b什么都没有是可以匹配的，而a只有？；b什么都没有是不可以匹配的
	for (int i = 1; i <= lena; i++)
		for (int j = 1; j <= lenb; j++)
			if (a[i] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (a[i] == '*')
				dp[i][j] = dp[i - 1][j] | dp[i][j - 1];//不用来匹配或用来匹配
			else if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1];
	if (dp[lena][lenb])
		cout << "matched" << endl;
	else
		cout << "not matched" << endl;
}