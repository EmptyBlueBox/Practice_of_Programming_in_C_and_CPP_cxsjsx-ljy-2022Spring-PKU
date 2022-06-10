#include <iostream>
using namespace std;

int a[7][7] = { {0} }, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool vis[7][7] = { {false} };
pair<int, int> path[9];
//要找路径dfs不能返回void，否则不知道这个点是不是在路径上
bool dfs(pair<int, int> x, int depth) { //返回经过这个点是否能到终点，在dfs过程中记录到终点的路径
	if (x == make_pair(5, 5)) { //到达终点
		path[depth] = x;
		return true;
	}
	if (vis[x.first][x.second])//旧点
		return false;
	vis[x.first][x.second] = true;//不用回溯
	for (int i = 0; i < 4; i++) {
		int xx = x.first + dx[i], yy = x.second + dy[i];
		if (a[xx][yy] && dfs({xx, yy}, depth + 1)) {//可行域并且往这里走能到终点
			path[depth] = x;
			return true;
		}
	}
	return false;
}
int main() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			cin >> a[i][j], a[i][j] = 1 - a[i][j];//0是墙
	dfs({ 1,1 }, 0);
	for (auto i : path)
		cout << '(' << i.first - 1 << ", " << i.second - 1 << ')' << endl;//', '要用双引号！！！
}
