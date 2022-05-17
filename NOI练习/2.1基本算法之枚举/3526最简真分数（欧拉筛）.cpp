#include <iostream>
#include <vector>
#include <set>
using namespace std;
//--------------------------------------------------------------------------------------------//
//欧拉筛（这个题没用）
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
//--------------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------------//
//最大公因数
inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
//--------------------------------------------------------------------------------------------//

int main() {
	int n, tmp, cnt = 0;
	set<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		//最简真分数不要求分子分母都是质数
		//if (!isprime[tmp])
		//	continue;
		a.insert(tmp);
	}
	for (auto i : a)
		for (auto j : a) {
			if (i >= j)
				continue;
			if (gcd(i, j) == 1)
				cnt++;
		}
	cout << cnt << endl;
}