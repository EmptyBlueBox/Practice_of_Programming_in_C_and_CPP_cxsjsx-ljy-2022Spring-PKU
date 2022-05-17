#include <iostream>
#include <vector>
using namespace std;
//粘个欧拉筛板子
int N;//算到N是不是质数
vector<int> prime;
vector<bool> isprime;
void Euler_Prime() {
	prime.resize(N + 1, 0);
	isprime.resize(N + 1, true);//初始都设成true,刨除合数
	for (int i = 2; i <= N; i++) {
		if (isprime[i])
			prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= N; j++) {//把已知素数的倍数标记为合数
			isprime[i * prime[j]] = false;//i在消去合数中的作用是当做倍数的
			if (i % prime[j] == 0)//prime[j]不是i*prime[j]的最小素因子了（重要）
				break;
		}
	}
}
int main() {
	N = 10000;
	Euler_Prime();
	int n;
	cin >> n;
	for (int i = n / 2; i >= 2; i--) {
		if (isprime[i] && isprime[n - i]) {
			cout << i * (n - i) << endl;
			return 0;
		}
	}
}