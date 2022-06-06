#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

enum BLOCK { EMPTY = -3, WALL, SIFU, SNAKE };
struct node {
	int x, y, key, killed, t;//杀死的蛇用位运算存储
	node(int _x, int _y, int _key, int _killed, int _t) :x(_x), y(_y), key(_key), killed(_killed), t(_t) {}
	bool operator<(node a)const {
		return (key == a.key ? t > a.t : key < a.key);
	}
};
bool vis[101][101][10][1 << 5] = { {false} };
int main() {
	int n, k;
	while (cin >> n >> k && n) {
		memset(vis, 0, sizeof(vis));
		int map[101][101] = { {0} }, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 }, tmp_snakeID = 0, ans = 0x3f3f3f3f;
		unordered_map<int, int> coordinate_to_snakeID;//对蛇标号，方便看这个蛇死没死
		priority_queue<node> q;
		char tmp;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cin >> tmp;
				if (tmp == '.') map[i][j] = EMPTY;//空格
				else if (tmp == '#') map[i][j] = WALL;//墙
				else if (tmp == 'T') map[i][j] = SIFU;//师傅
				else if (tmp == 'S')//蛇，给其一个编号
					map[i][j] = SNAKE, coordinate_to_snakeID[i * 100 + j] = tmp_snakeID++;
				else if (tmp == 'K')//孙悟空，初始化优先队列
					map[i][j] = EMPTY, q.push({ i,j,0,0,0 }), vis[i][j][0][0] = true;
				else map[i][j] = tmp - '0';//钥匙
			}
		while (!q.empty()) {
			node now = q.top();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i], keyy = now.key, killedd = now.killed, tt = now.t + 1;
				if (map[xx][yy] == WALL || vis[xx][yy][keyy][killedd] || xx < 1 || xx > n || yy < 1 || yy > n)//先排除不合法的状态
					continue;
				else if (map[xx][yy] == SIFU && keyy == k)//找到师傅，这个题比较复杂不能直接退出循环！！！
					ans = min(ans, tt);
				else if (map[xx][yy] == SNAKE && (!(killedd & (1 << coordinate_to_snakeID[xx * 100 + yy])))) //找到没杀死的蛇
					tt++, killedd |= (1 << coordinate_to_snakeID[xx * 100 + yy]);
				else if (map[xx][yy] == keyy + 1) //找到下一个钥匙
					keyy++;
				vis[xx][yy][keyy][killedd] = true;//别忘了维护vis数组！！！
				q.push({ xx,yy,keyy,killedd,tt });
			}
		}
		cout << (ans == 0x3f3f3f3f ? "impossible" : to_string(ans)) << endl;
	}
}