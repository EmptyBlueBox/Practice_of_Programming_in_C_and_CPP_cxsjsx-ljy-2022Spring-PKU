#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

//一定可以从(1, 1)开始，按字典序深搜得到答案
//DFS的参数都可以变成全局变量，要恰当决定哪些变成全局变量
//比如这个题，一些题解的第三个参数是与(1, 1)的距离，我们可以把他与全局变量的防止重复搜索的vis数组合并，简化DFS的参数
int m, n, dx[8] = { -1,1,-2,2,-2,2,-1,1 }, dy[8] = { -2,-2,-1,-1,1,1,2,2 }, dis[28][28] = { {0} };//dis是vis与距(1, 1)距离的数组合并得到的
vector<string> ans;
bool all_end = false;
void dfs(int x, int y) {
	if (dis[x][y] == m * n - 1) {
		for (auto i : ans)
			cout << i;
		cout << endl << endl;
		all_end = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || xx>m || yy<1 || yy>n || (dis[xx][yy] != 0x3f3f3f3f))
			continue;
		dis[xx][yy] = dis[x][y] + 1;
		ans.push_back(char(yy - 1 + 'A') + to_string(xx));
		dfs(xx, yy);
		if (all_end)
			return;
		ans.pop_back();
		dis[xx][yy] = 0x3f3f3f3f;
	}
}
int main() {
	int N;
	cin >> N;
	for (int T = 1; T <= N; T++) {
		printf("Scenario #%d:\n", T);
		memset(dis, 0x3f, sizeof(dis));
		ans.clear();
		all_end = false;
		cin >> m >> n;
		ans.push_back("A1");
		dis[1][1] = 0;
		dfs(1, 1);
		if (!all_end)
			cout << "impossible\n\n";
	}

}