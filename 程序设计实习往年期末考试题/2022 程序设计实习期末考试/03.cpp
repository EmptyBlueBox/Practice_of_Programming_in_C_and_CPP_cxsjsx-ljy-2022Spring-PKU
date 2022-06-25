#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string a, b;
		bool dp[55][55] = { {0} };
		cin >> a >> b;
		int la = a.length(), lb = b.length();
		a.insert(0, "0");
		b.insert(0, "0");
		dp[0][0] = true;
		if (b[1] == '*')
			for (int i = 0; i <= la; i++)
				dp[i][1] = true;
		for (int i = 1; i <= la; i++)
			for (int j = 1; j <= lb; j++)
				if (b[j] == '?')
					dp[i][j] = dp[i - 1][j - 1];
				else if (b[j] == '*')
					dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
				else if (a[i] == b[j])
					dp[i][j] = dp[i - 1][j - 1];
		cout << (dp[la][lb] ? "yes\n" : "no\n");
	}
}