#include <iostream>
using namespace std;
int cnt = 0;
void dfs(int n, int minfac) {
	for (int i = minfac; i <= n; i++) {
		if (n % i == 0)
			dfs(n / i, i);
		if (i == n)
			cnt++;
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		cnt = 0;
		dfs(n, 2);
		cout << cnt << endl;
	}
}