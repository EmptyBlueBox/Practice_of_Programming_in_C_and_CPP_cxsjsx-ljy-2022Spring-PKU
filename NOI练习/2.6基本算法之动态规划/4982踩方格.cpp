#include <iostream>
using namespace std;

//把第i步拆成第i步是向左向右还是向上达到目的地，细化再递归
int main() {
	int n, side[21] = { 0 }, up[21] = { 0 };
	side[1] = 1, up[1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
		up[i] = up[i - 1] + 2 * side[i - 1], side[i] = side[i - 1] + up[i - 1];
	cout << up[n] + 2 * side[n] << endl;
}