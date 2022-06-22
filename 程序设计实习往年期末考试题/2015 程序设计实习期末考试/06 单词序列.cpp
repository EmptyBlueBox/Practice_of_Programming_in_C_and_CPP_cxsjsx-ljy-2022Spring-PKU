#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool convert(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] != b[i])
			cnt++;
	return cnt == 1;
}
int n, vis[33] = { false }, ans = 0x3f3f3f3f;
vector<int> tp[33];
void f(int x,int step) {
	if (step >= ans)
		return;
	if (x == n + 1) {
		ans = min(ans, step);
		return;
	}
	for (int i = 0; i < tp[x].size(); i++)
		if (!vis[tp[x][i]])
			vis[tp[x][i]] = true, f(tp[x][i], step + 1), vis[tp[x][i]] = false;
}
int main() {
	vector<string> lib(2);
	cin >> lib[0] >> lib[1];
	string tmp;
	while (cin >> tmp)
		lib.insert(lib.begin() + 1, tmp);
	n = lib.size() - 2;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			if (i != j && convert(lib[i], lib[j]))
				tp[i].push_back(j);
	vis[0] = true;
	f(0, 1);
	cout << (ans == 0x3f3f3f3f ? 0 : ans) << endl;
}