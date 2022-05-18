#include <iostream>
using namespace std;
//先写到数组里再输出
//n的底是1<<n+1，高是1<<n
int n;
char a[5000][5000];
void plot(int x, int y, int t) { //大小为t，左下角坐标(x,y)
	if (t == 1) {
		a[x - 1][y + 1] = '/', a[x - 1][y + 2] = '\\';
		a[x][y] = '/', a[x][y + 1] = '_', a[x][y + 2] = '_', a[x][y + 3] = '\\';
		return;
	}
	int btm = 1 << (t + 1), h = 1 << t;
	plot(x - h / 2, y + btm / 4, t - 1);
	plot(x, y, t - 1);
	plot(x, y + btm / 2, t - 1);
}
void Print() {
	for (int i = 1; i <= (1 << n); i++) {
		for (int j = 0; j <= (1 << (n + 1)); j++)
			cout << a[i][j];
		cout << endl;
	}
}
void ini() {
	int tmp = 1 << 10 + 1;//要比最大的10大一点
	for (int i = 0; i < tmp; i++)
		for (int j = 0; j < 2 * tmp; j++) {
			a[i][j] = ' ';
		}
}
int main() {
	while (cin >> n && n != 0) {
		ini();
		plot(1 << n, 0, n);
		Print();
		cout << endl;
	}
}