#include <iostream>
#include <vector>
using namespace std;

vector<int> Prime;
vector<bool> Is_Prime;
//算到N是不是质数
void Euler_Prime(int N) {
	Prime.resize(N + 1);//Prime[0]代表着[2,N]有几个质数
	Is_Prime.resize(N + 1);//初始都设成true,刨除合数
	fill(Prime.begin(), Prime.end(), 0);//resize填充的是增大的那部分
	fill(Is_Prime.begin(), Is_Prime.end(), true);
	for (int i = 2; i <= N; i++) {
		if (Is_Prime[i])
			Prime[++Prime[0]] = i;
		for (int j = 1; j <= Prime[0] && i * Prime[j] <= N; j++) {//把已知素数的倍数标记为合数
			Is_Prime[i * Prime[j]] = false;//i在消去合数中的作用是当做倍数的
			if (i % Prime[j] == 0)//Prime[j]不是i*Prime[j]的最小素因子了（重要）
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n) {
		Euler_Prime(n);
		if (Is_Prime[n])
			cout << n << " is prime.\n";
		else
			cout << n << " is not prime.\n";
		cout << "There are " << Prime[0] << " primes from 2 to " << n << ", and they are:\n";
		for (int i = 1; i <= Prime[0]; i++)
			cout << Prime[i] << endl;
		cout << endl;
	}
}