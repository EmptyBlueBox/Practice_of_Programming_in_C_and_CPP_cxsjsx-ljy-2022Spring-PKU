#include <iostream>
#include <unordered_map>
using namespace std;

int d, n, tmp[3], rubbish[1030][1030] = { {0} }, maxsum = 0, cnt = 0;
inline int presum(int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	else if (i > 1024 && j <= 1024)
		return rubbish[1024][j];
	else if (i <= 1024 && j > 1024)
		return rubbish[i][1024];
	else if (i > 1024 && j > 1024)
		return rubbish[1024][1024];
	else
		return rubbish[i][j];
}
int main() {
	//unordered_map<int, unordered_map<int, int> > rubbish;//相当于二维数组，然而不如直接用二维数组
	cin >> d >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> tmp[j];
		rubbish[tmp[0]][tmp[1]] = tmp[2];
	}
	//下计算前缀和
	for (int i = 0; i <= 1024; i++)
		for (int j = 0; j <= 1024; j++) {
			if (!i && j)//第一行且不是第一个
				rubbish[0][j] += rubbish[0][j - 1];
			else if (i && !j)//第二行以后且是第一个
				rubbish[i][0] += rubbish[i - 1][0];
			if (i && j)
				rubbish[i][j] += rubbish[i - 1][j] + rubbish[i][j - 1] - rubbish[i - 1][j - 1];
		}
	for (int i = 0; i <= 1024; i++) {//要输出放置点个数不能忽略边界点！！！
		for (int j = 0; j <= 1024; j++) {
			int amount = presum(i + d, j + d) - presum(i - d - 1, j + d) - presum(i + d, j - d - 1) + presum(i - d - 1, j - d - 1);
			if (amount > maxsum) {
				maxsum = amount;
				cnt = 1;
			} else if (amount == maxsum)
				cnt++;
		}
	}
	cout << cnt << ' ' << maxsum << endl;
}