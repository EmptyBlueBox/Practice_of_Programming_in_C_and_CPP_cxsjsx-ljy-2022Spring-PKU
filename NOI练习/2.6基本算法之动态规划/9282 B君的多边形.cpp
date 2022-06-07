#include <iostream>
using namespace std;

//这个题的通项公式是f[n] * (n + 1) = f[n - 1] * (6n - 3) - f[n - 2] * (n - 2)
//由于取模对除法不适用，因此要先求(n - 1)的逆元
//逆元线性筛：inv[i] = (mod - mod / i) * inv[mod % i] % mod（mod为质数）
long long n, inv[1000001] = { 1, 1 }, f[1000001] = { 1, 1 }, mod = 1000000007;
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n; i++)
		f[i] = ((6 * i - 3) * f[i - 1] % mod - (i - 2) * f[i - 2] % mod + mod) % mod * inv[i + 1] % mod;
	cout << f[n - 2] << endl;
}